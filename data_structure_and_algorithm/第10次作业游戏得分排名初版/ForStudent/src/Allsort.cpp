#include "AllSort.h"

//��ѡ������,��������Կ�
void ChooseSort(vector<GamePoint> &array, int size) 
{
}

//��ӡ����
void PrintAll(GamePoint *array, int size) 
{
	for (int i = 0; i < size; ++i)
	{
		printf("%s %d\n", array[i]._idx, array[i]._point);
	}
}