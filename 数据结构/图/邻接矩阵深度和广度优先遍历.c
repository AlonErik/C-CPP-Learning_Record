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
	EdgeType arc[MAXSIZE][MAXSIZE];	//�ڽӾ���
	int numVertexes, numEdges;		//������, ����
}MGraph;

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
	if(Q.front == Q.rear)	//Ϊ�ձ�־
		return TRUE;
	else
		return FALSE;
}

//����δ��, �����eΪ�µĶ�βԪ��;
Status EnQueue(Queue *Q, int e)
{
	if((Q->rear+1)%MAXSIZE == Q->front)		//Ϊ����־
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE;			//�������ת��ͷ��
	
	return OK;
}

//���в���, ��ɾ����ͷԪ�ز���e����;
Status DeQueue(Queue *Q, int *e)
{
	if(Q->front == Q->rear)		//Ϊ�ձ�־
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;		//�������ת��ͷ��
	
	return OK;
}

//��ͼ;
Status CreateMGraph(MGraph *G)
{
	int i, j;
	G->numVertexes = 9;
	G->numEdges = 15;
	
	G->vexs[0]='A';
	G->vexs[1]='B';
	G->vexs[2]='C';
	G->vexs[3]='D';
	G->vexs[4]='E';
	G->vexs[5]='F';
	G->vexs[6]='G';
	G->vexs[7]='H';
	G->vexs[8]='I';
	
	for(i=0; i<G->numVertexes; i++)		//��ʼ��ͼ
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

//���ʱ�־������;
Boolean visited[MAXVEX];

//����Ż��ݹ��㷨;
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = TRUE;
	printf("%c ", G.vexs[i]);	//��ӡ����������������
	for(j=0; j<G.numVertexes; j++)
		if(G.arc[i][j]==1 && !visited[j])
			DFS(G, j);
}

//��ȱ���;
void DFSTraverse(MGraph G)
{
	int i;
	for(i=0; i<G.numVertexes; i++)
		visited[i] = FALSE;		//��ʼ�����ж��㶼��δ������
	for(i=0; i<G.numVertexes; i++)
		if(!visited[i])			//��δ���ʵĶ������DFS, ������ͨͼ, ִֻ��һ��
			DFS(G, i);
}

//��ȱ���;
void BFSTraverse(MGraph G)
{
	int i, j;
	Queue Q;
	for(i=0; i<G.numVertexes; i++)
		visited[i] = FALSE;
	InitQueue(&Q);			//��ʼ��1�����õĶ���
	for(i=0; i<G.numVertexes; i++)		//��ÿһ��������ѭ��
	{
		if(!visited[i])		//δ�����ʾͽ��д���
		{
			visited[i] = TRUE;
			printf("%c ", G.vexs[i]);	//��ӡ����/��������
			EnQueue(&Q, i);			//���˶��������
			while(!QueueEmpty(Q))		//����ǰ���зǿ�
			{
				DeQueue(&Q, &i);		//������Ԫ�س�����, ����i
				for(j=0; j<G.numVertexes; j++)
				{
					if(G.arc[i][j]==1 && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c ", G.vexs[j]);
						EnQueue(&Q, j);
					}
				}
			}
		}
	}
	
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	printf("\n��ȱ���: ");
	DFSTraverse(G);
	printf("\n��ȱ���: ");
	BFSTraverse(G);
	
	return 0;
}
