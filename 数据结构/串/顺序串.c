//��һ���ַ�����Ĵ洢��Ԫ���洢���е��ַ�����

#include<stdio.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 40 /* �洢�ռ��ʼ������ */

typedef int Status;		//�������״̬����
typedef int ElemType;	//�������Ͷ���

typedef char String[MAXSIZE+1];	//0�ŵ�Ԫ��Ŵ��ĳ���

//����1����ֵ�����ַ�������chars�Ĵ�T;
Status StrAssign(String T, char *chars)
{
	int i;
	if (strlen(chars) > MAXSIZE)	//�ж��Ƿ������
		return ERROR;
	else
	{
		T[0] = strlen(chars);		//��Ŵ��ĳ���
		for(i=1; i<=T[0]; i++)		
			T[i] = *(chars+i-1);	//ָ��chars��ÿһ��Ԫ��
		return OK;
	}
}

//��S����, �ɴ�S���Ƶô�T;
Status StrCopy(String T, String S)
{
	int i;
	for(i=0; i<=S[0]; i++)
		T[i] = S[i];
	return OK;
}

//��S����, �����;
Status ClearString(String S)
{
	S[0] = 0;
	return OK;
}

//����S����, ����true, ���򷵻�false;
Status EmptyString(String S)
{
	if (S[0] == 0)
		return TRUE;
	else
		return FALSE;
}

//���ش�S��Ԫ�ظ���;
Status StrLength(String S)
{
	return S[0];
}

//S>T, ����ֵ>0; S=T, ����0; S<T, ����ֵ<0;
Status StrCompare(String S, String T)
{
	int i;
	for(i=1; i<=S[0]&&i<=T[0]; ++i)
		if (S[i] != T[i])		//�Ƚ�ÿ��Ԫ�ش�С
			return S[i]-T[i];
	return S[0]-T[0];			//���Ȳ�ͬʱ, ���س��Ȳ�
}

//��T������S1��S2���Ӷ��ɵ��´�;
Status Concat(String T, String S1, String S2)
{
	int i;
	if (S1[0]+S2[0] <= MAXSIZE)	//δ���ض�
	{
		for(i=1; i<=S1[0]; i++)
			T[i] = S1[i];		//��S1ȫ������T
		for(i=1; i<=S2[0]; i++)
			T[i+S1[0]] = S2[i];	//��S2ȫ������T
		T[0] = S1[0]+S2[0];
		return TRUE;
	}
	else						//S2���ض�
	{
		for(i=1; i<=S1[0]; i++)
			T[i] = S1[i];
		for(i=1; i<=MAXSIZE-S1[0]; i++)
			T[S1[0]+i] = S2[i];
		T[0] = MAXSIZE;
		return FALSE;
	}
}

//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���ִ�;
Status SubString(String Sub, String S, int pos, int len)
{
	int i;
	if (pos<1 || pos>S[0] || len<0 || len>S[0]-pos+1)
		return ERROR;
	for(i=1; i<=len; i++)
		Sub[i] = S[pos+i-1];
	Sub[0] = len;
	
	return OK;
}

//�����Ӵ�T������S�е�pos���ַ�֮���λ��;
Status Index(String S, String T, int pos)
{
	int i = pos;	//����S�е�ǰλ�õ��±�
	int j = 1;		//�Ӵ�T�е�ǰλ�õ��±�
	while(i<=S[0] && j<=T[0])	//i������S�ĳ�����j������T�ĳ���
	{
		if (S[i] == T[j])		//��������ƥ��
		{
			++i;
			++j;
		}
		else		//ָ��������¿�ʼƥ��
		{
			i = i-j+2;			//i�����ϴ�ƥ����λ����һλ
			j = 1;				//j�����Ӵ�T����λ
		}
	}
	if (j > T[0])
		return i-T[0];
	else
		return FALSE;
}

//����S�е�pos���ַ��������T��ȵ��Ӵ�, ���ص�һ��������Ӵ����ֵ�λ��;
Status Index2(String S, String T, int pos)
{
	int i, n, m;
	String Sub;
	if (pos > 0)
	{
		n = StrLength(S);	
		m = StrLength(T);
		i = pos;
		while(i <= n-m+1)
		{
			SubString(Sub, S, i, m);	//ȡ�����е�i��λ�ó�����T��ȵ��Ӵ���Sub
			if (StrCompare(Sub, T) != 0)	//�ж������Ƿ����
				i++;					//λ�ú���
			else
				return i;
		}
	}
	return FALSE;
}

