#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

typedef struct
{
	char _idx[10];
	int _point;
}GamePoint;

void ChooseSort(vector<GamePoint> &array, int size);
void PrintAll(GamePoint *array, int size);