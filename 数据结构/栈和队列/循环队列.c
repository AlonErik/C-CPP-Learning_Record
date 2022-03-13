//ͷβ��ӵ�˳��洢�ṹ
//������: (rear+1)%QueueSize == front
//���г�: (rear-front+QueueSize)%QueueSize

#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int QElemType;	//��������Ԫ������
typedef int Status;		//���庯������, ��ֵΪ�����ṹ״̬����

typedef struct
{
	QElemType data[MAXSIZE];
	int front;		//ͷָ��
	int rear;		//βָ��, �����в���, ָ���βԪ�ص���һ��λ��
}SqQueue;

//��ʼ������;
Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

//�����д���, ������;
Status DestoryQueue(SqQueue *Q)
{
	if (Q->front != Q->rear)
		free(Q->data);
	Q->front = 0;
	Q->rear = 0;
	
	return OK;
}

//������Ϊ��, ����true, ���򷵻�false;
Status EmptyQueue(SqQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

//��ն���;
Status ClearQueue(SqQueue *Q)
{
	Q->front=Q->rear=0;
	return OK;
}

//�����д����ҷǿ�, ��e���ض�ͷԪ��;
Status GetHead(SqQueue Q, QElemType *e)
{
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.data[Q.front];
	
	return OK;
}

//�����д���, ������Ԫ��e����β;
Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1) % MAXSIZE;	//���������ת��ͷ��
	
	return OK;
}

//ɾ�����еĶ�ͷԪ��, ����e������ֵ;
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front+1) % MAXSIZE;	//���������ת��ͷ��
	
	return OK;
}

//���ض��е�Ԫ�ظ���;
Status QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

//��������е�Ԫ��;
Status QueueVisit(QElemType c)
{
	printf("%d ", c);
	return OK;
}

//�Ӷ�ͷ����β������ʾ�����е�ÿ��Ԫ��;
Status QueueTraverse(SqQueue Q)
{
	int i;
	i = Q.front;
	while(i != Q.rear)
	{
		QueueVisit(Q.data[i]);
		i = (i+1)%MAXSIZE;
	}
	printf("\n");
	
	return OK;
}

int main(void)
{
	SqQueue Q;
	QElemType e;
	Status i = 0;
	int j, k;
	
	InitQueue(&Q);
	printf("��ʼ��Q��, Q.length = %d\n", QueueLength(Q));
	printf("��ʼ�����к󣬶��пշ�%u (1: ��  0: ��)\n", EmptyQueue(Q));
	
	printf("����%d����Ӳ�����, Q.data: ", MAXSIZE-1);
	do{
		e = i + 100;
		i++;
		EnQueue(&Q, e);
	}while(i<MAXSIZE-1);
	QueueTraverse(Q);
	printf("��ʱ, ���г���Ϊ: %d\n",QueueLength(Q));
	printf("���ڶ��пշ�%u(1:�� 0:��)\n", EmptyQueue(Q));
	printf("\n");
	
	printf("����%d���ɶ�ͷɾ��Ԫ��,��β����Ԫ��:\n",MAXSIZE);
	for(k=1; k<=MAXSIZE; k++)
	{
		DeQueue(&Q, &e);
		printf("ɾ����Ԫ����: %d, �����Ԫ����: %d\n", e, k+1000);
		e = k+1000;
		EnQueue(&Q, e);
	}
	printf("��ʱ, Q.data: \n");
	QueueTraverse(Q);
	printf("��ʱ, ���г���Ϊ: %d\n",QueueLength(Q));
	printf("\n");
	
	printf("�����β������%d��Ԫ��\n",i+MAXSIZE);
	if(k-2>0)			//k = MAXSIZE+1��21
		printf("�����ɶ�ͷɾ��%d��Ԫ��:\n", k-2);
	while(QueueLength(Q)>2)
	{
		DeQueue(&Q, &e);
		printf("ɾ����Ԫ��ֵΪ%d\n", e);
	}
	
	j = GetHead(Q, &e);
	if(j)			//������Ϊ��ʱ, ����ѭ��
		printf("���ڵĶ�ͷԪ����: %d\n", e);
	printf("��ʱ, Q.data: \n");
	QueueTraverse(Q);
	ClearQueue(&Q);
	printf("��ն��к�, ���пշ�%u(1:�� 0:��)\n", EmptyQueue(Q));
	
	return 0;
}
