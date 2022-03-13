#include<stdio.h>    
#include<stdlib.h>   
#include<math.h>  
#include<time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100				//��󶥵���
#define GRAPH_INFINITY 65535	//������ʾ��

typedef int Status;			//�������״̬����
typedef char VertexType;	//��������
typedef int EdgeType;		//Ȩֵ����
typedef struct
{
	VertexType vexs[MAXVEX];		//�����
	EdgeType arc[MAXVEX][MAXVEX];	//�ڽӾ���, �ɿ����߱�
	int numNodes, numEdges;			//������, ����
}MGraph;

//����������ͼ���ڽӾ����ʾ;
Status CreateMGraph(MGraph *G)
{
	int i, j, k, w;
	printf("���붥�����ͱ���:\n");
	scanf("%d %d", &G->numNodes, &G->numEdges);
	for(i=0; i<G->numNodes; i++)	//���������
		scanf(&G->vexs[i]);
	for(i=0; i<G->numEdges; i++)	//�����߱�
		for(j=0; j<G->numEdges; j++)
			G->arc[i][j] = GRAPH_INFINITY;		//�ڽӾ����ʼ��
	for(k=0; k<G->numEdges; k++)	//����numEdges����, �����ڽӾ���
	{
		printf("�����(vi, vj)�ϵ��±�i, �±�j��Ȩw:\n");
		scanf("%d,%d,%d", &i, &j, &w);
		G->arc[i][j] = w;
		G->arc[j][i] = G->arc[i][j];	//����ͼ, ����Գ�	
	}
	return OK;
}

int main(void)
{
	MGraph G;
	CreateMGraph(&G);
	
	return 0;
}
