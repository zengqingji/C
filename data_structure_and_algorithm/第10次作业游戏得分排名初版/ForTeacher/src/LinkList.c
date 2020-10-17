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
	(*head) = malloc(sizeof(Node));
	if ((*head) == NULL)
	{
		return false;
	}
	(*head)->next = NULL;
	return true;
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
	(*head) = malloc(sizeof(Node));
	if ((*head) == NULL)
	{
		return false;
	}
	(*head)->next = NULL;
	for (size_t i = 0; i < n; ++i)
	{
		ListInsert((*head), i, addr[i]);
	}
	return true;
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
	Node* p = NULL;
	while (head)
	{
		p = head->next;
		free(head);
		head = p;
	}
	free(p);
	if (p != NULL)
	{
		return false;
	}
	return true;
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
	Node* p = head;
	Node* q = malloc(sizeof(Node));
	q->data.x = e.x;
	q->data.y = e.y;
	q->data.c = e.c;
	while ((p) && (index != 0))
	{
		p = p->next;
		--index;
	}
	if (p == NULL) { return false; }
	q->next = p->next;
	p->next = q;
	return true;
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
	Node *p, *q;
	p = head;
	while (((p->next) != NULL) && (index != 0))
	{
		p = p->next;
		--index;
	}
	if (!(p->next))
	{
		return false;
	}
	q = p->next;
	p->next = p->next->next;
	*e = q->data;
	free(q);
	return true;
}