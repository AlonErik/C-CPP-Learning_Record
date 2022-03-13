//��ʾ���̵�����ͼ, �����ʾʱ��, ����ʾ�, Ȩֵ��ʾ����ʱ��, AOE��;
//·���ϸ����������ʱ��֮��: ·������;
//��Դ�㵽��������󳤶�·��: �ؼ�·��, �����ϵĻ�йؼ��;
#include<stdio.h>    
#include<stdlib.h>   
#include<math.h>  
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 30
#define MAXEDGE 30
#define GRAPH_INFINITY 65535

typedef int Status;
int *etv, *ltv;		//�¼����緢��ʱ�����ٷ���ʱ������
int *stack2;		//�洢���˽ṹ���е�ջ
int top2;			//ջָ���±�

typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef struct EdgeNode		//�߱���
{
	int adjvex;			//�ڽӵ���, �洢�ý���Ӧ�±�
	int weight;			//�洢Ȩֵ
	struct EdgeNode *next;	//����, ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode	//�������
{
	int in;		//���
	int data;	//������, �洢������Ϣ
	EdgeNode *firstedge;	//�߱�ͷ���
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

//����ͼ;
Status CreateMGraph(MGraph *G)
{
	int i, j;
	G->numVertexes = 10;
	G->numEdges = 13;
	
	for(i=0; i<G->numVertexes; i++)
		G->vexs[i] = i;
	for(i=0; i<G->numVertexes; i++)
	{
		for(j=0; j<G->numVertexes; j++)
			G->arc[i][j] = 0;
	}
	G->arc[0][1]=3;
	G->arc[0][2]=4; 
	G->arc[1][3]=5; 
	G->arc[1][4]=6; 
	G->arc[2][3]=8; 
	G->arc[2][5]=7; 
	G->arc[3][4]=3;
	G->arc[4][6]=9; 
	G->arc[4][7]=4;
	G->arc[5][7]=6; 
	G->arc[6][9]=2;
	G->arc[7][8]=5;
	G->arc[8][9]=3;
	
	return OK;
}

//�����ڽӾ��󹹽��ڽӱ�;
Status CreateALGraph(MGraph G, GraphAdjList *GL)
{
	int i, j;
	EdgeNode *e;
	*GL = (GraphAdjList)malloc(sizeof(graphAdjList));
	(*GL)->numVertexes = G.numVertexes;
	(*GL)->numEdges = G.numEdges;
	for(i=0; i<G.numVertexes; i++)		//���������
	{
		(*GL)->adjList[i].in = 0;
		(*GL)->adjList[i].data = G.vexs[i];
		(*GL)->adjList[i].firstedge = NULL;
	}
	for(i=0; i<G.numVertexes; i++)		//�����߱�
	{
		for(j=0; j<G.numVertexes; j++)
		{
			if(G.arc[i][j]!=0 && G.arc[i][j]<GRAPH_INFINITY)
			{
				e = (EdgeNode *)malloc(sizeof(EdgeNode));
				e->adjvex = j;			//�ڽ����Ϊ1
				e->next = (*GL)->adjList[i].firstedge;
				(*GL)->adjList[i].firstedge = e;
				(*GL)->adjList[j].in++;
			}
		}
	}
	return OK;
}

Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;		//ջָ���±�
	int count = 0;		//ͳ���������ĸ���
	int *stack;			//��ջ�����Ϊ0�Ķ�����ջ
	stack = (int*)malloc(GL->numVertexes *sizeof(int));
	
	for(i=0; i<GL->numVertexes; i++)
		if(0 == GL->adjList[i].in)		//���Ϊ0�Ķ�����ջ
			stack[++top] = i;
	top2 = 0;
	etv = (int*)malloc(GL->numVertexes *sizeof(int));
	for(i=0; i<GL->numVertexes; i++)
		etv[i] = 0;
	stack2 = (int*)malloc(GL->numVertexes *sizeof(int));
	
	printf("TopologicalSort:\t");
	while(top!=0)
	{
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		count++;
		
		stack2[++top2] = gettop;	//�������Ķ������ѹ���������е�ջ
		for(e=GL->adjList[gettop].firstedge; e; e=e->next)
		{
			k = e->adjvex;
			if(!(--GL->adjList[k].in))	//��i�Ŷ�����ڽӵ�����-1, ��-1��Ϊ0, ����ջ
				stack[++top] = k;
			if((etv[gettop]+e->weight)>etv[k])
				etv[k] = etv[gettop]+e->weight;
		}
	}
	return OK;
}

//��ؼ�·��, GLΪ������, ���G�ĸ���ؼ��;
Status CriticalPath(GraphAdjList GL)
{
	EdgeNode *e;
	int i, j, k, gettop;
	int ete, lte;			//����緢������ٷ�����ʱ��
	TopologicalSort(GL);	//��������etv��stack2��ֵ
	ltv = (int *)malloc(GL->numVertexes *sizeof(int));
	for(i=0; i<GL->numVertexes; i++)
		ltv[i] = etv[GL->numVertexes-1];
	
	printf("etv:\n");
	for(i=0; i<GL->numVertexes; i++)
		printf("%d -> ", etv[i]);
	printf("\n");
	
	while(top2!=0)		//��ջ����ltv
	{
		gettop = stack2[top2--];
		for(e=GL->adjList[gettop].firstedge; e; e=e->next)	//�������¼���ٷ���ʱ��ltv
		{
			k = e->adjvex;
			if(ltv[k]-e->weight < ltv[gettop])
				ltv[gettop] = ltv[k]-e->weight;
		}
	}
	printf("ltv:\n");
	for(i=0; i<GL->numVertexes; i++)
		printf("%d -> ", ltv[i]);
	printf("\n");
	
	for(j=0; j<GL->numVertexes; j++)
	{
		for(e=GL->adjList[j].firstedge; e; e=e->next)
		{
			k = e->adjvex;
			ete = etv[j];		//����緢��ʱ��
			lte = ltv[k]-e->weight;		//���ٷ���ʱ��
			if(ete==lte)
				printf("<v%d - v%d> length: %d \n", GL->adjList[j].data, GL->adjList[k].data, e->weight);
		}
	}
	return OK;
}

int main(void)
{    
	MGraph G;    
	GraphAdjList GL;    
	CreateMGraph(&G);
	CreateALGraph(G,&GL);
	CriticalPath(GL);
	
	return 0;
}
