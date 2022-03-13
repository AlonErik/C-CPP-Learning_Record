//Ϊ��ʡ��û��Ҫ�Ļ���
//�����ַ���ǰ, �ȶ�Ҫ���ҵ��ַ�����

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;		//�������״̬����
typedef int ElemType;	//�������Ͷ���

typedef char String[MAXSIZE+1];	//0�ŵ�Ԫ��Ŵ��ĳ���

//����1����ֵ�����ַ�������chars�Ĵ�T;
Status StrAssign(String T, char *chars)
{
	int i;
	if (strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{	
		T[0] = strlen(chars);
		for(i=1; i<=T[0]; i++)
			T[i] = *(chars+i-1);
		return OK;
	}
}

//��S����, �����;
Status ClearString(String S)
{
	S[0] = 0;
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

//���next����ֵ;
Status NextPrint(int next[], int length)
{
	int i;
	for(i=1; i<=length; i++)
		printf("%d", next[i]);
	printf("\n");
	
	return OK;
}

//���ش�S��Ԫ�ظ���;
Status StrLength(String S)
{
	return S[0];
}

//���ص�ģʽƥ���㷨;
Status Index(String S, String T, int pos)
{
	int i = pos;		//����S�е�ǰλ�õ��±�
	int j = 1;			//�Ӵ�T�е�ǰλ�õ��±�
	while(i<=S[0] && j<=T[0])	//i������S�ĳ�����j������T�ĳ���
	{
		if (S[i] == T[j])		//��������ƥ��
		{
			++i;
			++j;
		}
		else		//ָ��������¿�ʼƥ��
		{
			i = i-j+2;	//i�����ϴ�ƥ����λ����һλ
			j = 1;		//j�����Ӵ�T����λ
		}
	}
	if (j > T[0])
		return i-T[0];
	else
		return FALSE;
}

//ͨ�����㷵���ַ�T��next����
Status GetNext(String T, int *next)
{
	int i, k;
	i = 1;		//�Ӵ�T�ӵ�һ��Ԫ����ʼ����
	k = 0;		//�����Եõ�next����
	next[1] = 0;
	while(i < T[0])
	{
		if (k==0 || T[i]==T[k])	
		{
			++i;
			++k;
			next[i] = k;
		}
		else
			k = next[k];	//���ַ�����ͬ, ��kֵ����
	}
	return OK;
}

//�����Ӵ�T������S�е�pos���ַ�֮���λ��;
int Index_KMP(String S, String T, int pos)
{
	int i = pos;		//����S�е�ǰλ�õ��±�
	int j = 1;			//�Ӵ�T�е�ǰλ�õ��±�
	int next[255];
	GetNext(T, next);	//��T�����õ�next����
	while(i<=S[0] && j<=T[0])
	{
		if (j==0 || S[i]==T[j])		//��������ƥ��
		{
			++i;
			++j;
		}
		else
			j = next[j];	//j�������ʵ�λ��, i����
	}
	if (j > T[0])
		return i-T[0];
	else
		return FALSE;
}

//��ģʽ��T��next��������ֵ����������nextval;
Status GetNextval(String T, int *nextval)
{
	int i, k;
	i = 1;
	k = 0;
	nextval[1] = 0;
	while(i < T[0])
	{
		if (k==0 || T[i]==T[k])
		{
			++i;
			++k;
			if (T[i]!=T[k])			//����ǰ�ַ���ǰ׺�ַ���ͬ
				nextval[i] = k;		//��ǰ��kΪnextval��iλ�õ�ֵ
			else							//����ǰ�ַ���ǰ׺�ַ���ͬ
				nextval[i] = nextval[k];	//��ǰ׺�ַ���nextval����nextval��iλ�õ�ֵ
		}
		else
			k = nextval[k];			//���ַ���ͬ, ��kֵ����
	}
	return OK;
}

int Index_KMP1(String S, String T, int pos)
{
	int i = pos;		//����S�е�ǰλ�õ��±�
	int j = 1;			//�Ӵ�T�е�ǰλ�õ��±�
	int next[255];
	GetNextval(T, next);	//��T�����õ�next����
	while(i<=S[0] && j<=T[0])
	{
		if (j==0 || S[i]==T[j])		//��������ƥ��
		{
			++i;
			++j;
		}
		else
			j = next[j];	//j�������ʵ�λ��, i����
	}
	if (j > T[0])
		return i-T[0];
	else
		return FALSE;
}

int main(void)
{
	int i, *p;
	String S, T;
	
	StrAssign(S, "abcdex");
	printf("�Ӵ�Ϊ: ");
	StrPrint(S);
	i = StrLength(S);
	p = (int*)malloc((i+1)*sizeof(int));
	GetNext(S, p);
	printf("NextΪ: ");
	NextPrint(p, StrLength(S));
	printf("\n");
	
	StrAssign(S, "abcabx");
	printf("�Ӵ�Ϊ: ");
	StrPrint(S);
	i = StrLength(S);
	p = (int*)malloc((i+1)*sizeof(int));
	GetNext(S, p);
	printf("NextΪ: ");
	NextPrint(p, StrLength(S));
	printf("\n");
	
	StrAssign(S, "ababaaaba");
	printf("�Ӵ�Ϊ: ");
	StrPrint(S);
	i = StrLength(S);
	p = (int*)malloc((i+1)*sizeof(int));
	GetNext(S, p);
	printf("NextΪ: ");
	NextPrint(p, StrLength(S));
	printf("\n");
	
	StrAssign(S, "aaaaaaaab");
	printf("�Ӵ�Ϊ: ");
	StrPrint(S);
	i = StrLength(S);
	p = (int*)malloc((i+1)*sizeof(int));
	GetNext(S, p);
	printf("NextΪ: ");
	NextPrint(p, StrLength(S));
	printf("\n");
	
	StrAssign(S, "ababaaaba");
	printf("   �Ӵ�Ϊ: ");
	StrPrint(S);
	i = StrLength(S);
	p = (int*)malloc((i+1)*sizeof(int));
	GetNext(S, p);
	printf("   NextΪ: ");
	NextPrint(p, StrLength(S));
	GetNextval(S, p);
	printf("NextValΪ: ");
	NextPrint(p, StrLength(S));
	printf("\n");
	
	StrAssign(S, "aaaaaaaab");
	printf("   �Ӵ�Ϊ: ");
	StrPrint(S);
	i = StrLength(S);
	p = (int*)malloc((i+1)*sizeof(int));
	GetNext(S, p);
	printf("   NextΪ: ");
	NextPrint(p, StrLength(S));
	GetNextval(S, p);
	printf("NextValΪ: ");
	NextPrint(p, StrLength(S));
	printf("\n");
	
	StrAssign(S, "00000000000000000000000000000000000000000000000001");
	printf("����SΪ: ");
	StrPrint(S);
	StrAssign(T, "0000000001");
	printf("�Ӵ�TΪ: ");
	StrPrint(T);
	printf("\n");
	printf("����S���Ӵ�T�ڵ�%d���ַ����״�ƥ�䣨����ģʽƥ���㷨��\n", Index(S, T, 1));
	printf("����S���Ӵ�T�ڵ�%d���ַ����״�ƥ�䣨KMP�㷨�� \n", Index_KMP(S, T, 1));
	printf("����S���Ӵ�T�ڵ�%d���ַ����״�ƥ�䣨KMP�����㷨��\n", Index_KMP1(S, T, 1));
	
	return 0;
}























