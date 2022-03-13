#include<stdio.h>    
#include<stdlib.h>   
#include<math.h>  
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 20
#define MAXEDGE 20
#define GRAPH_INFINITY 65535	//������ʾ��

typedef int Status;
typedef struct
{
	int vexs[MAXVEX];
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

typedef int Patharc[MAXVEX];		//�洢���·���±�
typedef int ShortPathTable[MAXVEX];	//�洢���������·����Ȩֵ��

Status CreateMGraph(MGraph *G)
{
	int i, j;
	G->numVertexes = 9;
	G->numEdges = 15;
	
	for(i=0; i<G->numVertexes; i++)
		G->vexs[i] = i;
	for(i=0; i<G->numVertexes; i++)
	{
		for(j=0; j<G->numVertexes; j++)
		{
			if(i==j)
				G->arc[i][j] = 0;
			else
				G->arc[i][j] = G->arc[j][i] = GRAPH_INFINITY;
		}
	}
	G->arc[0][1]=1;
	G->arc[0][2]=5; 
	G->arc[1][2]=3; 
	G->arc[1][3]=7; 
	G->arc[1][4]=5; 
	G->arc[2][4]=1; 
	G->arc[2][5]=7; 
	G->arc[3][4]=2; 
	G->arc[3][6]=3; 
	G->arc[4][5]=3;
	G->arc[4][6]=6;
	G->arc[4][7]=9; 
	G->arc[5][7]=5; 
	G->arc[6][7]=2; 
	G->arc[6][8]=7;
	G->arc[7][8]=4;
	for(i=0; i<G->numVertexes; i++)
	{
		for(j=i; j<G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
	return OK;
}

//�Ͻ�˹����Dijkstra�㷨��������G��v0�����ඥ��v�����·��P[v]����Ȩ����D[v];
//P[v]��ֵΪǰ�������±�, D[v]Ϊv0��v�����·�����Ⱥ�;
Status ShortestPath_Dijkstra(MGraph G, int v0, Patharc *P, ShortPathTable *D)
{
	int v, w, k, min;
	int final[MAXVEX];		//final[j]=1��ʾ��ö���v0��vw�����·��
	for(v=0; v<G.numVertexes; v++)
	{
		final[v] = 0;		//ȫ�������ʼ��Ϊδ֪���·��״̬
		(*D)[v] = G.arc[v0][v];		//����v0�����ߵĶ������Ȩֵ
		(*P)[v] = -1;		//��ʼ��·����ֵPΪ1
	}
	(*D)[v0] = 0;			//v0��v0·��Ϊ0
	final[v0] = 1;			//v0��v0������
	
	for(v=1; v<G.numVertexes; v++)		//ѭ��, ÿ�����v0��v��������·��
	{
		min = GRAPH_INFINITY;			//��ʼ����̾���
		for(w=0; w<G.numVertexes; w++)
		{
			if(!final[w] && (*D)[w]<min)
			{
				k = w;
				min = (*D)[w];			//w������v0����
			}
		}
		final[k] = 1;		//��Ŀǰ�ҵ�������Ķ�����Ϊ1
		for(w=0; w<G.numVertexes; w++)	//������ǰ���·��������
		{	//����v�����·������������·������:
			if(!final[w] && (min+G.arc[k][w]<(*D)[w]))
			{
				(*D)[w] = min+G.arc[k][w];
				(*P)[w] = k;
			}
		}
	}
	return OK;
}

int main(void)
{
	int i, j, v0;
	MGraph G;
	Patharc P;
	ShortPathTable D;
	v0 = 0;
	
	CreateMGraph(&G);
	ShortestPath_Dijkstra(G, v0, &P, &D);
	printf("���·����������: \n");
	for(i=1; i<G.numVertexes; ++i)
	{
		printf("v%d - v%d : ", v0, i);
		j = i;
		while(P[j]!=-1)
		{
			printf("%d ", P[j]);
			j = P[j];
		}
		printf("\n");
	}
	printf("\nԭ�㵽����������·������Ϊ: \n");
	for(i=1; i<G.numVertexes; ++i)
		printf("v%d - v%d : %d \n", G.vexs[0], G.vexs[i], D[i]);
	return 0;
}
