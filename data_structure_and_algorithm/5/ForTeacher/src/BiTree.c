#include "BiTree.h"

/*
Args:
* s:the string of preorder traversal sequence.

for example:
if you want to obtain an element of s,you can write the code:
DataType data = *((*s));
if you want to obtain the second element of s,you can write the code:
(*s)++;
DataType data = *((*s));

Return:
* Pointer of the bitree node.
Description:
* Create a bitree from preorder traversal sequence.
*/
BinaryTree CreateBinaryTreeFromPreOrderSequence(DataType **s)
{
	BinaryTree BiTree = NULL;
	DataType data = *((*s));
	if (data == '\0') { return BiTree; }
	else if (data == '*')
	{
		BiTree = (BinaryTree)malloc(sizeof(BinaryNode));
		BiTree->data = data;
		(*s)++;
		BiTree->left = NULL;
		BiTree->right = NULL;
	}
	else
	{
		BiTree = (BinaryTree)malloc(sizeof(BinaryNode));
		BiTree->data = data;
		(*s)++;
		BiTree->left = CreateBinaryTreeFromPreOrderSequence(&(*s));
		BiTree->right = CreateBinaryTreeFromPreOrderSequence(&(*s));
	}
	return BiTree;
}

/*
Args:
* t:the pointer of the bitree.
* s:the string of preorder traversal sequence you returned.
Return:
* None.
Description:
* return preorder traversal sequence of the bitree.
*/
void PreOrderTraversal(BinaryTree t, DataType **s)
{
	if (t!=NULL)
	{
		*((*s)) = t->data;
		(*s)++;
		PreOrderTraversal(t->left, &(*s));
		PreOrderTraversal(t->right, &(*s));
	}
}

/*
Args:
* t:the pointer of the bitree.
* s:the string of ineorder traversal sequence you returned.
Return:
* None.
Description:
* return inorder traversal sequence of the bitree.
*/
void InOrderTraversal(BinaryTree t, DataType **s)
{
	if (t!=NULL)
	{
		InOrderTraversal(t->left, &(*s));
		*((*s)) = t->data;
		(*s)++;
		InOrderTraversal(t->right, &(*s));
	}

}

/*
Args:
* t:the pointer of the bitree.
* s:the string of postorder traversal sequence you returned.
Return:
* None.
Description:
* return postorder traversal sequence of the bitree.
*/
void PostOrderTraversal(BinaryTree t, DataType **s)
{
	if (t!=NULL)
	{
		PostOrderTraversal(t->left,&(*s));
		PostOrderTraversal(t->right,&(*s));
		*((*s)) = t->data;
		(*s)++;
	}
}

/*
Args:
* head: pointer of the bitree.
Returns:
* None
Description:
* Destroy the bitree.
* Release all allocated memory.
*/
//不能传指针的副本，那还是传值
BinaryTree DestroyTree(BinaryTree *T)
{
	if ((*T)!=NULL)
	{
		DestroyTree(&((*T)->left));
		DestroyTree(&((*T)->right));
		(*T) = NULL;
	}
	return (*T);
}