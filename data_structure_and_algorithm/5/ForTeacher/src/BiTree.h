#pragma once
#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

typedef struct BinaryNode
{
	DataType data;
	struct BinaryNode *left;
	struct BinaryNode *right;
} BinaryNode, *BinaryTree;

BinaryTree CreateBinaryTreeFromPreOrderSequence(DataType **s);
void PreOrderTraversal(BinaryTree t, DataType **s);
void InOrderTraversal(BinaryTree t, DataType **s);
void PostOrderTraversal(BinaryTree t, DataType **s);
BinaryTree DestroyTree(BinaryTree *T);
