//������������ݽ���;
/*
B��ÿ�����ĺ������ɶ���2��, ��ÿ����㴦���Դ洢���Ԫ��;
��һ��ƽ��Ķ�·������, ������ĺ�����Ŀ��ΪB���Ľ�

B+�������ڷ�֧����е�Ԫ�ػ������ڸ÷�֧���λ�õ������������ٴ��г�;
ÿ��Ҷ�ӽ�㶼�ᱣ��1��ָ���1Ҷ�ӽ���ָ��
*/
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 	//�洢�ռ��ʼ������
#define m 3			//B���Ľ�
#define N 17		//Ԫ�ظ���
#define MAX 5		//�ַ�����󳤶�+1

typedef int Status;

typedef struct BTNode
{
	int keynum;		//����йؼ��ָ���, ������С
	struct BTNode *parent;		//ָ��˫�׽��
	struct Node		//�����������
	{
		int key;	//�ؼ�������
		struct BTNode *ptr;		//����ָ������
		int recptr;	//��¼ָ������
	}node[m+1];		//key, recptr��0�ŵ�Ԫ����
}BTNode, *BTree;	//B���Ľ�������

typedef struct
{
	BTNode *pt;		//ָ���ҵ��Ľ��
	int i;			//�ڽ���еĹؼ������
	int tag;		//��־: 1:���ҳɹ�, 0:����ʧ��
}Result;			//B���Ĳ��ҽ������

//��p->node[1~keunum].key�в���i, ʹ��p->node[i].key��K��p->node[i+1].key;
int Search(BTree p, int K)
{
	int j, i=0;
	for(j=1; j<=p->keynum; j++)
		if(p->node[j].key<=K)
			i = j;
	return i;
}

//��m��B��T�ϲ��ҹؼ���K, ���ؽ��(pt, i, tag);
//û�ҵ��򽫵���K�Ĺؼ��ֲ�����ָ��pt��ָ����е�i��i+1���ؼ���֮��
Result SearchBTree(BTree T, int K)
{
	BTree p =T, q = NULL;	//��ʼ��, pָ�������, qָ��p��˫��
	Status found = FALSE;
	int i = 0;
	Result r;
	while(p && !found)
	{
		i = Search(p, K);	//p->node[i].key��K<p->node[i+1].key
		if(i>0 && p->node[i].key==K)	//�ҵ�
			found = TRUE;
		else
		{
			q = p;
			p = p->node[i].ptr;
		}
	}
	r.i = i;
	if(found)	//���ҳɹ�
	{
		r.pt = p;
		r.tag= 1;
	}
	else		//����K�Ĳ���λ����Ϣ
	{
		r.pt = q;
		r.tag= 0;
	}
	return r;
}

//��r->key, r, ap�ֱ���뵽q->key[i+1], q->recptr[i+1], q->ptr[i+1]��;
void Insert(BTree *q, int i, int key, BTree ap)
{
	int j;
	for(j=(*q)->keynum; j>i; j--)		//�ճ�(*q)->node[i+1]
		(*q)->node[j+1] = (*q)->node[j];
	(*q)->node[i+1].key = key;
	(*q)->node[i+1].ptr = ap;
	(*q)->node[i+1].recptr = key;
	(*q)->keynum++;
}

//�����q�ֳ�2�����, ǰ1�뱣��, ��1�������½��ap;
void Split(BTree *q, BTree *ap)
{
	int s=(m+1)/2, i;
	*ap = (BTree)malloc(sizeof(BTNode));
	(*ap)->node[0].ptr = (*q)->node[s].ptr;		//��1������ap
	for(i=s+1; i<=m; i++)
	{
		(*ap)->node[i-s] = (*q)->node[i];
		if((*ap)->node[i-s].ptr)
		   (*ap)->node[i-s].ptr->parent = *ap;
	}
	(*ap)->keynum = m-s;
	(*ap)->parent = (*q)->parent;
	(*q)->keynum = s-1;			//ǰ1�뱣��, �޸�keynum
}

//���ɺ���Ϣ(T, r, ap)���µĸ����&T, ԭT��apΪ����ָ��;
void NewRoot(BTree *T, int key, BTree ap)
{
	BTree p;
	p = (BTree)malloc(sizeof(BTNode));
	p->node[0].ptr = *T;
	*T= p;
	if((*T)->node[0].ptr)
	   (*T)->node[0].ptr->parent = *T;
	(*T)->parent = NULL;
	(*T)->keynum = 1;
	(*T)->node[1].key = key;
	(*T)->node[1].recptr = key;
	(*T)->node[1].ptr = ap;
	if((*T)->node[1].ptr)
	   (*T)->node[1].ptr->parent = *T;
}

//��m��B��T�Ͻ��*q��key[i]��key[i+1]֮�����ؼ���K��ָ��r;
//��������, ����˫�������б�Ҫ�Ľ����ѵ���, ʹT����m��B��
void InsertBTree(BTree *T, int key, BTree q, int i)
{
	BTree ap = NULL;
	Status finished = FALSE;
	int s;
	int rx = key;
	while(q && !finished)
	{
		Insert(&q, i, rx, ap);	//��r->key, r, ap�ֱ���뵽q->key[i+1], q->recptr[i+1], q->ptr[i+1]��
		if(q->keynum<m)
			finished = TRUE;	//�������
		else
		{	//���ѽ��*q
			s = (m+1)/2;
			rx= q->node[s].recptr;
			Split(&q, &ap);		//��q->key[s+1~m], q->ptr[s~m], q->recptr[s+1~m]�����½��*ap
			q = q->parent;
			if(q)
				i = Search(q, key);		//��˫�׽��*q�в���rx->key�Ĳ���λ��
		}
	}
	if(!finished)		//T�ǿ���(����q��ʼֵΪNULL)�������ѷ���Ϊ���*q��*ap
		NewRoot(T, rx, ap);		//���ɺ���Ϣ(T, rx, ap)���µĸ����*T, ԭT��apΪ����ָ��
}

void Print(BTNode c, int i)
{
	printf("(%d)", c.node[i].key);
}

int main(void)
{
	int r[N]={22,16,41,58,8,11,12,16,17,22,23,31,41,52,58,59,61};
	BTree T=NULL;
	Result s;
	int i;
	for(i=0; i<N; i++)
	{
		s = SearchBTree(T,r[i]);
		if(!s.tag)
			InsertBTree(&T, r[i], s.pt, s.i);
	}
	printf("\n�������ؼ���: ");
	scanf("%d", &i);
	s = SearchBTree(T, i);
	if(s.tag)
		Print(*(s.pt), s.i);
	else
		printf("û�ҵ�");
	printf("\n");
	return 0;
}
