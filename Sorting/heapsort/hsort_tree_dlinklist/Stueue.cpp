#include "Stueue.h"

Stueue::Stueue()
{
	pList = new doublelinkedlist;
}

Stueue::~Stueue()
{
	if (pList != NULL)
	{
		delete pList;
		pList = NULL;
	}
}

// remove the last node from the list
void* Stueue::deletelast()
{
	void * k = NULL;	
	k = pList->deletelast();
	
	return k;
}

void* Stueue::deletefront()
{
	void* k = pList->deletefront();
	
	return k;
}


// insert a new node with key value of v at fron of list
void Stueue::insertfront(void * v)
{
	pList->insertfront(v);
}

void Stueue::insertlast(void* v)
{
	pList->insertlast(v);
}

void Stueue::showlist()
{
	pList->showlist();
}

int Stueue::isEmpty()
{
	return (pList->isEmpty());
}

