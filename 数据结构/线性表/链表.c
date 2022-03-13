//���Ա����ʽ�洢�ṹ;
//��һ������Ĵ洢��Ԫ�洢���Ա������Ԫ��;
//��n����������һ������, ʵ����ʽ�洢�ṹ;
//��һ�����Ĵ洢λ�ý�ͷָ��, ������ͷ���,��Ϊָ��ͷ����ָ��;
//��һ�����ǰ����һ��ͷ���, ��ָ����洢ָ���һ������ָ��;

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;	//��������Ԫ������
typedef int Status;		//���庯������, ��ֵΪ�����ṹ״̬����

//����һ��������ṹ��
typedef struct Node		//����ṹ�����
{
	ElemType data;		//����������
	struct Node *next;	//����ָ����
}Node;
typedef struct Node *LinkList;
//Node, *LinkList��ΪNode�ı���, ��һ����Ҫָ�����,һ����Ҫָ������
//����ɴ������Ԫ�ص�������ʹ�ź�̽��ĵ�ַ��ָ�������
//n���������һ������
//LinkList  L����һ��ָ����� (ֻ�ı�ṹ�������, ���ı�L�ĵ�ַ)
//��ʱ*LΪһ���ṹ��
//LinkList *L����һ��ָ��ṹ��ָ���ָ�� (��ı�L�ĵ�ַ)
//��ʱ**LΪһ���ṹ��

//��ʼ����ʽ���Ա�;
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	//����ͷ���, ��ʹLָ���ͷ���
	if (!(*L))			//�洢����ʧ��
		return ERROR;
	(*L)->next = NULL;	//ָ����Ϊ��
	
	return OK;
}

//�����Ա�LΪ��,����true,���򷵻�false;
Status EmptyList(LinkList L)
{
	if (L->next)
		return FALSE;
	else
		return TRUE;
}

//������Ա�L;
Status ClearList(LinkList *L)
{
	LinkList p, s;
	p = (*L)->next;		//pָ��L�ĵ�һ�����
	while( p )			//pû����β
	{
		s = p->next;	//��p�ĺ�̽�� ---> s
		free(p);		//�ͷ�p���
		p = s;			//�൱�ڽ�p����1λ�������
	}
	(*L)->next = NULL;	//ͷ���ָ����Ϊ��
	
	return OK;
}

//��e����L�е�i��Ԫ�ص�ֵ;
Status GetElem(LinkList L, int i, ElemType *e)
{
	int k;
	LinkList p;			//����һ�����p
	p = L->next;		//pָ��L�ĵ�һ�����
	k = 1;				//kΪ������
	while(p && k<i)		//p��Ϊ�ջ��߼�����k������iʱ, ѭ������
	{
		p = p->next;	//pָ����һ�����
		++k;
	}
	if (!p || k>i)
		return ERROR;	//��i��Ԫ�ز�����
	*e = p->data;
	
	return OK;
}

//�����Ա�L�в��������ֵe��ȵ�Ԫ�ز����������;
Status LocateElem(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while(p)
	{
		i++;
		if (p->data == e)
			return i;
		p = p->next;
	}
	return 0;
}

//��L�еĵ�i��λ��֮ǰ�����µ�����Ԫ��e, L�ĳ��ȼ�1;
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int k;
	LinkList p, s;
	p = *L;
	k = 1;
	while(p && k<i)		//p��Ϊ�ջ��߼�����k������iʱ, ѭ������;
	{
		p = p->next;
		++k;
	}
	if (!p || k>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));	//����һ���½��;
	s->data = e;		
	s->next = p->next;	//��p�ĺ�̽�� ---> s�ĺ�̽��
	p->next = s;		//��s ---> p�ĺ�̽��
	
	return OK;
}

