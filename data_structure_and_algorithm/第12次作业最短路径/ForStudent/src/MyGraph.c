#include "MyGraph.h"

//用数组初始化有向图，邻接矩阵建立有向有权重图
void CreateGraph(MyGraph* G, DataType(*MyMatrix)[MAXVER])
{
}

//Dijkstra算法求单源最短路径
void Dijkstra(MyGraph* G) 
{
}

//Floyd-Warshall算法求所有节点对最短路径
void FloydWarshall(MyGraph* G) 
{
}

//无需改动
void PrintDijkstra(MyGraph* G) 
{
	printf("带权重有向图邻接矩阵为：\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((G->_matrix[i][j] >= 1000) || (G->_matrix[i][j] <= (-1000)))
			{
				printf("∞ ");
			}
			else
			{
				printf("%d ", G->_matrix[i][j]);
			}
		}
		printf("\n");
	}
	printf("以V1为起点，每个顶点路径长度：\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		printf("V%d：%d \n", (i + 1), G->_vertex[i]._value);
	}
}

//无需改动
void PrintFloydWarshall(MyGraph* G)
{
	printf("带权重有向图邻接矩阵为：\n");
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			if ((G->_matrix[i][j] >= 1000) || (G->_matrix[i][j] <= (-1000)))
			{
				printf("∞ ");
			}
			else
			{
				printf("%d ", G->_matrix[i][j]);
			}
		}
		printf("\n");
	}
}