#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <crtdbg.h>//add this header file to detect memory leaks
#include"Graph.h"

//邻接表生成无向图
int main()
{
	int i;
	int visit[MAXVER] = { 0 };
	char v[MAXVER] = { 'A','B','C','D','E','F','G','H','I','J' };
	char e[MAXEDG][2] = { { 'A','B' },{ 'A','D' },{ 'A','E' },{ 'A','G' },\
	{'B','F'},{ 'C','F' },{ 'C','H' },{ 'C','J' },{ 'D','G' },\
	{'E','J'},{ 'G','H' },{ 'G','I' },{ 'I','J' } };
	char res[MAXVER] = { '0' };
	char *p = res;
	Graph Gra;
	creatGraph(&Gra, v, e);
	printf("Print  Adjacency table:\n");
	Print(&Gra);
	DFS(&Gra, 0, visit, &p);
	printf("\n");
	printf("DFS:\n");
	for (i = 0; i < MAXVER; i++)
	{
		printf("%c ", res[i]);
		visit[i] = 0;
	}
	printf("\n");
	BFS(&Gra, visit, res);
	printf("BFS:\n");
	for (i = 0; i < MAXVER; i++)
	{
		printf("%c ", res[i]);
	}
	printf("\n");
	DestroyGraph(&Gra);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("100!\n");
	}
	system("PAUSE");
	return 0;
}
