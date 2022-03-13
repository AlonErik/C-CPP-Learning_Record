#include<stdio.h>    
#include<stdlib.h>   
#include<math.h>  
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100				//��󶥵���

typedef int Status;			//�������״̬����
typedef char VertexType;	//��������
typedef int EdgeType;		//Ȩֵ����

typedef struct EdgeNode		//�߱���
{
	int adjvex;			//�ڽӵ���, �洢�ڽӵ��ڶ�����е��±�
	EdgeType info;		//�洢Ȩֵ
	struct EdgeNode *next;		//����, ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode	//�������
{
	VertexType data;		//������, �洢������Ϣ
	EdgeNode *firstedge;	//�߱�ͷָ��
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numNodes, numEdges;	//������, ����
}GraphAdjList;

//��������ͼ���ڽӱ��ʾ;
Status CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	printf("���붥�����ͱ���:\n");
	scanf("%d,%d", &G->numNodes, &G->numEdges);
	for(i=0; i<G->numNodes; i++)		//���������
	{
		scanf(&G->adjList[i].data);		//���붥����Ϣ
		G->adjList[i].firstedge = NULL;	//��Ϊ�ձ�
	}
	for(k=0; k<G->numEdges; k++)
	{
		printf("�����(vi, vj)�϶������:\n");
		scanf("%d,%d", &i, &j);
		e = (EdgeNode *)malloc(sizeof(EdgeNode));	//���ɱ߱���
		e->adjvex = j;		//�ڽ����Ϊ1
		e->next = G->adjList[i].firstedge;		//��e��ָ��ָ��ǰ����ָ��Ľ��
		G->adjList[i].firstedge = e;			//����ǰ�����ָ��ָ��e
		e = (EdgeNode *)malloc(sizeof(EdgeNode));	//���ɱ߱���
		e->adjvex = i;		//�ڽ����Ϊ1
		e->next = G->adjList[j].firstedge;		//��e��ָ��ָ��ǰ����ָ��Ľ��
		G->adjList[j].firstedge = e;			//����ǰ�����ָ��ָ��e
	}
	return OK;
}

int main(void)
{
	GraphAdjList G;
	CreateALGraph(&G);
	
	return 0;
}
