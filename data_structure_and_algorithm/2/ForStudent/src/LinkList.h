#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "ball.h"
#define _Bool int
#define true 1
#define false 0

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

