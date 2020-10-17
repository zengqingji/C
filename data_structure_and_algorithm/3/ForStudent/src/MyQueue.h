#pragma once
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 11
#define true 1
#define false 0
typedef int DataType;

typedef struct queue
{
	DataType* base;
	int front;
	int rear;
	int maxsize;
}Queue, *PQueue;

PQueue CreatQueue(int maxsize);
void DestroyQueue(PQueue q);
_Bool Insert(PQueue q, DataType x);
_Bool Delete(PQueue q, DataType* x);
_Bool Empty(PQueue q);
_Bool Full(PQueue q);
int Length(PQueue q);
