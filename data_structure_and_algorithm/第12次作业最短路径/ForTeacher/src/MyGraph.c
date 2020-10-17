#include "MyGraph.h"

//用数组初始化有向图，邻接矩阵建立有向有权重图
void CreateGraph(MyGraph* G, DataType(*MyMatrix)[MAXVER])
{
	G->_vernum = MAXVER;
	for (int i = 0; i < MAXVER; ++i)
	{
		G->_vertex[i]._visit = false;
		G->_vertex[i]._value = INT_MAX;
	}
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			G->_matrix[i][j] = MyMatrix[i][j];
		}
	}
}

//Dijkstra算法求单源最短路径
void Dijkstra(MyGraph* G) 
{
	//从一个顶点先赋初值
	for (int i = 0; i < MAXVER; ++i)
	{
		G->_vertex[i]._value = G->_matrix[0][i];
	}
	G->_vertex[V1]._visit = true;
	G->_vertex[V1]._value = 0;
	int index = 1;
	while (index != MAXVER)
	{
		int temp = 0;
		int min = INT_MAX;
		for (int i = 0; i < MAXVER; ++i)
		{
			//从剩下的点里找最小值
			if ((G->_vertex[i]._visit == false) && (G->_matrix[0][i]<INT_MAX))
			{
				min = G->_matrix[0][i];
				temp = i;
			}
		}
		G->_vertex[temp]._visit = true;
		++index;
		for (int i = 0; i < MAXVER; ++i)
		{
			if ((G->_vertex[i]._visit == 0) && (G->_matrix[temp][i]<INT_MAX) && ((G->_vertex[temp]._value + G->_matrix[temp][i])<G->_vertex[i]._value))
			{
				G->_vertex[i]._value = G->_vertex[temp]._value + G->_matrix[temp][i];
			}
		}
	}
}

//Floyd-Warshall算法求所有节点对最短路径
void FloydWarshall(MyGraph* G) 
{
	for (int i = 0; i < MAXVER; ++i)
	{
		for (int j = 0; j < MAXVER; ++j)
		{
			for (int k = 0; k < MAXVER; ++k)
			{
				if ((G->_matrix[j][k])>(G->_matrix[j][i] + G->_matrix[i][k]) && (G->_matrix[j][i] != INT_MAX) && 
					(G->_matrix[i][k] != INT_MAX) && (j != k) && (k != i) && (i != j))
				{
					G->_matrix[j][k] = G->_matrix[j][i] + G->_matrix[i][k];
				}
			}
		}
	}
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