#pragma once
#include<stdio.h>
#include<stdlib.h>
#define true 1;
#define false 0;
typedef int DataType;

typedef struct BST_Node
{
	DataType data;
	struct BST_Node *lchild;
	struct BST_Node *rchild;
}BST_T, *BST_P;

void CreateBST(BST_P *root, int *arr, int len);
void DestoryBST(BST_P *root);
_Bool InsertBSTNode(BST_P *root, DataType data);
_Bool DeleteBSTNode(BST_P *root, DataType data);
BST_P SearchBST(BST_P *root, DataType data);
BST_P SearchBSTF(BST_P *root, DataType data);
void MidOrderTraverse(BST_P root);
