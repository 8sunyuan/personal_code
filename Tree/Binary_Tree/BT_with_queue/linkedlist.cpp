
#include "linkedlist.h"


linkedlist::linkedlist()
{
	// creating an empty list
	pHead = NULL;
	printf("linkedlist constructor called \n");
	
	return;
}

linkedlist::~linkedlist()
{
	void* x;
	while (!isEmpty())
	{
		x = deletefront();
	}
}

// remove the node from front of the list
void* linkedlist::deletefront()
{
	struct node *x;
	void* k = NULL;
	
	if (!isEmpty())
	{
		x = pHead;
		k = x->key;
		
		pHead= pHead->next;
	}
	// free(x);
	
	return k;
}

void* linkedlist::deletelast()
{
	struct node *x = pHead;
	struct node *last = NULL;
	void* k = NULL;
	
	if(!isEmpty())
	{
		// List has only 1 node
		if (x->next == NULL)
		{
			k = x->key;
			free(x);
			pHead = NULL;
		}
		// At least 2 nodes in the list
		else
		{
			while (x->next->next != NULL)
			{
				// at least we have two nodes in the list
				x = x->next;
			}
			last = x->next;
			k = last->key;
			
			x->next = NULL;
			free(last);
		}
	}
	
	return k;
}

// Traverse list and print all node key values

void linkedlist::showlist()
{
	if (!isEmpty())
	{
		struct node *p = pHead;
		
		printf ("Here are the remaining nodes of the list: \n\n");
		while (p != NULL)
		{
			printf ("Node key = %d\n", (long)p->key);
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
void linkedlist::insertfront(void* v)
{

	struct node *x = (struct node *) malloc(sizeof(struct node));
	x->key = v;
	x->next = pHead;
	pHead = x;
	
	return;
}

int linkedlist::isEmpty()
{
	return (pHead == NULL);
}
