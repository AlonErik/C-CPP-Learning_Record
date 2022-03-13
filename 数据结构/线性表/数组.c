//���Ա��˳��洢�ṹ;
//��һ�ε�ַ�����Ĵ洢��Ԫ���δ洢���Ա������Ԫ��;
//��һά����ʵ��˳��洢�ṹ;

#include<stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20		//�洢�ռ��ʼ������

typedef int ElemType;	//��������Ԫ������
typedef int Status;		//���庯������, ��ֵΪ�����ṹ״̬����

typedef struct
{
	ElemType data[MAXSIZE];	//���飬�洢����Ԫ��
	int length;				//���Ա�ǰ�ĳ���
}SqList;

//��ʼ��˳�����Ա�;
Status InitList(SqList *L)
{
	L->length = 0;
	return OK;
}

//�����Ա�LΪ��,����true,���򷵻�false;
Status EmptyList(SqList L)
{
	if (L.length == 0)
		return TRUE;
	else
		return FALSE;
}

//������Ա�L;
Status ClearList(SqList *L)
{
	L->length = 0;
	return OK;
}

//��e����L�е�i��Ԫ�ص�ֵ;
Status GetElem(SqList L, int i, ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i-1];	//��i��λ��Ԫ�ض�Ӧ�����i-1�±��ֵ
	
	return OK;
}

//�����Ա�L�в��������ֵe��ȵ�Ԫ�ز����������;
Status LocateElem(SqList L, ElemType e)
{
	int i;
	if (L.length == 0)
		return ERROR;
	for(i=1; i<=L.length; i++)
	{
		if (L.data[i-1] == e)
			break;
	}
	if (i>L.length)
		return FALSE;
	
	return i;
}

//��L�еĵ�i��λ��֮ǰ�����µ�����Ԫ��e, L�ĳ��ȼ�1;
Status ListInsert(SqList *L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length+1)	//i�ȵ�1λ��С���߱����1λ��1λ�ô�
		return ERROR;
	if (i<=L->length)			//����λ�ò��ڱ�β
	{
		for(k=L->length-1; k>=i-1; k--)
			L->data[k+1] = L->data[k];
		//�±�Ϊlength-1��i-1�����1������i��Ԫ��ȫ������1λ
	}
	L->data[i-1] = e;	//���±�i-1����i��λ���ϲ����µ�����Ԫ��e
	L->length++;		//����1
	
	return OK;
}

//ɾ��L�ĵ�i������Ԫ��, ����e������ֵ, L�ĳ��ȼ�1;
Status ListDelete(SqList *L, int i, ElemType *e)
{
	int k;
	if (L->length == 0)
		return ERROR;
	if (i<1 || i>L->length)		//ɾ��λ�ò�����
		return ERROR;
	*e = L->data[i-1];			//���±�Ϊi-1����i��Ԫ�ص�ֵ����e
	if (i<L->length)
	{
		for(k=i; k<L->length; k++)
			L->data[k-1] = L->data[k];
			//�±�Ϊi��length-1����i+1�������һ��Ԫ��ȫ��ǰ��1λ
	}
	L->length--;	//����1
	
	return OK;
}

//�������Ա�L��Ԫ�ظ���;
Status ListLength(SqList L)
{
	return L.length;
}

//������Ա�L�е�Ԫ��
Status ListVisit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

//���ζ�L��ÿ������Ԫ�����;
Status ListTraverse(SqList L)
{
	int i;
	for(i=1; i<=L.length; i++)
		ListVisit(L.data[i-1]);
	printf("\n");
	
	return OK;
}

//�����������Ա�Lb������La�е�����ȫ�����뵽La��;
Status ListUnion(SqList *La, SqList Lb)
{
	int La_len, Lb_len, i;
	ElemType e;		//����La��Lb��ͬ������Ԫ��e
	La_len = ListLength(*La);		//������Ա�ĳ���
	Lb_len = ListLength(Lb);
	for(i = 1; i<=Lb_len; i++)
	{
		GetElem(Lb, i, &e);			//ȡ��Lb�е�i������Ԫ�ظ���e
		if (!LocateElem(*La, e))	//La�в����ں�e��ͬ������Ԫ��
			ListInsert(La, ++La_len, e);
	}
	return OK;
}

int main(void)
{
	SqList L;
	SqList L2;
	ElemType e;
	Status i;
	int j, k;
	
	i = InitList(&L);
	printf("��ʼ�����Ա�L��, L.length = %d\n", L.length);
	for(j=1; j<=5; j++)
		i = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ���β���1~5��, L.data = ");
	ListTraverse(L);
	printf("��ʱ, L.length = %d\n", L.length);
	printf("\n");
	
	i = EmptyList(L);
	printf("L�Ƿ�Ϊ��, i = %d (1: ��  0: ��)\n", i);
	i = ClearList(&L);
	printf("���L��, L.length = %d\n", L.length);
	i = EmptyList(L);
	printf("L�Ƿ�Ϊ��, i = %d (1: ��  0: ��)\n", i);
	printf("\n");
	
	for(j=1; j<=10; j++)
		ListInsert(&L, j, j);
	printf("��L�ı�β���β���1~10��, L.data = ");
	ListTraverse(L);
	printf("��ʱ, L.length = %d\n", L.length);
	printf("\n");
	
	ListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��, L.data = ");
	ListTraverse(L);
	printf("��ʱ, L.length = %d\n", L.length);
	printf("\n");
	
	GetElem(L, 5, &e);
	printf("L�е�5��Ԫ�ص�ֵ��: %d\n", e);
	for(j=8; j<=12; j++)
	{
		k = LocateElem(L, j);
		if (k)
			printf("L�е�%d��Ԫ�ص�ֵ��%d\n", k, j);
		else
			printf("L��û��ֵΪ%d��Ԫ��\n", j);
	}
	printf("\n");
	
	k = ListLength(L);
	for(j=k+1; j>=k; j--)
	{
		i = ListDelete(&L, j, &e);
		if (i==ERROR)
			printf("L��ɾ����%d��Ԫ��ʧ��\n", j);
		else
			printf("L��ɾ����%d��Ԫ�ص�ֵΪ: %d\n", j, e);
	}
	printf("�������L��Ԫ��: ");
	ListTraverse(L);
	printf("\n");
	
	//����һ����10������L2
	i = InitList(&L2);
	for(j=6; j<=15; j++)
		i = ListInsert(&L2, 1, j);
	printf("\n");
	
	printf("�����, �������L2��Ԫ��: ");
	ListTraverse(L2);
	ListUnion(&L, L2);
	printf("��������ϲ�L2��L��Ԫ��: ");
	ListTraverse(L);
	
	return 0;
}
