//��Ϊ����߲���ɾ��Ч��, ���ܹ��ϸ�Ч��ʵ�ֲ���
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 	//�洢�ռ��ʼ������

typedef int Status;

typedef struct BiTNode	//���ṹ
{
	int data;			//�������
	struct BiTNode *lchild, *rchild;	//���Һ���ָ��
}BiTNode, *BiTree;

//�ݹ���Ҷ���������T���Ƿ����ֵkey;
//ָ��fָ��T��˫��, ��ʼ����ֵΪNULL;
//ָ��p�������ز��ҽ��
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if(!T)
	{
		*p = f;
		return FALSE;
	}
	else if(key==T->data)
	{
		*p = T;
		return TRUE;
	}
	else if(key<T->data)
		return SearchBST(T->lchild, key, T, p);
	else
		return SearchBST(T->rchild, key, T, p);
}

//������ֵΪkey������Ԫ��ʱ, ����key������TURE;
Status InsertBST(BiTree *T, int key)
{
	BiTree p, s;
	if(!SearchBST(*T, key, NULL, &p))
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(!p)
			*T = s;			//����sΪ�µĸ����
		else if(key<p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return TRUE;
	}
	else		//����������ؼ�����ͬ�Ľ��
		return FALSE;
}

//ɾ�����p���ؽ���/������;
Status Delete(BiTree *p)
{
	BiTree q, s;
	if((*p)->rchild==NULL)		//ֻ��Ҫ�ؽ�������
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if((*p)->lchild==NULL)	//ֻ��Ҫ�ؽ�������
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else		//���Ҿ���Ϊ��
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)	//�����������ҽ��(�Ҵ�ɾ����ǰ��)
		{
			q = s;
			s = s->rchild;	
		}
		(*p)->data = s->data;	//sָ��ɾ����ֱ��ǰ��(����ɾ���ǰ����ֵȡ����ɾ����ֵ)
		if(q!=*p)
			q->rchild = s->lchild;		//�ؽ�q��������
		else
			q->lchild = s->rchild;		//�ؽ�q��������
		free(s);
	}
	return OK;
}

//����ֵΪkey������Ԫ��ʱ, ɾ���ý�㲢����TRUE;
Status DeleteBST(BiTree *T, int key)
{
	if(!*T)
		return FALSE;
	else
	{
		if(key==(*T)->data)
			return Delete(T);
		else if(key<(*T)->data)
			return DeleteBST(&(*T)->lchild, key);
		else
			return DeleteBST(&(*T)->rchild, key);
	}
}

int main(void)
{
	int i;
	int a[10]={62,88,58,47,35,73,51,99,37,93};
	BiTree T = NULL;
	for(i=0; i<10; i++)
	{
		InsertBST(&T, a[i]);
	}
	DeleteBST(&T, 93);
	DeleteBST(&T, 47);
	
	return 0;
}









