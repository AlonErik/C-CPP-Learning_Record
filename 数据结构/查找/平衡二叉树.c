//������������һ��, ����ÿ���������������������ĸ߶Ȳ��������1
//�������߶� - �������߶� = ƽ������BF (ֻ��Ϊ-1, 0, 1)
//����������������|ƽ������|>1�Ľ��Ϊ��������, ��Ϊ��С��ƽ������
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 	//�洢�ռ��ʼ������

#define LH +1	//���
#define EH 0	//�ȸ�
#define RH -1	//�Ҹ�
typedef int Status;

typedef struct BiTNode	//���ṹ
{
	int data;
	int bf;		//���ƽ������
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

//����PΪ���Ķ������������������� (ƽ������BF����1ʱ);
//�����Pָ���µ��������, ������ǰ���������ĸ����
void R_Rotate(BiTree *P)
{
	BiTree L;
	L = (*P)->lchild;		//Lָ��P�������������
	(*P)->lchild = L->rchild;	//L���������ӹ�ΪP��������
	L->rchild = (*P);		
	*P = L;					//Pָ���µĸ����
}

//����PΪ���Ķ������������������� (ƽ������BFС��-1ʱ);
//�����Pָ���µ��������, ������ǰ���������ĸ����
void L_Rotate(BiTree *P)
{
	BiTree R;
	R = (*P)->rchild;		//Rָ��P�������������
	(*P)->rchild = R->lchild;	//R���������ӹ�ΪP��������
	R->lchild = (*P);
	*P = R;					//Pָ���µĸ����
}

//����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����;
void LeftBalance(BiTree *T)
{
	BiTree L, Lr;
	L = (*T)->lchild;		//Lָ��T�������������
	switch(L->bf)
	{	//���T����������ƽ���, ������Ӧ����
		case LH:			//�½�����T�����ӵ���������, ����������
			(*T)->bf = L->bf = EH;
			R_Rotate(T);
			break;
		case RH:			//�½�����T�����ӵ���������, ��˫������
			Lr = L->rchild;	//Lrָ��T�����ӵ���������
			switch(Lr->bf)
			{	//�޸�T������������ƽ������
				case LH:(*T)->bf = RH;
						L->bf = EH;
						break;
				case EH:(*T)->bf = EH;
						L->bf = EH;
						break;
				case RH:(*T)->bf = EH;
						L->bf = LH;
						break;
			}
			Lr->bf = EH;
			L_Rotate(&(*T)->lchild);	//��������������ƽ�⴦��
			R_Rotate(T);				//��T������ƽ�⴦��
	}
}

//����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����;
void RightBalance(BiTree *T)
{
	BiTree R, Rl;
	R = (*T)->lchild;		//Rָ��T�������������
	switch(R->bf)
	{	//���T����������ƽ���, ������Ӧ����
		case LH:			//�½�����T���Һ��ӵ���������, ����������
			(*T)->bf = R->bf = EH;
			L_Rotate(T);
			break;
		case RH:			//�½�����T�����ӵ���������, ��˫������
			Rl = R->lchild;	//Rlָ��T���Һ��ӵ���������
			switch(Rl->bf)
			{	//�޸�T������������ƽ������
				case RH:(*T)->bf = LH;
						R->bf = EH;
						break;
				case EH:(*T)->bf = EH;
						R->bf = EH;
						break;
				case LH:(*T)->bf = EH;
						R->bf = RH;
						break;
			}
			Rl->bf = EH;
			R_Rotate(&(*T)->rchild);	//��������������ƽ�⴦��
			L_Rotate(T);				//��T������ƽ�⴦��
	}
}

//��ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ��, �����eΪ����Ԫ�ص��½��;
//�������ʧ��, ����ƽ��ѡ����, ��������taller��ӳT�Ƿ񳤸�;
Status InsertAVL(BiTree *T, int e, Status *taller)
{
	if(!*T)
	{	//�����½��, taller����ΪTRUE
		*T = (BiTree)malloc(sizeof(BiTNode));
		(*T)->data = e;
		(*T)->lchild = (*T)->rchild = NULL;
		(*T)->bf = EH;
		*taller = TRUE;
	}
	else
	{
		if(e==(*T)->data)
		{	//�Ѵ�����ͬ����򲻲���
			*taller = FALSE;
			return FALSE;
		}
		if(e<(*T)->data)
		{	//������T���������н�������
			if(!InsertAVL(&(*T)->lchild, e, taller))	//δ����
				return FALSE;
			if(*taller)		//�Ѳ��뵽T����������������������
				switch((*T)->bf)		//���T��ƽ���
				{
					case LH:LeftBalance(T);
							*taller = FALSE;
							break;			//ԭ������������������, ������ƽ�⴦��
					case EH:(*T)->bf = LH;
							*taller = TRUE;
							break;			//ԭ�����������ȸ�, ���������������
					case RH:(*T)->bf = EH;
							*taller = FALSE;
							break;			//ԭ������������������, �����ȸ�
				}
		}
		else
		{	//������T���������н�������
			if(!InsertAVL(&(*T)->rchild, e, taller))	//δ����
				return FALSE;
			if(*taller)		//�Ѳ��뵽T����������������������
				switch((*T)->bf)		//���T��ƽ���
				{
					case LH:(*T)->bf = EH;
							*taller = FALSE;
							break;			//ԭ������������������, �����ȸ�
					case EH:(*T)->bf = RH;
							*taller = TRUE;
							break;			//ԭ�����������ȸ�, ���������������
					case RH:RightBalance(T);
							*taller = FALSE;
							break;			//ԭ������������������, ������ƽ�⴦��
				}
		}
	}
	return TRUE;
}

int main(void)
{
	int i;
	int a[10] = {3,2,1,4,5,6,7,10,9,8};
	BiTree T = NULL;
	Status taller;
	for(i=0; i<10; i++)
	{
		InsertAVL(&T, a[i], &taller);
	}
	return 0;
}
