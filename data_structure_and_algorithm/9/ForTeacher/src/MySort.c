#include "MySort.h"

#ifdef QSort
//¿ìËÙÅÅÐò
void Mysort(int *array, int left, int right)//ascending sort
{
	if (left>=right)
	{
		return;
	}
	int base = array[left];
	int index, fml, fmr;
	fml = left;
	fmr = right;
	while (fml<fmr)
	{
		while ((fml<fmr)&&(array[fmr]>=base))
		{
			--fmr;
		}
		array[fml] = array[fmr];
		while ((fml<fmr)&&(array[fml]<=base))
		{
			++fml;
		}
		array[fmr] = array[fml];
	}
	array[fml] = base;
	index = fml;
	Mysort(array, left, (index - 1));
	Mysort(array, (index + 1), right);
}
#else
//¹é²¢ÅÅÐò
void Mysort(int *array, int *temp, int left, int right)//ascending sort
{
	if (left>=right){ return; }
	int middle = (left + right) / 2;
	Mysort(array, temp, left, middle);
	Mysort(array, temp, (middle + 1), right);
	MyMerge(array, temp, left, middle, right);
}
void MyMerge(int *array, int *temp, int left, int middle, int right) 
{
	int leftIndex = left;
	int middleIndex = middle + 1;
	int tempIndex = left;
	while ((leftIndex<=middle)&&(middleIndex<=right))
	{
		if (array[leftIndex]<=array[middleIndex])
		{
			temp[tempIndex++] = array[leftIndex++];
		}
		else
		{
			temp[tempIndex++] = array[middleIndex++];
		}
	}
	while (leftIndex != (middle + 1))
	{
		temp[tempIndex++] = array[leftIndex++];
	}
	while (middleIndex != (right + 1))
	{
		temp[tempIndex++] = array[middleIndex++];
	}
	for (int i = left; i <= right; ++i)
	{
		array[i] = temp[i];
	}
}
#endif
