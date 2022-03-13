//��ջ�����ڵ������ͷ��, ��ջ����Ҫͷ���, �ҳ���������

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int SElemType;	//��������Ԫ������
typedef int Status;		//���庯������, ��ֵΪ�����ṹ״̬����

typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;		//LinkStackPtr��ΪStackNode��ָ��

typedef struct
{
	LinkStackPtr top;			//��Ϊջ��ָ��
	int count;
}LinkStack;						//��StackNode��ָ��Ƕ�뵽LinkStack�Ľṹ��

//��ʼ����ջ;
Status InitStack(LinkStack *S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->top = NULL;
	S->count = 0;
	return OK;
}

//��ջΪ��ջ������true, ���򷵻�false;
Status StackEmpty(LinkStack S)
{ 
	if (S.count==0)
		return TRUE;
	else
		return FALSE;
}

//���ջ;
Status ClearStack(LinkStack *S)
{
	LinkStackPtr p, q;
	p = S->top;			//����ָ��pָ��ջ��
	while(p)
	{
		q = p;
		p = p->next;	//����һλ
		free(q);
	}
	S->count = 0;
	
	return OK;
}

//��ջ�����ҷǿ�, ��e����ջ��Ԫ��;
Status GetTop(LinkStack S, SElemType *e)
{
	if (S.top == NULL)
		return ERROR;
	else
		*e = S.top->data;
	
	return OK;
}

//��ջ����, ������Ԫ��e��ջ��;
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;		//��Ԫ��ֵΪe���½�㶨��Ϊs
	s->next = S->top;	//����ǰ��ջ��Ԫ�ظ����½���ֱ�Ӻ��
	S->top = s;
	S->count++;
	
	return OK;
}

//ɾ��ջ��Ԫ��, ����e������ֵ;
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;				//��ջ����㸳ֵ��p
	S->top = S->top->next;	//ջ��ָ������һλ, ָ���һ���
	free(p);
	S->count--;
	
	return OK;
}

//����ջ��Ԫ�ظ���;
Status StackLength(LinkStack S)
{
	return S.count;
}

//���ջ�е�Ԫ��;
Status StackVisit(SElemType c)
{
	printf("%d ", c);
	return OK;
}

//��ջ�׵�ջ��������ʾջ�е�ÿ��Ԫ��;
Status StackTraverse(LinkStack S)
{
	LinkStackPtr p;
	p = S.top;
	while(p)
	{
		StackVisit(p->data);
		p = p->next;
	}
	printf("\n");
	
	return OK;
}

int main(void)
{
	LinkStack S;
	SElemType e;
	int j;
	
	InitStack(&S);
	printf("��ʼ��S��, S.length = %d\n", StackLength(S));
	for(j=1; j<=10; j++)
		Push(&S, j);
	printf("������ջ��, ջ��Ԫ������ΪS.data = ");
	StackTraverse(S);
	printf("��ʱ, S.length = %d\n", StackLength(S));
	printf("\n");
	
	Pop(&S, &e);
	printf("������ջ��Ԫ�� e=%d\n", e);
	GetTop(S, &e);
	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(S));
	printf("��ʱ, S.data = ");
	StackTraverse(S);
	
	printf("ջ�Ƿ�Ϊ��: %d (1: ��  0: ��)\n",StackEmpty(S));
	ClearStack(&S);
	printf("���ջ��ջ�Ƿ�Ϊ��: %d (1: ��  0: ��)\n",StackEmpty(S));
	
	return 0;
}
