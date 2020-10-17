#include"Graph.h"
#include"Queue.h"
#include<stdlib.h>

/*
Function:  Creat an undirected graph
Args:
*G:    Pointer to a gragh
*ver:  An array of vertex value
*edge: An array of edges
Description: Construct a graph which is stored in the form of an adjacency list
*/
void creatGraph(Graph* G, VertexType ver[], VertexType edge[][2])
{
	int indexl, indexr;
	ENode *tempnode1, *tempnode2, *findnul;
	G->vexnum = MAXVER;
	G->edgenum = MAXEDG;
	for (int i = 0; i < (G->vexnum); ++i)
	{
		G->vertexs[i].val = ver[i];
		G->vertexs[i].first_edge = NULL;
	}
	for (int i = 0; i < (G->edgenum); ++i)
	{
		indexl = edge[i][0] - 'A';
		indexr = edge[i][1] - 'A';
		tempnode1 = (ENode*)malloc(sizeof(ENode));
		tempnode1->v_id = indexr;
		tempnode1->next_edge = NULL;
		if (G->vertexs[indexl].first_edge == NULL)
		{
			G->vertexs[indexl].first_edge = tempnode1;
		}
		else
		{
			findnul = G->vertexs[indexl].first_edge;
			while (findnul->next_edge != NULL)
			{
				findnul = findnul->next_edge;
			}
			findnul->next_edge = tempnode1;
		}
		tempnode2 = (ENode*)malloc(sizeof(ENode));
		tempnode2->v_id = indexl;
		tempnode2->next_edge = NULL;
		if (G->vertexs[indexr].first_edge == NULL)
		{
			G->vertexs[indexr].first_edge = tempnode2;
		}
		else
		{
			findnul = G->vertexs[indexr].first_edge;
			while (findnul->next_edge != NULL)
			{
				findnul = findnul->next_edge;
			}
			findnul->next_edge = tempnode2;
		}
	}
}

/*
Function:    Tranverse the graph Depth-first
Args:
*G:      Pointer to a gragh
*k:      Current index of vertex node
*_visit: An array helping judging whether the vertex is visited
*ret:    An array storing the vertexs in Depth-first consequence
Description: None
*/
//全连接图可以不用循环
void DFS(Graph* G, int k, int* _visit, char** ret)
{
	_visit[k] = true;
	*((*ret)) = G->vertexs[k].val;
	(*ret)++;
	ENode* temp = G->vertexs[k].first_edge;
	while (temp)
	{
		if ((_visit[temp->v_id])==false)
		{
			k = temp->v_id;
			DFS(G, k, _visit, &(*ret));
		}
		temp = temp->next_edge;
	}
}

/*
Function:    Tranverse the graph Breadth-first
Args:
*G:      Pointer to a gragh
*_visit: An array helping judging whether the vertex is visited
*ret:    An array storing the vertexs in Breadth-first consequence
Description: None
*/
void BFS(Graph* G, int* _visit, char res[])
{
	int ResI = 0;
	PQueue Q;
	Q = CreatQueue(MAXSIZE);
	int index = 0;
	if (_visit[0] == false)
	{
		_visit[0] = true;
		Insert(Q, G->vertexs[0].val);
		while (!Empty(Q))
		{
			Delete(Q, &res[ResI]);
			int ResInt = (int)(res[ResI] - 'A');
			ENode* index = G->vertexs[ResInt].first_edge;
			++ResI;
			while (index)
			{
				if (_visit[index->v_id] == false)
				{
					_visit[index->v_id] = true;
					Insert(Q, G->vertexs[index->v_id].val);
				}
				index = index->next_edge;
			}
		}
	}
	DestroyQueue(Q);
	free(Q);
}

/*
Function:    Destroy a graph
Args:
*G:      Pointer to a gragh
Description: None
*/
void DestroyGraph(Graph*G)
{
	ENode* tempnode;
	for (int i = 0; i < (G->vexnum); ++i)
	{
		if (G->vertexs[i].first_edge != NULL)
		{
			while ((G->vertexs[i].first_edge)->next_edge != NULL)
			{
				tempnode = G->vertexs[i].first_edge;
				G->vertexs[i].first_edge = (G->vertexs[i].first_edge)->next_edge;
				free(tempnode);
			}
			free(G->vertexs[i].first_edge);
			G->vertexs[i].first_edge = NULL;
		}
	}
}

/*
Function: Print adjacency list
Args:    G:  Pointer to a gragh
Description: None
*/
void Print(Graph*G)
{
	ENode* cur;
	int i;
	for (i = 0; i < MAXVER; ++i)
	{
		cur = G->vertexs[i].first_edge;
		printf("%c: ", G->vertexs[i].val);
		while (cur != NULL)
		{
			printf("%c ", G->vertexs[cur->v_id].val);
			cur = cur->next_edge;
		}
		printf("\n");
	}
}
