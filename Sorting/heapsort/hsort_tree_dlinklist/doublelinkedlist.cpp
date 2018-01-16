
#include "doublelinkedlist.h"


doublelinkedlist::doublelinkedlist()
{
	// creating an empty list
	pHead = NULL;
	pTail = NULL;
	printf("doublelinkedlist constructor called \n");
	
	return;
}

doublelinkedlist::~doublelinkedlist()
{
	while (!isEmpty())
	{
		deletefront();
	}
}

// remove the node from front of the list
void* doublelinkedlist::deletefront()
{
	struct node *first = pHead;
	struct node *second = NULL;
	void* k = NULL;
	
	if (!isEmpty())
	{
		// List has only 1 node
		if (pHead == pTail)
		{
			k = first->key;
			free(first);
			pHead = NULL;
			pTail = NULL;
		}
		// At least 2 nodes in the list
		else
		{
			k = first->key;
			second = first->next;
			second->prev = NULL;
			pHead = second;
			
			first->next = NULL;
			first->prev = NULL;
			free(first);
		}
	}
	return k;
}

void* doublelinkedlist::deletelast()
{
	struct node *last = pTail;
	struct node *sec_last = NULL;
	void* k = NULL;
	
	if(!isEmpty())
	{
		// List has only 1 node
		if (pHead == pTail)
		{
			k = last->key;
			free(last);
			pHead = NULL;
			pTail = NULL;
		}
		// At least 2 nodes in the list
		else
		{
			k = last->key;
			sec_last = last->prev;
			sec_last->next = NULL;
			pTail = sec_last;
			
			last->next = NULL;
			last->prev = NULL;
			free(last);
		}
	}
	return k;
}

// Traverse list and print all node key values

void doublelinkedlist::showlist()
{
	if (!isEmpty())
	{
		struct node *p = pHead;
		
		printf ("\nHere are the remaining nodes of the list: \n\n");
		while (p != NULL)
		{
			printf ("Node key = %d\n", ((BT_Node*)p->key)->data);
			p = p->next;
		}
	}
	else
	{
		printf("List is empty\n");
	}
	
	return;
}


// insert a new node with key value of v after the node pHead
void doublelinkedlist::insertfront(void* v)
{
	struct node *x = (struct node *) malloc(sizeof(struct node));
	if(isEmpty())
	{
		x->key = v;
		x->prev = NULL;
		x->next = NULL;
		pHead = x;
		pTail = x;
	}
	else
	{
		x->key = v;
		x->prev = NULL;
		x->next = pHead;
		pHead->prev = x;
		pHead = x;
	}
	
	// printf("insertfront: Node Key = %d \n", ((BT_Node*)v)->data);
	return;
}

void doublelinkedlist::insertlast(void* v)
{
	struct node *x = (struct node *) malloc(sizeof(struct node));
	if(isEmpty())
	{
		x->key = v;
		x->prev = NULL;
		x->next = NULL;
		pHead = x;
		pTail = x;
	}
	else
	{
		x->key = v;
		x->next = NULL;
		x->prev = pTail;
		pTail->next = x;
		pTail = x;
	}
	
	// printf("insertlast: Node Key = %d \n", ((BT_Node*)v)->data);
	return;
}

int doublelinkedlist::isEmpty()
{
	return (pHead == NULL);
}
