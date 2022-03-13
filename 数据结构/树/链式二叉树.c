//��1���������2��ָ������ɶ�������
//����������1��ָ����˫�׵�ָ����, ������������

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

TElemType Nil=' ';			//�ַ����Կո��Ϊ��

//���������;
int treeIndex = 1;
typedef char String[24];	//0�ŵ�Ԫ�洢�����
String str;

Status StrAssign(String T, char *chars)
{
	int i;
	if(strlen(chars) > MAXSIZE)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for(i=1; i<=T[0]; i++)
			T[i] = *(chars+i-1);
		return OK;
	}
}

Status visit(TElemType e)
{
	printf("%c ",e);
	return OK;
}

//���ṹ;
typedef struct BiTNode
{
	TElemType data;		//�������
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode, *BiTree;

//����ն�����;
Status InitBiTree(BiTree *T)
{
	*T = NULL;
	return OK;
}

#define ClearBiTree InitBiTree
//˳��洢�����, ��������ȫһ��

//������������, ������;
Status DestoryBiTree(BiTree *T)
{
	if(*T)
	{
		if((*T)->lchild)	//������
			DestoryBiTree(&(*T)->lchild);	//������������
		if((*T)->rchild)	//���Һ���
			DestoryBiTree(&(*T)->rchild);	//�����Һ�������
		free(*T);			//�ͷŸ����
		*T = NULL;			//��ָ�븳0
	}
	return OK;
}

//��definition�и��������Ķ�����������;
Status CreateBiTree(BiTree *T)
{
	TElemType ch;
	ch = str[treeIndex++];
	if(ch=='#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			return ERROR;
		(*T)->data = ch;	//���ɸ����
		CreateBiTree(&(*T)->lchild);	//����������
		CreateBiTree(&(*T)->rchild);	//����������
	}
	return OK;
}

//����TΪ����, ����true, ���򷵻�false;
Status EmptyBiTree(BiTree T)
{
	if(T)
		return FALSE;
	else
		return TRUE;
}

//������T�����;
Status DepthBiTree(BiTree T)
{
	int i, j;
	if(!T)
		return ERROR;
	if(T->lchild)
		i = DepthBiTree(T->lchild);
	else
		i = 0;
	if(T->rchild)
		i = DepthBiTree(T->rchild);
	else
		j = 0;
	return i>j?i+1:j+1;
}

//������T�ĸ����;
Status Root(BiTree T)
{
	if(EmptyBiTree(T))
		return Nil;
	else
		return T->data;
}

//����cur_e����ֵ;
TElemType Value(BiTree p)
{
	return p->data;
}

//�����cur_e��ֵΪvalue;
	Status Assign(BiTree p, TElemType value)
{
	p->data = value;
}

//ǰ��ݹ����, ��---��---��;
Status PreOrderTraverse(BiTree T)
{
	if(T==NULL)
		return ERROR;
	printf("%c", T->data);		//��ʾ�������, �ɸ���Ϊ�����Խ��Ĳ���
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

//����ݹ����, ��---��---��;
Status InOrderTraverse(BiTree T)
{
	if(T==NULL)
		return ERROR;
	InOrderTraverse(T->lchild);
	printf("%c", T->data);
	InOrderTraverse(T->rchild);
}

//����ݹ����, ��---��---��;
Status PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return ERROR;
	PostOrderTraverse(T->lchild);
	PostOrderTraverse(T->rchild);
	printf("%c", T->data);
}

int main(void)
{
	int i;
	BiTree T;
	TElemType e;
	
	InitBiTree(&T);
	StrAssign(str, "ABDH#K###E##CFI###G#J##");
	CreateBiTree(&T);
	printf("����һ��������, �Ƿ�Ϊ��: %d (1:�� 0:��)\n", EmptyBiTree(T));
	printf("�������Ϊ: %d\n", DepthBiTree(T));
	e = Root(T);
	printf("�������ĸ�Ϊ: %c\n", e);
	printf("\nǰ�����������:");
	PreOrderTraverse(T);
	printf("\n�������������:");
	InOrderTraverse(T);
	printf("\n�������������:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n��ն�������, �Ƿ�Ϊ��: %d (1:�� 0:��)\n", EmptyBiTree(T));
	printf("��ʱ, �������Ϊ: %d\n", DepthBiTree(T));
	i = Root(T);
	if(!i)
		printf("���գ��޸�\n");
	return 0;
}
