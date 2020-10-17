#include "BST.h"

/*
Args:
* root: The root pointer of the BST
arr: The pointer to a integer array
len: The length of the data, which needs to be stored in BST

Description:
* Create an BST with arr whose length is len
*/
void CreateBST(BST_P *root, int *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		InsertBSTNode(&(*root), arr[i]);
	}
}

/*
Args:
* root: The root pointer of the BST

Description:
* Destroy root BST, free all the memory of root BST
*/
void DestoryBST(BST_P *root)
{
	if ((*root)!=NULL)
	{
		DestoryBST(&((*root)->lchild));
		DestoryBST(&((*root)->rchild));
		free(*root);
		(*root) = NULL;
	}
}

/*
Args:
* root: The root pointer of the BST
data: The data you want to insert into BST

Description:
* Insert data into the root BST,return true.
* ATTENTION: If data already exist in BST, DO NOTIHNG and return false.
*/
_Bool InsertBSTNode(BST_P *root, DataType data)
{
	if ((*root)==NULL)
	{
		(*root) = (BST_P)malloc(sizeof(BST_T));
		(*root)->data = data;
		(*root)->lchild = NULL;
		(*root)->rchild = NULL;
		return true;
	}
	else if (((*root)->data) == data) { return false; }
	else if (((*root)->data) > data) { InsertBSTNode(&((*root)->lchild), data); }
	else if (((*root)->data) < data) { InsertBSTNode(&((*root)->rchild), data); }
}

/*
Args:
* root: The root pointer of the BST
data: The data you want to delete from BST

Description:
* Delete data from the root BST, and free the memory
* ATTENTION: If data doesn't exist in BST, DO NOTIHNG and return false.
*/
//要把父节点置为NULL，不能把另一个指向子节点的指针置为NULL
_Bool DeleteBSTNode(BST_P *root, DataType data)
{
	BST_P node = SearchBST(&(*root), data);
	BST_P nodef = SearchBSTF(&(*root), data);
	BST_P temp, tempUp;

	if (node == NULL) { return false; }
	else if ((node->lchild == NULL) && (node->rchild == NULL))
	{
		if (nodef->lchild == node)
		{
			free(node);
			nodef->lchild = NULL;
		}
		else if (nodef->rchild == node)
		{
			free(node);
			nodef->rchild = NULL;
		}
	}
	else if (((node)->lchild != NULL) && ((node)->rchild == NULL))
	{
		if (nodef->lchild == node)
		{
			nodef->lchild = node->lchild;
			free(node);
		}
		else if (nodef->rchild == node)
		{
			nodef->rchild = node->lchild;
			free(node);
		}
	}
	else if (((node)->lchild == NULL) && ((node)->rchild != NULL))
	{
		if (nodef->lchild == node)
		{
			nodef->lchild = node->rchild;
			free(node);
		}
		else if (nodef->rchild == node)
		{
			nodef->rchild = node->rchild;
			free(node);
		}
	}
	//删除节点有点烦
	else if (((node)->lchild != NULL) && ((node)->rchild != NULL))
	{
		tempUp = node;
		temp = node->lchild;
		while (temp->rchild)
		{
			tempUp = temp;
			temp = temp->rchild;
		}
		node->data = temp->data;
		if ((temp->lchild)==NULL)
		{
			tempUp->rchild = NULL;
			free(temp);
		}
		else
		{
			tempUp->rchild = temp->lchild;
			free(temp);
		}
		//if (node != tempUp) { node->rchild = temp->lchild; }
		//else { node->lchild = temp->lchild; }
		//free(temp);
		//tempUp->rchild = NULL;
	}
	return true;
}

/*
Args:
* root: The root pointer of the BST
data: The data you want to search

Description:
* Search data within the root BST, and return its BST pointer
* ATTENTION: If data doesn't exist in BST, return NULL.
*/
BST_P SearchBST(BST_P *root, DataType data)
{
	if ((*root) == NULL) { return NULL; }
	else if (((*root)->data) == data) { return (*root); }
	else if (((*root)->data) > data) { return SearchBST(&((*root)->lchild), data); }
	else if (((*root)->data) < data) { return SearchBST(&((*root)->rchild), data); }
}
BST_P SearchBSTF(BST_P *root, DataType data)
{
	if (((*root) == NULL) || (((*root)->data == data))) { return NULL; }
	else if (((*root)->lchild == NULL) && ((*root)->rchild == NULL)) { return NULL; }
	else if ((*root)->lchild == NULL)
	{
		if (((*root)->rchild->data) == data) { return (*root); }
		else { return SearchBSTF(&((*root)->rchild), data); }
	}
	else if ((*root)->rchild == NULL)
	{
		if (((*root)->lchild->data) == data) { return (*root); }
		else { return SearchBSTF(&((*root)->lchild), data); }
	}
	else if ((((*root)->lchild->data) == data)|| (((*root)->rchild->data) == data)) { return (*root); }
	else if (((*root)->lchild->data) > data) { return SearchBSTF(&((*root)->lchild), data); }
	else if (((*root)->rchild->data) < data) { return SearchBSTF(&((*root)->rchild), data); }
	else
	{
		if (SearchBSTF(&((*root)->lchild), data) == NULL) { return SearchBSTF(&((*root)->rchild), data); }
		else { return SearchBSTF(&((*root)->lchild), data); }
	}
}

/*
Args:
* root: The root pointer of the BST

Description:
* visualize the MidOrderTraverse of root BST
*/
void MidOrderTraverse(BST_P root)
{
	if (root != NULL)
	{
		MidOrderTraverse(root->lchild);
		printf("%d, ", root->data);
		MidOrderTraverse(root->rchild);
	}
}
