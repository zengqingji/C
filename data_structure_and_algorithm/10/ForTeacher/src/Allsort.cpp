#include "AllSort.h"

//��ѡ������,��������Կ�
void ChooseSort(vector<GamePoint> &array, int size) 
{
	GamePoint temp;
	int index;
	for (int i = 0; i < size; ++i)
	{
		index = i;
		temp = array[i];
		for (size_t j = i + 1; j < size; ++j)
		{
			if (array[j]._point<temp._point)
			{
				temp = array[j];
				index = j;
			}
		}
		if (index != i)
		{
			array[index] = array[i];
			array[i] = temp;
		}
	}
}

//��ӡ����
void PrintAll(GamePoint *array, int size) 
{
	for (int i = 0; i < size; ++i)
	{
		printf("%s %d\n", array[i]._idx, array[i]._point);
	}
}