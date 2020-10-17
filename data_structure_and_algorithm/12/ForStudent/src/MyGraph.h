#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <crtdbg.h>//add this header file to detect memory leaks

#define MAXVER 5
#define true 1
#define false 0

//���Բ���ע��Ϊ�˸��������˳��
enum MyVertex { V1 = 0, V2, V3, V4, V5 };
//Ȩ�����ͣ��˴�Ϊint
typedef int DataType;

typedef struct 
{
	_Bool _visit;
	DataType _value;
}MyVertex;

typedef struct
{
	int _vernum;
	MyVertex _vertex[MAXVER];
	DataType _matrix[MAXVER][MAXVER];
}MyGraph;

void CreateGraph(MyGraph* G, DataType(*MyMatrix)[MAXVER]);

void Dijkstra(MyGraph* G);

void FloydWarshall(MyGraph* G);

void PrintDijkstra(MyGraph* G);

void PrintFloydWarshall(MyGraph* G);

