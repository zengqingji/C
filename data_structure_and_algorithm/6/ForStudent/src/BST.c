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
}

/*
Args:
* root: The root pointer of the BST

Description:
* Destroy root BST, free all the memory of root BST
*/
void DestoryBST(BST_P *root)
{
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
}

/*
Args:
* root: The root pointer of the BST

Description:
* visualize the MidOrderTraverse of root BST
*/
void MidOrderTraverse(BST_P root)
{
}
