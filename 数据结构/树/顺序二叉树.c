//��1ά����洢�������Ľ��, һ��ֻ������ȫ������
//���ҽ��Ĵ洢λ�ü������±������ֽ�����߼���ϵ

#include<stdio.h>
#include<math.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 			//�洢�ռ��ʼ������
#define MAX_TREE_SIZE 100 		//���������������

typedef int Status;			//�������״̬����
typedef int TElemType;		//��������ݽṹ����
typedef TElemType SqBiTree[MAX_TREE_SIZE];	//0�ŵ�Ԫ�洢�����

TElemType Nil = 0;			//������0Ϊ��

typedef struct		//������λ��
{
	int level;		//���Ĳ�
	int order;		//�������
}Position;

Status visit(TElemType c)
{
	printf("%d ", c);
	return OK;
}

//�������T, TΪ�̶�����, �ʲ���Ҫ&;
Status InitBiTree(SqBiTree T)
{
	int i;
	for(i=0; i<MAX_TREE_SIZE; i++)
		T[i] = Nil;		//��ʼֵΪ��
	return OK;
}

#define ClearBiTree InitBiTree
//˳��洢�����, ��������ȫһ��

//��definition�и��������Ķ�����������;
Status CreateBiTree(SqBiTree T)
{
	int i = 0;
	printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�������������%d:\n", MAX_TREE_SIZE);
	while(i<10)
	{
		T[i] = i+1;
		if (i!=0 && T[(i+1)/2-1]==Nil && T[i]!=Nil)		//�˽��ǿ���˫���Ҳ��Ǹ����
		{
			printf("������˫�׵ķǸ����%d\n", T[i]);
			return ERROR;
		}
		i++;
	}
	while(i<MAX_TREE_SIZE)
	{
		T[i] = Nil;		//��ֵ����T����Ľ��
		i++;
	}
	return OK;
}

//����TΪ����, ����true, ���򷵻�false;
Status EmptyBiTree(SqBiTree T)
{
	if (T[0] == Nil)
		return TRUE;
	else
		return FALSE;
}

//������T�����;
Status DepthBiTree(SqBiTree T)
{
	int i, j=-1;
	for(i=MAX_TREE_SIZE-1; i>=0; i--)	//�ҵ����1�����
		if (T[i] != Nil)
			break;
	i++;		//�õ�������
	do{
		j++;
	}while(i>=pow(2, j));	
	return j;
}

//������T�ĸ����;
Status Root(SqBiTree T, TElemType *e)
{
	if (EmptyBiTree(T))
		return ERROR;
	else
	{
		*e = T[0];
		return OK;
	}
}

//����cur_e����ֵ;
TElemType Value(SqBiTree T, Position e)
{
	return T[(int)powl(2, e.level-1)+e.order-2];
	//�������ĵ�i������2^(i-1)�����, ��ͬ�ڵ�i���1������±�
	//Ȼ��order-2�Եõ�����Ӧ���±�ֵ
}

//�����cur_e��ֵΪvalue;
Status Assign(SqBiTree T, Position e, TElemType value)
{
	int i = (int)powl(2, e.level-1)+e.order-2;		//�õ�����±�ֵ
	if(value!=Nil && T[(i+1)/2-1]==Nil)			//��Ҷ�Ӹ��ǿ�ֵ��˫��Ϊ��
		return ERROR;
	else if(value==Nil && (T[i*2+1]!=Nil || T[i*2+2]!=Nil))	//��˫�׸���ֵ����Ҷ��
		return ERROR;
	T[i] = value;
	
	return OK;
}

//��cur_eΪ�Ǹ����, �򷵻���˫��;
TElemType Parent(SqBiTree T, TElemType e)
{
	int i;
	if(T[0] == Nil)		//����
		return ERROR;
	for(i=1; i<=MAX_TREE_SIZE-1; i++)
		if(T[i] == e)	//�ҵ�e
			return T[(i+1)/2-1];
	return FALSE;		//û�ҵ�e
}

//����e������;
TElemType LeftChild(SqBiTree T, TElemType e)
{
	int i;
	if(T[0] == Nil)
		return ERROR;
	for(i=1; i<=MAX_TREE_SIZE-1; i++)
		if(T[i] == e)
			return T[i*2+1];
	return FALSE;
}

//����e���Һ���;
TElemType RightChild(SqBiTree T, TElemType e)
{
	int i;
	if(T[0] == Nil)
		return ERROR;
	for(i=1; i<=MAX_TREE_SIZE-1; i++)
		if(T[i] == e)
			return T[i*2+2];
	return FALSE;
}

//����e�����ֵ�;
TElemType LeftSibling(SqBiTree T, TElemType e)
{
	int i;
	if(T[0] == Nil)
		return ERROR;
	for(i=1; i<=MAX_TREE_SIZE-1; i++)
		if(T[i]==e && i%2==0)		//�ҵ�e�������Ϊż��(Ϊ�Һ���)
			return T[i-1];
	return FALSE;
}

