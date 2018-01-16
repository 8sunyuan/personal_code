#include "Queue.h"


Queue::Queue()
{
	pList = new linkedlist;
}

Queue::~Queue()
{
	if (pList != NULL)
	{
		delete pList;
		pList = NULL;
	}
}

// remove the last node from the list
int Queue::pop()
{
	int k = pList->deletelast();
	
	return k;
}

// Traverse list and print all node key values
void Queue::emptyQueue()
{
	int x;
	
	while (!isEmpty())
	{
		x = pop();
		printf ("queue Key Value: %d\n", x);
	}
	
	return;
}

// insert a new node with key value of v at fron of list
void Queue::push(int v)
{
	pList->insertfront(v);
}

int Queue::isEmpty()
{
	return (pList->isEmpty());
}
