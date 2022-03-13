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
	int arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
}MGraph;

Status CreateMGraph(MGraph *G)
{
	int i, j;
	G->numVertexes = 9;
	G->numEdges = 15;
	
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
	G->arc[0][1]=10;
	G->arc[0][5]=11; 
	G->arc[1][2]=18; 
	G->arc[1][8]=12; 
	G->arc[1][6]=16; 
	G->arc[2][8]=8; 
	G->arc[2][3]=22; 
	G->arc[3][8]=21; 
	G->arc[3][6]=24; 
	G->arc[3][7]=16;
	G->arc[3][4]=20;
	G->arc[4][7]=7; 
	G->arc[4][5]=26; 
	G->arc[5][6]=17; 
	G->arc[6][7]=19;
	for(i=0; i<G->numVertexes; i++)
	{
		for(j=i; j<G->numVertexes; j++)
		{
			G->arc[j][i] = G->arc[i][j];
		}
	}
	return OK;
}

//����ķPrim�㷨������С������;
Status MiniSpanTree_Prim(MGraph G)
{
	int min, i, j, k;
	int adjvex[MAXVEX];		//������صĶ����±�
	int lowcost[MAXVEX];	//���涥���ߵ�Ȩֵ
	lowcost[0] = 0;		//��ʼ����һ��ȨֵΪ0��v0����������
	adjvex[0] = 0;		//��ʼ����һ�������±�Ϊ0
	
	for(i=1; i<G.numVertexes; i++)	//ѭ���±�����ȫ������
	{
		lowcost[i] = G.arc[0][i];	//��v0��������ߵ�Ȩֵ�洢
		adjvex[i] = 0;
	}
	for(i=1; i<G.numVertexes; i++)
	{
		min = GRAPH_INFINITY;		//��ʼ����СȨֵΪ��
		j = 1;
		k = 0;
		while(j < G.numVertexes)
		{
			if(lowcost[j]!=0 && lowcost[j]<min)		//Ȩֵ�Ƚ�
			{
				min = lowcost[j];
				k = j;		//����ǰ��Сֵ���±����k
			}
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);			//��ӡ��ǰ�������Ȩֵ��С�ı�
		lowcost[k] = 0;		//����ǰ�����Ȩֵ����Ϊ0, ��ʾ���������
		for(j=1; j<G.numVertexes; j++)
		{	//�±�Ϊk�Ķ�����ߵ�ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
			if(lowcost[j]!=0 && G.arc[k][j]<lowcost[j])
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
	return OK;
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	MiniSpanTree_Prim(G);
	
	return 0;
}