//�ڴ�S�ĵ�pos���ַ�֮ǰ���봮T;
Status StrInsert(String S, int pos, String T)
{
	int i;
	if (pos<1 || pos>S[0]+1)	//����λ�ô���
		return ERROR;
	if (S[0]+T[0] <= MAXSIZE)
	{
		for(i=S[0]; i>=pos; i--)
			S[i+T[0]] = S[i];	//�൱�ڽ�pos���Ԫ�غ���T[0]�Բ��봮T
		for(i=pos; i<pos+T[0]; i++)
			S[i] = T[i-pos+1];	//�൱�ڽ�T��Ԫ�ش�pos��ʼ���β���
		S[0] = S[0] + T[0];
		return OK;
	}
	else			//���ֲ���
	{
		for(i=MAXSIZE; i<=pos; i--)
			S[i] = S[i-T[0]];	//�൱�ڽ�pos���Ԫ��Ų����β
		for(i=pos; i<pos+T[0]; i++)
			S[i] = T[i-pos+1];
		S[0] = MAXSIZE;
		return FALSE;
	}
}

//�Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�;
Status StrDelete(String S,int pos,int len)
{
	int i;
	if (pos<1 || pos>S[0]-len+1 || len<0)
		return ERROR;
	for(i=pos+len; i<=S[0]; i++)
		S[i-len] = S[i];
	S[0] -= len;
	return OK;
}

//��V�滻����S�г���������T��ȵĲ��ص����Ӵ�;
Status Replace(String S, String T, String V)
{
	int i = 1;
	if (EmptyString(T))
		return ERROR;
	do{
		i = Index(S, T, i);		//iΪ��һ��i֮���ҵ��Ӵ�T��λ��
		if (i)
		{
			StrDelete(S, i, StrLength(T));		//ɾ�����Ӵ�T
			StrInsert(S, i, V);					//ԭλ���ϲ���V
			i += StrLength(V);	//�ڲ���Ĵ�V��������Ҵ�T
		}
	}while(i);
	return OK;
}

//����ַ���T;
Status StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
	
	return OK;
}

int main(void)
{
	int n, m;
	Status i;
	char s;
	String t, s1, s2;
	
	printf("Let string s1 = 'abcd'\n");
	i = StrAssign(s1, "abcd");
	if (!i)
		printf("�����ȳ���MAXSIZE(=%d)\n", MAXSIZE);
	printf("����Ϊ%d ���շ�: %d(1:�� 0:��)\n",StrLength(s1), EmptyString(s1));
	printf("s1: ");
	StrPrint(s1);
	StrCopy(s2, s1);
	printf("����s1����s2Ϊ: ");
	StrPrint(s2);
	printf("\n");
	
	printf("Let string s2 = 'efghijk'\n");
	i = StrAssign(s2, "efghijk");
	printf("s2: ");
	StrPrint(s2);
	if (!i)
		printf("�����ȳ���MAXSIZE(=%d)\n", MAXSIZE);
	i = StrCompare(s1, s2);
	if(i<0)
		s='<';
	else if(i==0)
		s='=';
	else
		s='>';
	printf("��s1 %c ��s2\n", s);
	printf("\n");
	
	i = Concat(t, s1, s2);
	printf("��s1���Ӵ�s2�õ��Ĵ�tΪ: ");
	StrPrint(t);
	if(i==FALSE)
		printf("��t�нض�\n");
	ClearString(s1);
	printf("��Ϊ�մ���,��s1Ϊ: ");
	StrPrint(s1);
	printf("s1����Ϊ%d ���շ�%d(1:�� 0:��)\n",StrLength(s1), EmptyString(s1));
	printf("\n");

	printf("��t���Ӵ�, �������Ӵ�����ʼλ��n, �Ӵ�����m: ");
	n = 2;
	m = 3;
	printf("%d,%d \n", n, m);
	i = SubString(s2, t, n, m);
	if(i)
	{
		printf("�Ӵ�s2Ϊ: ");
		StrPrint(s2);
	}
	printf("�Ӵ�t�ĵ�n���ַ���,ɾ��m���ַ���������n, m: ");
	n = 4;
	m = 2;
	printf("%d,%d \n", n, m);
	StrDelete(t, n, m);
	printf("ɾ����Ĵ�tΪ: ");
	StrPrint(t);
	printf("\n");
	
	i = StrLength(s2)/2;
	StrInsert(s2, i, t);
	printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t��,��s2Ϊ:\n", i);
	StrPrint(s2);
	i = Index(s2,t,1);
	printf("s2�ĵ�%d����ĸ���t��һ��ƥ��\n", i);
	SubString(t, s2, 1, 1);
	printf("�ӵ�1��λ��������ȡ1λ��, ��tΪ��");
	StrPrint(t);
	Concat(s1,t,t);
	printf("��t��t���ӵô�s1Ϊ��");
	StrPrint(s1);
	Replace(s2,t,s1);
	printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ���,��s2Ϊ: ");
	StrPrint(s2);
	
	return 0;
}






