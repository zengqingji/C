#include"MyQueue.h"

/*
Args:
* Maxsize: The maxsize of the queue
Return:
* Pointer points to a Queue.
Description:
* Create an empty queue with capacity of MAXSIZE
*/
PQueue CreatQueue(int Maxsize)
{
	PQueue queue = (PQueue)malloc(sizeof(Queue));
	queue->maxsize = Maxsize;
	queue->front = 0;
	queue->rear = 0;
	queue->base = (DataType*)malloc(queue->maxsize * sizeof(DataType));
	return queue;
}

/*
Args:
* q:Pointer points to a queue
Return:
* None
Description:
* Destroy the queue you have created,or free the memory you allocated when you creat the queue.And let q->base=NULL.
*/
void DestroyQueue(PQueue q)
{
	free(q->base);
	q->base = NULL;
	q->front = q->rear = q->maxsize = 0;
}

/*
Args:
* q:Pointer points to a queue
Return:
* true of false,if you can't insert,you return fasle.Otherwise,you return true.
Description:
* If the queue is  4 5 6 and x=3, after Insert(Q,x),the queue is 4 5 6 3
*/
_Bool Insert(PQueue q, DataType x)
{
	if (Full(q) == true) { return false; }
	q->base[q->rear] = x;
	q->rear = (q->rear + 1) % (q->maxsize);
	return true;
}

/*
Args:
* q:Pointer points to a queue
* x:Pointer points to a memory which can store the number you delete
Return:
* If the queue is empty,return false.Otherwise, you should return true.
Description:
* If the queue is  4 5 6, after Delete(Q,x),the queue is 5 6 and x=4
*/
_Bool Delete(PQueue q, DataType* x)
{
	if (Empty(q) == true) { return false; }
	*x = q->base[q->front];
	q->front = (q->front + 1) % (q->maxsize);
	return true;
}

/*
Args:
* q:Pointer points to a queue
Return:
* If the queue is empty,return true.Otherwise, you should return false.
Description:None
*/
_Bool Empty(PQueue q)
{
	if ((q->front)==(q->rear)){ return true; }
	else{ return false; }
}

/*
Args:
* q:Pointer points to a queue
Return:
* If the queue is full,return true.Otherwise, you should return false.
Description:None
*/
_Bool Full(PQueue q)
{
	if (((q->rear+1)%(q->maxsize))==(q->front)){ return true; }
	else{ return false; }
}

/*
Args:
* q:Pointer points to a queue
Return:
* Return the number of data the queue has.
Description:Node
*/
int Length(PQueue q)
{
	return(((q->maxsize) + (q->rear) - (q->front)) % (q->maxsize));
}