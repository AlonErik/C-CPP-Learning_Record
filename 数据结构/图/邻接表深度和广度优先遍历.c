#include<stdio.h>    
#include<stdlib.h>   
#include<math.h>  
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 9		//�洢�ռ��ʼ������
#define MAXEDGE 15
#define MAXVEX 9

typedef int Status;			//�������״̬����
typedef char VertexType;	//��������
typedef int EdgeType;		//Ȩֵ����
typedef int Boolean;		//�ж��Ƿ��ѱ�����

typedef struct
{
	VertexType vexs[MAXSIZE];		//�����
	EdgeType arc[MAXSIZE][MAXSIZE];	//�ڽӾ���, �ɿ����߱�
	int numVertexes, numEdges;		//������, ����
}MGraph;

//�ڽӱ�ṹ;
typedef struct EdgeNode		//�߱���
{
	int adjvex;			//�ڽӵ���, �洢�ý���Ӧ���±�
	int weight;			//�洢Ȩֵ
	struct EdgeNode *next;	//����, ָ����һ���ڽӵ�
}EdgeNode;

typedef struct VertexNode	//�������
{
	int in;				//�������
	char data;			//������, �洢������Ϣ
	struct EdgeNode *firstedge;		//�߱�ͷ���
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjlist;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

//ѭ�����е�˳��洢�ṹ;
typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
}Queue;

//��ʼ��1���ն���Q;
Status InitQueue(Queue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

//����QΪ��, ����true, ���򷵻�false;
Status QueueEmpty(Queue Q)
{
	if(Q.front==Q.rear)
		return TRUE;
	else
		return FALSE;
}

//����δ��, �����eΪ�µĶ�βԪ��;
Status EnQueue(Queue *Q, int e)
{
	if((Q->rear+1)%MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;
	
	return OK;
}

//���в���, ��ɾ����ͷԪ�ز���e����;
Status DeQueue(Queue *Q, int *e)
{
	if(Q->front==Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	
	return OK;
}

//��ͼ;
Status CreateMGraph(MGraph *G)
{
	int i, j;
	G->numVertexes=9;
	G->numEdges=15;
	
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';
	
	for(i=0; i<G->numVertexes; i++)
	{
		for(j=0; j<G->numVertexes; j++)
		{
			G->arc[i][j] = 0;
		}
	}
	G->arc[0][1]=1;
	G->arc[0][5]=1;
	G->arc[1][2]=1; 
	G->arc[1][8]=1; 
	G->arc[1][6]=1; 
	G->arc[2][3]=1; 
	G->arc[2][8]=1; 
	G->arc[3][4]=1;
	G->arc[3][7]=1;
	G->arc[3][6]=1;
	G->arc[3][8]=1;
	G->arc[4][5]=1;
	G->arc[4][7]=1;
	G->arc[5][6]=1; 
	G->arc[6][7]=1; 
	for(i=0; i<G->numVertexes; i++)
	{
		for(j=i; j<G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
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
		(*GL)->adjlist[i].in = 0;
		(*GL)->adjlist[i].data = G.vexs[i];
		(*GL)->adjlist[i].firstedge = NULL;		//�߱���Ϊ�ձ�
	}
	for(i=0; i<G.numVertexes; i++)		//�����߱�
	{
		for(j=G.numVertexes-1; j>=0; j--)
		{
			if(G.arc[i][j]==1)
			{
				e = (EdgeNode *)malloc(sizeof(EdgeNode));
				if(i==0 && j==8)
					e->adjvex = 6;
				else if(i==1 && j==6)
					e->adjvex = 8;
				else
					e->adjvex = j;		//�ڽ����Ϊj
				e->next = (*GL)->adjlist[i].firstedge;
				(*GL)->adjlist[i].firstedge = e;
				(*GL)->adjlist[j].in++;
			}
		}
	}
	return OK;
}

//���ʱ�־������;
Boolean visited[MAXVEX];

//����Ż��ݹ��㷨;
void DFS(GraphAdjList GL, int i)
{
	EdgeNode *p;
	visited[i] = TRUE;
	printf("%c ", GL->adjlist[i].data);
	p = GL->adjlist[i].firstedge;
	while(p)
	{
		if(!visited[p->adjvex])
			DFS(GL, p->adjvex);
		p = p->next;
	}
}

//��ȱ���;
void DFSTraverse(GraphAdjList GL)
{
	int i;
	for(i=0; i<GL->numVertexes; i++)
		visited[i] = FALSE;
	for(i=0; i<GL->numVertexes; i++)
		if(!visited[i])
			DFS(GL, i);
}

//��ȱ���;
void BFSTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode *p;
	Queue Q;
	for(i=0; i<GL->numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);
	for(i=0; i<GL->numVertexes; i++)
	{
		if(!visited[i])
		{
			visited[i] = TRUE;
			printf("%c ", GL->adjlist[i].data);
			EnQueue(&Q, i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = GL->adjlist[i].firstedge;
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = TRUE;
						printf("%c ", GL->adjlist[p->adjvex].data);
						EnQueue(&Q, p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}

int main(void)
{    
	MGraph G;  
	GraphAdjList GL;    
	CreateMGraph(&G);
	CreateALGraph(G,&GL);
	
	printf("\n��ȱ���:");
	DFSTraverse(GL);
	printf("\n��ȱ���:");
	BFSTraverse(GL);
	return 0;
}
