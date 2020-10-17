#include "MySort.h"

#if 0
//ºÚµ•—°‘Ò≈≈–Ú
void Mysort(int *array, int size)//ascending sort
{
	int index, min;
	for (size_t i = 0; i < size; ++i)
	{
		index = i;
		min = array[i];
		for (size_t j = i + 1; j < size; ++j)
		{
			if (array[j]<min)
			{
				min = array[j];
				index = j;
			}
		}
		if (index != i)
		{
			array[index] = array[i];
			array[i] = min;
		}
	}
}
#endif

#if 0
//≤Â»Î≈≈–Ú
void Mysort(int *array, int size)//ascending sort
{
	int tmp;
	for (size_t i = 1; i < size; ++i)
	{
		tmp = array[i];
		size_t j = i - 1;
		while ((j >= 0) && (tmp<array[j]))
		{
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = tmp;
	}
}
#endif

#if 1
//√∞≈›≈≈–Ú
void Mysort(int *array, int size)//ascending sort
{
	int tmp;
	for (size_t i = 0; i < (size - 1); ++i)
	{
		for (size_t j = 0; j < (size - i - 1); ++j)
		{
			if (array[j]>array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
#endif

