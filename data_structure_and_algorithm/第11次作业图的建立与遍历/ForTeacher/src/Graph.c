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
}

/*
Function:    Destroy a graph
Args:
*G:      Pointer to a gragh
Description: None
*/
void DestroyGraph(Graph*G)
{
}

/*
Function: Print adjacency list
Args:    G:  Pointer to a gragh
Description: None
*/
void Print(Graph*G)
{
}
