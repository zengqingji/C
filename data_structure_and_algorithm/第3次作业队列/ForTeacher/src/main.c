#include"MyQueue.h"
#include<assert.h>
#include<stdio.h>
#include <crtdbg.h>//add this header file to detect memory leaks

int main(int argc, char*argv[])
{
	Queue* Q;
	int i;
	int n;
	int array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	printf("60\n");//If you compile successfully, you  will get 60!
	Q = CreatQueue(MAXSIZE);
	assert(Q->base != NULL&&Q->front == 0 && Q->rear == 0 && Q->maxsize == MAXSIZE);
	printf("70\n");//If you initialize the queue sucessfully, you  will get 70!
	for (i = 0; i<10; i++)
	{
		Insert(Q, array[i]);
	}
	assert(Length(Q) == 10);
	assert(Full(Q) == true);
	assert(Insert(Q, 10) == false);//The queue is full.If you insert a number,it will return fasle;
	printf("80\n");
	for (i = 0; i<10; i++)
	{
		if (Delete(Q, &n))
		{
			assert(n == i);
		}
	}
	assert(Empty(Q) == true);
	assert(Delete(Q, n) == false);//The queue is empty.If you delete a number,it will return fasle;
	for (i = 0; i<10; i++)
	{
		Insert(Q, array[i]);
	}
	assert(Q->front == 10 && Q->rear == 9);
	assert(Length(Q) == 10);
	for (i = 0; i<10; i++)
	{
		assert(Q->base[(Q->front + i) % Q->maxsize] == i);
	}
	printf("90\n");
	DestroyQueue(Q);
	assert(Q->base == NULL);
	free(Q);
	if (!_CrtDumpMemoryLeaks())
	{
		printf("100!\n");
	}
	system("PAUSE");
	return 0;
}
