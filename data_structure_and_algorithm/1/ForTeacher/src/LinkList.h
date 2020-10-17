#pragma once
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node *next;
} Node;


_Bool CreateEmptyList(Node** head);

_Bool CreateList(DataType *addr, unsigned int n, Node** head);

_Bool DestroyList(Node *head);

_Bool ListInsert(Node *head, unsigned int index, DataType e);

_Bool ListDelete(Node *head, unsigned int index, DataType* e);
