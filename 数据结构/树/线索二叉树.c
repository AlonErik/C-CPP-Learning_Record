//��������+ָ��ǰ����̵�ָ��(����)������������, ����������ת���˫������
//��������ĳ�ִ������ʹ���Ϊ�����������Ĺ��̳�Ϊ������, ���ڱ����Ĺ������޸Ŀ�ָ��
//��ָ�����е�lchildָ��ǰ��, rchildָ����
//��������ֱ�־tag, �����ֺ��Ӻ�ǰ�����

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 			//�洢�ռ��ʼ������

typedef int Status;			//�������״̬����
typedef char TElemType;		//��������ݽṹ����
typedef enum {Link, Thread} PointerTag;
//Link==0��ʾָ�����Һ��ӵ�ָ��
//Thread==1��ʾָ��ǰ����̵�����
TElemType Nil='#';			//�ַ�����#Ϊ��

typedef struct BiThrNode	//���������洢���ṹ
{
	TElemType data;		//�������
	struct BiThrNode *lchild, *rchild;		//���Һ���ָ��
	PointerTag LTag;	//Ϊ0ָ������, Ϊ1ָ��ǰ��
	PointerTag RTag;	//Ϊ0ָ���Һ���, Ϊ1ָ����
}BiThrNode, *BiThrTree;

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

//��ǰ����������������н���ֵ,�������������;
Status CreateBiThrTree(BiThrTree *T)
{
	TElemType h;
	scanf("%c", &h);
	if(h==Nil)
		*T = NULL;
	else
	{
		*T = (BiThrTree)malloc(sizeof(BiThrNode));
		if(!*T)
			return ERROR;
		(*T)->data = h;		//���ɸ����
		CreateBiThrTree(&(*T)->lchild);		//����������
		if((*T)->lchild)	//������
			(*T)->LTag = Link;
		CreateBiThrTree(&(*T)->rchild);		//����������
		if((*T)->rchild)	//���Һ���
			(*T)->RTag = Link;
	}
	return OK;
}

//ȫ�ֱ���, ʼ��ָ��ոշ��ʹ��Ľ��;
BiThrTree pre;

//���������������������;
Status InThreading(BiThrTree p)
{
	if(p)
	{
		InThreading(p->lchild);		//�ݹ�������������
		if(!p->lchild)		//������
		{
			p->LTag = Thread;		//ǰ������
			p->lchild = pre;		//����ָ��ǰ��
		}
		if(!pre->rchild)	//ǰ�����Һ���
		{
			pre->RTag = Thread;		//�������
			pre->rchild = p;		//ǰ���Һ���ָ��ָ����(��ǰ���p)
		}
		pre = p;			//����preָ��p��ǰ��
		InThreading(p->rchild);		//�ݹ�������������
	}
	return OK;
}

//�������������T,����������������,Thrtָ��ͷ���;
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
	*Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
	if(!*Thrt)
		return ERROR;
	(*Thrt)->LTag = Link;		//����ͷ���
	(*Thrt)->RTag = Thread;
	(*Thrt)->rchild = (*Thrt);	//��ָ���ָ
	if(!T)		//��������Ϊ��, ����ָ���ָ
		(*Thrt)->lchild = *Thrt;
	else
	{
		(*Thrt)->lchild = T;
		pre = (*Thrt);
		InThreading(T);		//���������������������
		pre->rchild = *Thrt;
		pre->RTag = Thread;		//���1�����������
		(*Thrt)->rchild = pre;
	}
	return OK;
}

//�����������������T(ͷ���)�ķǵݹ��㷨;
Status InOrderTraverse_Thr(BiThrTree T)
{
	BiThrTree p;
	p = T->lchild;		//pָ������
	while(p!=T)			//����/��������ʱ, p==T
	{
		while(p->LTag == Link)
			p = p->lchild;
		if(!visit(p->data))		//������������Ϊ�յĽ��
			return ERROR;
		while(p->RTag==Thread && p->rchild!=T)
		{
			p = p->rchild;
			visit(p->data);		//���ʺ�̽��
		}
		p = p->rchild;
	}
	return OK;
}

int main(void)
{
	BiThrTree H,T;
	printf("�밴ǰ�����������(��:'ABDH##I##EJ###CF##G##')\n");
	CreateBiThrTree(&T); 		//��ǰ�����������
	InOrderThreading(&H,T); 	//�������,������������������
	printf("�������(���)����������:\n");
	InOrderTraverse_Thr(H); 	//�������(���)����������
	printf("\n");
	return 0;
}









