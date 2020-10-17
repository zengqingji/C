#include <stdio.h>
#include <assert.h>
#include <crtdbg.h>
#include "LinkList.h"

#define _CRTDBG_MAP_ALLOC


void PrintList(Node* head)
{
	Node *p = head->next;
	if (p == NULL) {
		printf("Empty List");
	}
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}


int main(int argc, char* argv[])
{
	Node *head = NULL, *p;
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int i;

	// If your code is compiled successfully, you will get 60.
	printf("60\n");

	// If you create an empty linked list successfully, you will get 70.
	CreateEmptyList(&head);
	//ListInsert(head, 0, 1);
	for (i = 0; i < 10; ++i) {
		ListInsert(head, 0, i);
	}

	p = head->next;
	for (i = 0; i < 10; ++i) {
		assert(p->data == array[9 - i]);
		p = p->next;
	}
	assert(p == NULL);
	DestroyList(head);
	printf("70\n");

	// If you initialize the linked list with an array successfully, you will get 80.
	CreateList(array, 10, &head);
	p = head->next;
	for (i = 0; i < 10; ++i) {
		assert(p->data == i);
		p = p->next;
	}
	assert(p == NULL);
	printf("80\n");

	// If your insert function is correct, you will get 90.
	for (i = 0; i < 10; ++i) {
		ListInsert(head, i, i + 10);
	}
	p = head->next;
	for (i = 0; i < 20; ++i) {
		if (i < 10) {
			assert(p->data == i + 10);
		}
		else {
			assert(p->data == i - 10);
		}
		p = p->next;
	}
	assert(p == NULL);
	printf("90\n");

	// If your delete function is correct, you will get 100.
	DataType temp;
	for (i = 19; i > 9; --i) {
		ListDelete(head, i, &temp);
		assert(temp == i - 10);
	}

	p = head->next;
	for (i = 0; i < 10; ++i) {
		assert(p->data == i + 10);
		p = p->next;
	}

	assert(p == NULL);
	DestroyList(head);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("100!\n");
	}
	system("PAUSE");
	return 0;
}