//ɾ��L�ĵ�i������Ԫ��, ����e������ֵ, L�ĳ��ȼ�1;
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int k;
	LinkList p, s;
	p = *L;
	k = 1;
	while(p->next && k<i)	//����Ѱ�ҵ�i��Ԫ��
	{
		p = p->next;
		++k;
	}
	if (!(p->next) || k>i)
		return ERROR;
	s = p->next;		//����ɾ���Ľ��p->next ---> s
	p->next = s->next;	//��s�ĺ�̽�� ---> p�ĺ�̽��
	*e = s->data;
	free(s);
	
	return OK;
}

//�������Ա�L��Ԫ�ظ���;
Status ListLength(LinkList L)
{
	int i = 0;
	LinkList p;
	p = L->next;
	while(p)
	{
		++i;
		p = p->next;	
	}
	return i;
}

//������Ա�L�е�Ԫ��
Status ListVisit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

//���ζ�L��ÿ������Ԫ�����;
Status ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while(p)
	{
		ListVisit(p->data);
		p = p->next;
	}
	printf("\n");
	
	return OK;
}

//�������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L (ͷ�巨)
Status CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));		//��ʼ�����������
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;	//����һ����ͷ���ĵ�����
	for(i=0; i<n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));	//����һ���½��
		p->data = rand()%100+1;		//�������100���ڵ�����
		p->next = (*L)->next;		//��ͷ����̽�� ---> p�ĺ�̽��
		(*L)->next = p;				//��p ---> ͷ����̽��			
	}
	return OK;
}

//�������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L (β�巨)
Status CreateListTail(LinkList *L, int n)
{
	LinkList p, s;
	int i;
	srand(time(0));		//��ʼ�����������
	*L = (LinkList)malloc(sizeof(Node));
	s = *L;				//����һ��ָ��β���Ľ��s
	for(i=0; i<n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));	//����һ���½ڵ�
		p->data = rand()%100+1;		//�������100���ڵ�����
		s->next = p;				//����β�ն˽��ָ��ָ���½��;
		s = p;						//��p ---> ��β�ն˽��, ʼ�ս�sָ��β��
	}
	s->next = NULL;					//ѭ��������, ��β�����ָ�����ÿ�
	
	return OK;
}

int main(void)
{
	LinkList L;
	ElemType e;
	Status i;
	int j, k;
	
	i = InitList(&L);
	printf("��ʼ�����Ա�L��, L.length = %d\n", ListLength(L));
	for(j=1; j<=5; j++)
		i = ListInsert(&L, 1, j);
	printf("��L�ı�ͷ���β���1~5��, L.data = ");
	ListTraverse(L);
	printf("��ʱ, L.length = %d\n", ListLength(L));
	printf("\n");
	
	i = EmptyList(L);
	printf("L�Ƿ�Ϊ��, i = %d (1: ��  0: ��)\n", i);
	i = ClearList(&L);
	printf("���L��, L,length = %d\n", ListLength(L));
	i = EmptyList(L);
	printf("L�Ƿ�Ϊ��, i = %d (1: ��  0: ��)\n", i);
	printf("\n");
	
	for(j=1; j<=10; j++)
		ListInsert(&L, j, j);
	printf("��L�ı�β���β���1~10��, L.data = ");
	ListTraverse(L);
	printf("��ʱ, L.length = %d\n", ListLength(L));
	printf("\n");
	
	ListInsert(&L, 1, 0);
	printf("��L�ı�ͷ����0��, L.data = ");
	ListTraverse(L);
	printf("��ʱ, L.length = %d\n", ListLength(L));
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
	
	j=5;
	ListDelete(&L,j,&e); /* ɾ����5������ */
	printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);	
	printf("�������L��Ԫ�أ�");
	ListTraverse(L); 
	
	i=ClearList(&L);
	printf("\n���L��ListLength(L)=%d\n",ListLength(L));
	CreateListHead(&L,20);
	printf("���崴��L��Ԫ��(ͷ�巨)��");
	ListTraverse(L);
	
	i=ClearList(&L);
	printf("\nɾ��L��ListLength(L)=%d\n",ListLength(L));
	CreateListTail(&L,20);
	printf("���崴��L��Ԫ��(β�巨)��");
	ListTraverse(L); 
	
	return 0;
}







