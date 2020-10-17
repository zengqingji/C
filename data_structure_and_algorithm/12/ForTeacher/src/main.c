#include "MyGraph.h"

int main() 
{
	DataType Map[MAXVER][MAXVER] = { { INT_MAX,10,5,INT_MAX,INT_MAX },{ INT_MAX,INT_MAX,2,1,INT_MAX },
	{ INT_MAX,3,INT_MAX,9,2 },{ INT_MAX,INT_MAX,INT_MAX,INT_MAX,4 },{ 7,INT_MAX,INT_MAX,6,INT_MAX } };
	MyGraph mygraph;
	CreateGraph(&mygraph, Map);
	printf("60!\n");
	Dijkstra(&mygraph);
	PrintDijkstra(&mygraph);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("80!\n");
	}
	DataType MapFull[MAXVER][MAXVER] = { { INT_MAX,2,6,4,INT_MAX },{ INT_MAX,INT_MAX,3,INT_MAX,INT_MAX },
	{ 7,INT_MAX,INT_MAX,1,INT_MAX },{ 5,INT_MAX,12,INT_MAX,INT_MAX },{ INT_MAX,INT_MAX,INT_MAX,INT_MAX,INT_MAX } };
	CreateGraph(&mygraph, MapFull);
	FloydWarshall(&mygraph);
	PrintFloydWarshall(&mygraph);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("100!\n");
	}
	system("PAUSE");
	return 0;
}