//����e�����ֵ�;
TElemType RightSibling(SqBiTree T, TElemType e)
{
	int i;
	if(T[0] == Nil)
		return ERROR;
	for(i=1; i<=MAX_TREE_SIZE-1; i++)
		if(T[i]==e && i%2)		//�ҵ�e�������Ϊ����(Ϊ����)
			return T[i+1];
	return FALSE;
}

//PreOrderTraverse()����
void PreTraverse(SqBiTree T, int e)
{
	visit(T[e]);
	if(T[2*e+1] != Nil)		//�������ǿ�
		PreTraverse(T, 2*e+1);
	if(T[2*e+2] != Nil)		//�������ǿ�
		PreTraverse(T, 2*e+2);
}

//ǰ�����, ��---��---��;
Status PreOrderTraverse(SqBiTree T)
{
	if(!EmptyBiTree(T))		//���ǿ�
		PreTraverse(T, 0);
	printf("\n");
	return OK;
}

//InOrderTraverse()����
void InTraverse(SqBiTree T, int e)
{
	if(T[2*e+1] != Nil)		//�������ǿ�
		InTraverse(T, 2*e+1);
	visit(T[e]);			//�ȱ���������������
	if(T[2*e+2] != Nil)		//�������ǿ�
		InTraverse(T, 2*e+2);
}

//�������, ��---��---��;
Status InOrderTraverse(SqBiTree T)
{
	if(!EmptyBiTree(T))		//���ǿ�
		InTraverse(T, 0);
	printf("\n");
	return OK;
}

//PostOrderTraverse()����
void PostTraverse(SqBiTree T, int e)
{
	if(T[2*e+1] != Nil)		//�������ǿ�
		PostTraverse(T, 2*e+1);
	if(T[2*e+2] != Nil)		//�������ǿ�
		PostTraverse(T, 2*e+2);
	visit(T[e]);			//
}

//�������, ��---��---��;
Status PostOrderTraverse(SqBiTree T)
{
	if(!EmptyBiTree(T))		//���ǿ�
		PostTraverse(T, 0);
	printf("\n");
	return OK;
}

//�������, �Ը���㿪ʼ���϶���������;
Status LevelOrderTraverse(SqBiTree T)
{
	int i = MAX_TREE_SIZE-1, j;
	while(T[i] == Nil)
		i--;				//�ҵ����һ���ǿս��
	for(j=0; j<=i; j++)
		if(T[j] != Nil)		//ֻ�����ǿս��
			visit(T[j]);
	printf("\n");
	return OK;
}

//���, ������������������;
Status Print(SqBiTree T)
{
	int j, k;
	Position p;
	TElemType e;
	for(j=1; j<=DepthBiTree(T); j++)
	{
		printf("��%d��: ", j);
		for(k=1; k<=powl(2, j-1); k++)
		{
			p.level = j;
			p.order = k;
			e = Value(T, p);
			if(e != Nil)
				printf("��%d��: %d ", k, e);
		}
		printf("\n");
	}
	return OK;
}

int main(void)
{
	Status i;
	Position p;
	TElemType e;
	SqBiTree T;
	
	CreateBiTree(T);
	printf("����һ��������, �Ƿ�Ϊ��: %d (1:�� 0:��)\n", EmptyBiTree(T));
	printf("�������Ϊ: %d\n", DepthBiTree(T));
	i = Root(T, &e);
	if(i)
		printf("�������ĸ�Ϊ: %d\n", e);
	else
		printf("����, �޸�\n");
	printf("�������������: \n");
	LevelOrderTraverse(T);
	printf("ǰ�����������: \n");
	PreOrderTraverse(T);
	printf("�������������: \n");
	InOrderTraverse(T);
	printf("�������������: \n");
	PostOrderTraverse(T);
	printf("�޸ĵ�%d��, �������Ϊ%d�Ľ��", 3, 2);
	p.level = 3;
	p.order = 2;
	e = Value(T, p);
	printf("���޸Ľ��ԭֵΪ: %d and������ֵ: ", e);
	scanf("%d", &e);
	Assign(T, p, e);
	printf("��ʱ, �������������: \n");
	LevelOrderTraverse(T);
	printf("ǰ�����������: \n");
	PreOrderTraverse(T);
	printf("\n");
	
	printf("���%d��˫��Ϊ%d\n", e, Parent(T, e));
	printf("����Ϊ: %d, �Һ���Ϊ: %d\n", LeftChild(T, e), RightChild(T, e));
	printf("���ֵ�Ϊ: %d, ���ֵ�Ϊ: %d\n", LeftSibling(T, e), RightSibling(T, e));
	ClearBiTree(T);
	printf("��ն�������, �Ƿ�Ϊ��: %d (1:�� 0:��)\n", EmptyBiTree(T));
	printf("��ʱ, �������Ϊ: %d\n", DepthBiTree(T));
	i = Root(T, &e);
	if(i)
		printf("�������ĸ�Ϊ: %d\n", e);
	else
		printf("����, �޸�\n");
	
	return 0;
}










