#include "LinkList.h"

/*
Args:
* head:pointer of the head node.
Return:
* True or false.
Description:
* Create an empty linked list with a head node.
* The "next" field of the head node should point to NULL.
*/
_Bool CreateEmptyList(Node** head)
{
}


/*
Args:
* addr: pointer of an array.
* n: length of the array.
* head:pointer of the head node.
Return:
* True or false.
Description:
* Initialize a linked list with an array.
*/
_Bool CreateList(DataType *addr, unsigned int n, Node** head)
{
}


/*
Args:
* head: pointer of the head node.
Returns:
* True or false.
Description:
* Destroy the linked list.
* Release all allocated memory.
*/
_Bool DestroyList(Node *head)
{
}


/*
Args:
* head: pointer of the head node.
* index: index of the inserted data.
* data: the inserted data.
Returns:
* True or false.
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 0, 6), the linked
* list will be "head->6->3->5->2".
*/
_Bool ListInsert(Node *head, unsigned int index, DataType e)
{
}


/*
Args:
* head: pointer of the head node.
* index: index of the deleted data.
* e:The deleted data.
Returns:
Description:
*   If the linked list is "head->3->5->2",
* when you call (head, 2), the linked
* list will be "head->3->5".
*/
_Bool ListDelete(Node *head, unsigned int index, DataType* e)
{
}

