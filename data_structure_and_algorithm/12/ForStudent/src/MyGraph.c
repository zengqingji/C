#include "MyGraph.h"

//�������ʼ������ͼ���ڽӾ�����������Ȩ��ͼ
void CreateGraph(MyGraph* G, DataType(*MyMatrix)[MAXVER])
{
}

//Dijkstra�㷨��Դ���·��
void Dijkstra(MyGraph* G) 
{
}

//Floyd-Warshall�㷨�����нڵ�����·��
void FloydWarshall(MyGraph* G) 
{
}

//����Ķ�
void PrintDijkstra(MyGraph* G) 
{
	printf("��Ȩ������ͼ�ڽӾ���Ϊ��\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((G->_matrix[i][j] >= 1000) || (G->_matrix[i][j] <= (-1000)))
			{
				printf("�� ");
			}
			else
			{
				printf("%d ", G->_matrix[i][j]);
			}
		}
		printf("\n");
	}
	printf("��V1Ϊ��㣬ÿ������·�����ȣ�\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		printf("V%d��%d \n", (i + 1), G->_vertex[i]._value);
	}
}

//����Ķ�
void PrintFloydWarshall(MyGraph* G)
{
	printf("��Ȩ������ͼ�ڽӾ���Ϊ��\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((G->_matrix[i][j] >= 1000) || (G->_matrix[i][j] <= (-1000)))
			{
				printf("�� ");
			}
			else
			{
				printf("%d ", G->_matrix[i][j]);
			}
		}
		printf("\n");
	}
}