#pragma once
#include<stdio.h>
#include<stdlib.h>
//#define QSort

#ifdef QSort
void Mysort(int *array, int left, int right);
#else
void Mysort(int *array, int *temp, int left, int right);
void MyMerge(int *array, int *temp, int left, int middle, int right);
#endif // QSort

