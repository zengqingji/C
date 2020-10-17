#include "AllSort.h"

//简单选择排序,任意排序皆可
void ChooseSort(vector<GamePoint> &array, int size) 
{
}

//打印函数
void PrintAll(GamePoint *array, int size) 
{
	for (int i = 0; i < size; ++i)
	{
		printf("%s %d\n", array[i]._idx, array[i]._point);
	}
}