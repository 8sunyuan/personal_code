
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
		
void Stack::push(int v)
{
	pList->insertfront(v);
}
		
		
int Stack::pop()
{
	int k = pList->deletefront();
	
	return k;
}
		
void Stack::emptyStack()
{
	int k = 0;
	
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

