//��һ������洢����ջ, �ֱ���ʼ�˺�ĩ���������м�����

#include<stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20		//�洢�ռ��ʼ������

typedef int SElemType;	//��������Ԫ������
typedef int Status;		//���庯������, ��ֵΪ�����ṹ״̬����

typedef struct
{
	SElemType data[MAXSIZE];
	int top1;		//ջ1��ջ��ָ��	
	int top2;		//ջ2��ջ��ָ��
}SqDoubleStack;			//ջ��ָ�뼴��ǰջ��Ԫ�ص��±�ֵ

//��ʼ��ջ;
Status InitStack(SqDoubleStack *S)
{
	S->top1 = -1;			//ջ1��, ��һ��Ԫ����ջʱ�Լ�
	S->top2 = MAXSIZE;		//ջ2��, ��һ��Ԫ����ջʱ�Լ�
	return OK;
}

//��ջ����, ������
Status DestoryStack(SqDoubleStack *S)
{
	if (S->top1!=-1 || S->top2!=MAXSIZE)
	{
		S->top1 = -1;
		S->top2 = MAXSIZE;
	}
	return OK;
}

//��ջΪ��, ����true, ���򷵻�false;
Status EmptyStack(SqDoubleStack S)
{
	if (S.top1==-1 && S.top2==MAXSIZE)
		return TRUE;
	else
		return FALSE;
}

//���ջ;
Status ClearStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

//��ջ�����ҷǿ�, ��e����ջ��Ԫ��;
Status GetTop(SqDoubleStack S, SElemType *e, int StackNumber)
{
	if (StackNumber == 1)
	{
		if (S.top1 == -1)
			return ERROR;
		*e = S.data[S.top1];
	}
	else if (StackNumber == 2)
	{
		if (S.top2 == MAXSIZE)
			return ERROR;
		*e = S.data[S.top2];
	}
	return OK;
}

//��ջ����, ������Ԫ��e��ջ��;
Status Push(SqDoubleStack *S, SElemType e, int StackNumber)
{
	if (S->top1+1 == S->top2)		//�ж��Ƿ�ջ��
		return ERROR;
	if (StackNumber == 1)
		S->data[++S->top1] = e;		//ջ1, ����top1+1���ٸ�����Ԫ�ظ�ֵ
	else if (StackNumber == 2)
		S->data[--S->top2] = e;		//ջ2, ����top2-1���ٸ�����Ԫ�ظ�ֵ
	
	return OK;
}

//��ջ����, ɾ��ջ��Ԫ��, ����e������ֵ;
Status Pop(SqDoubleStack *S, SElemType *e, int StackNumber)
{
	if (StackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;
		*e = S->data[S->top1--];	//ջ1, �Ƚ�ջ��Ԫ�ظ���e�ٳ�ջ
	}
	if (StackNumber == 2)
	{
		if (S->top1 == MAXSIZE)
			return ERROR;
		*e = S->data[S->top2++];	//ջ2, �Ƚ�ջ��Ԫ�ظ���e�ٳ�ջ
	}
	
	return OK;
}

//���ջ�е�Ԫ��;
Status StackVisit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

//����ջ��Ԫ�ظ���;
Status StackLength(SqDoubleStack S)
{
	return (S.top1+1)+(MAXSIZE-S.top2);
}

//��ջ�׵�ջ��������ʾջ�е�ÿ��Ԫ��;
Status StackTraverse(SqDoubleStack S)
{
	int i;
	i = 0;
	while(i <= S.top1)
	{
		StackVisit(S.data[i++]);
	}
	i = S.top2;
	while(i < MAXSIZE)
	{
		StackVisit(S.data[i++]);
	}
	printf("\n");
	
	return OK;
}

int main(void)
{
	SqDoubleStack S;
	SElemType e;
	int j;
	
	InitStack(&S);
	printf("��ʼ��S��, S.length = %d\n", StackLength(S));
	for(j=1; j<=5; j++)
		Push(&S, j, 1);
	for(j=MAXSIZE; j>=MAXSIZE-2; j--)
		Push(&S, j, 2);
	printf("�ֱ���ջ��, ջ��Ԫ������ΪS.data = ");
	StackTraverse(S);
	printf("��ʱ, S.length = %d\n", StackLength(S));
	printf("\n");
	
	Pop(&S, &e, 1);
	printf("����ջ1��ջ��Ԫ��: %d\n", e);
	Pop(&S, &e, 2);
	printf("����ջ2��ջ��Ԫ��: %d\n", e);
	printf("��ʱ, S.length = %d\n, ջ��Ԫ������ΪS.data = ", StackLength(S));
	StackTraverse(S);
	printf("\n");
	
	printf("ջ�Ƿ�Ϊ��: %d (1: ��  0: ��)\n", EmptyStack(S));
	ClearStack(&S);
	printf("���ջ��, ջ�Ƿ�Ϊ��: %d (1: ��  0: ��)\n", EmptyStack(S));
	
	return 0;
}
