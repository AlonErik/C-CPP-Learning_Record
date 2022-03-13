//ֻ��β��ͷ��

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int QElemType;	//��������Ԫ������
typedef int Status;		//���庯������, ��ֵΪ�����ṹ״̬����

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct 
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

//��ʼ������;
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)
		return ERROR;
	Q->front->next = NULL;
	
	return OK;
}

//�����д���, ������;
Status DestoryQueue(LinkQueue *Q)
{
	while(Q->front)		//���п�ʱ, ����ѭ��
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;		//�൱��front����һλ����rearָ��ͬһ��Ԫ��
	}
	return OK;
}

//������Ϊ��, ����true, ���򷵻�false;
Status EmptyQueue(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

//��ն���;
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr p, q;	
	Q->rear = Q->front;		//front, rear��ָ��ͷ���
	p = Q->front->next;		//pָ���һ��Ԫ��
	Q->front->next = NULL;	//ɾ����һ��Ԫ��
	while(p)		//����Ϊ��ʱ, ����ѭ��
	{
		q = p;
		p = p->next;		//ָ��p����һλ
		free(q);
	}
	return OK;
}

//�����д����ҷǿ�, ��e���ض�ͷԪ��;
Status GetHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p;
	if(Q.front == Q.rear)
		return ERROR;
	p = Q.front->next;		//pָ���һ��Ԫ��
	*e = p->data;
	
	return OK;
}

//�����д���, ������Ԫ��e����β;
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if (!s)		//�洢�ռ����ʧ��
		return ERROR;
	s->data = e;		//��e����һ���ս��
	s->next = NULL;
	Q->rear->next = s;	//��ӵ��e���½��s����ԭ��βָ��ĺ��
	Q->rear = s;		//��s����Ϊ��β���
	
	return OK;
}

//ɾ�����еĶ�ͷԪ��, ����e������ֵ;
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;		//����ɾ���Ķ�ͷ����ݴ��p
	*e = p->data;			//����ɾ���Ķ�ͷ����ֵ����e
	Q->front->next = p->next;	//��ԭ��ͷ���ĺ�̼�p->next����ͷ���ĺ��
	if(Q->rear == p)
		Q->rear = Q->front;
	free(p);
	
	return OK;
}

//���ض��е�Ԫ�ظ���;
Status QueueLength(LinkQueue Q)
{
	int i = 0;
	QueuePtr p;
	p = Q.front;
	while(p != Q.rear)
	{
		i++;
		p = p->next;	//pָ�����һλ
	}
	return i;
}

//��������е�Ԫ��;
Status QueueVisit(QElemType c)
{
	printf("%d ", c);
	return OK;
}

//�Ӷ�ͷ����β������ʾ�����е�ÿ��Ԫ��;
Status QueueTraverse(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;		//��һ��Ԫ��
	while(p)
	{
		QueueVisit(p->data);
		p = p->next;
	}
	printf("\n");
	
	return OK;
}

int main(void)
{
	LinkQueue Q;
	QElemType e;
	Status i;
	
	i = InitQueue(&Q);
	printf("��ʼ��Q��, Q.length = %d\n", QueueLength(Q));
	printf("��ʼ�����к󣬶��пշ�%u (1: ��  0: ��)\n", EmptyQueue(Q));
	EnQueue(&Q,-5);
	EnQueue(&Q,5);
	EnQueue(&Q,10);
	printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", QueueLength(Q));
	printf("�Ƿ�ն��У�%d (1: ��  0: ��) ", EmptyQueue(Q));
	printf("���е�Ԫ������Ϊ��");
	QueueTraverse(Q);
	
	DeQueue(&Q, &e);
	printf("ɾ����ͷԪ��: %d, ��ʱ,���еĳ���Ϊ: %d\n", e, QueueLength(Q));
	GetHead(Q, &e);
	printf("�µĶ�ͷԪ��Ϊ: %d\n", e);
	ClearQueue(&Q);
	printf("��ն��к�, Q.front=%d, q.rear=%d, q.front->next=%d\n", Q.front, Q.rear, Q.front->next);
	DestoryQueue(&Q);
	printf("���ٶ��к�, Q.front=%d, q.rear=%d\n", Q.front, Q.rear);
	
	return 0;
}
