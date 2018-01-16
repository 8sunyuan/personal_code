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
void * Queue::pop()
{
	void * k = NULL;	
	k = pList->deletelast();
	
	return k;
}

// Traverse list and print all node key values
void Queue::emptyQueue()
{
	void* x = NULL;
	
	while (!isEmpty())
	{
		x = pop();
	}
	
	return;
}

// insert a new node with key value of v at fron of list
void Queue::push(void * v)
{
	pList->insertfront(v);
}

int Queue::isEmpty()
{
	return (pList->isEmpty());
}

void Queue::showlist()
{
	pList->showlist();
	return;
}
