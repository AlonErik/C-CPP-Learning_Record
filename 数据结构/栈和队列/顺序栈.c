//ջ��˳��洢�����Ա�˳��洢�ļ�

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
	int top;			//ջ��ָ�뼴��ǰջ��Ԫ�ص��±�ֵ
}SqStack;

//��ʼ��˳��ջ;
Status InitStack(SqStack *S)
{
	S->top = -1;			//��ջ, ��һ��Ԫ����ջʱ�Լ�ָ��0Ԫ��
	return OK;
}

//��ջ����, ������
Status DestoryStack(SqStack *S)
{
	if (S->top != -1)
		S->top = -1;
	
	return OK;
}

//��ջΪ��, ����true, ���򷵻�false;
Status EmptyStack(SqStack S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}

//���ջ;
Status ClearStack(SqStack *S)
{
	S->top = -1;
	return OK;
}

//��ջ�����ҷǿ�, ��e����ջ��Ԫ��;
Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == -1)
		return ERROR;
	*e = S.data[S.top];
	
	return OK;
}

//��ջ����, ������Ԫ��e��ջ��;
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE-1)	//�ж��Ƿ�ջ��
		return ERROR;
	S->top++;					//ջ��ָ���1
	S->data[S->top] = e;
	
	return OK;
}

//ɾ��ջ��ջ��Ԫ��, ����e������ֵ;
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	
	return OK;
}

//����ջ��Ԫ�ظ���;
Status StackLength(SqStack S)
{
	return S.top+1;
}

//���ջ�е�Ԫ��;
Status StackVisit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

//��ջ�׵�ջ��������ʾջ�е�ÿ��Ԫ��;
Status StackTraverse(SqStack S)
{
	int i;
	for(i=0; i<=S.top; i++)
	{
		StackVisit(S.data[i]);
	}
	printf("\n");
	
	return OK;
}

int main(void)
{
	SqStack S;
	SElemType e;
	Status i;
	int j;
	
	i = InitStack(&S);
	printf("��ʼ��S��, S.length = %d\n", StackLength(S));
	for(j=1; j<=10; j++)
		i = Push(&S, j);
	printf("��1~10������ջ��, S.data = ");
	StackTraverse(S);
	printf("��ʱ, S.length = %d\n", StackLength(S));
	printf("\n");
	
	i = EmptyStack(S);
	printf("S�Ƿ�Ϊ��, i = %d (1: ��  0: ��)\n", i);
	i = ClearStack(&S);
	printf("���S��, S.length = %d\n", StackLength(S));
	i = EmptyStack(S);
	printf("S�Ƿ�Ϊ��, i = %d (1: ��  0: ��)\n", i);
	printf("\n");
	
	for(j=1; j<=5; j++)
		i = Push(&S, j);
	printf("��1~5������ջ��, S.data = ");
	StackTraverse(S);
	Push(&S, 6);
	printf("�ٽ�6��ջ��, S,data = ");
	StackTraverse(S);
	Pop(&S, &e);
	printf("������ջ��Ԫ�� e=%d\n", e);
	GetTop(S, &e);
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(S));
	
	return 0;
}
