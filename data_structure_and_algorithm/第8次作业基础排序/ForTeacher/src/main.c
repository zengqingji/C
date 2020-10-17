#include<assert.h>
#include<stdio.h>
//add this header file to detect memory leaks
#include <crtdbg.h>
#include <stdlib.h>
#include <time.h>
#include "MySort.h"

#define LONG_N 1000

int cmp(const void*a, const void*b)//ascending order
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int i;
	int array_long[LONG_N];
	int num = 10;
	clock_t start, stop;
	while (num--)
	{
		for (i = 0; i < LONG_N; ++i)
		{
			array_long[i] = (int)(rand());
		}
		int array_long_target[LONG_N];
		int array_long_test[LONG_N];
		memcpy(array_long_target, array_long, LONG_N * sizeof(int));
		memcpy(array_long_test, array_long, LONG_N * sizeof(int));
		start = clock();
		qsort(array_long_target, LONG_N, sizeof(int), cmp);
		stop = clock();
		printf("The time of standard qsort:%f\n", (double)(stop - start) / CLK_TCK);
		start = clock();
		Mysort(array_long_test, LONG_N);
		stop = clock();
		printf("The time of my qsort:%f\n", (double)(stop - start) / CLK_TCK);
		for (i = 0; i < LONG_N; ++i)
		{
			assert(array_long_test[i] == array_long_target[i]);
		}
	}
	printf("100!\n");
	_CrtDumpMemoryLeaks();
	system("PAUSE");
	return 0;
}
