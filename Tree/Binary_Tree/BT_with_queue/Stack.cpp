
#include "Stack.h"

Stack::Stack()
{
	pList = new linkedlist;
}

Stack::~Stack()
{
	if (pList != NULL)
	{
		delete pList;
		pList = NULL;
	}
}
		
void Stack::push(void* v)
{
	pList->insertfront(v);
}
		
		
void* Stack::pop()
{
	void* k = pList->deletefront();
	
	return k;
}
		
void Stack::emptyStack()
{
	void* k;
	
	while (!isEmpty())
	{
		k = pop();
		printf("Stack pop: k = %d \n", k);
	}
	
	return;
}

int Stack::isEmpty()
{
	return ( pList->isEmpty() );
}

