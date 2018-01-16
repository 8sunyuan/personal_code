
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
	int x = 0;
	while (!isEmpty())
	{
		x = deletefront();
	}
}

// remove the node from front of the list
int linkedlist::deletefront()
{
	struct node *x;
	int k = 0;
	
	if (!isEmpty())
	{
		x = pHead;
		k = x->key;
		
		pHead= pHead->next;
	}
	printf("Deleted node with key=%d\n", x->key);
	free(x);
	
	return k;
}

int linkedlist::deletelast()
{
	struct node *x = pHead;
	struct node *last = NULL;
	int k = 0;
	
	if(!isEmpty())
	{
		while (x->next->next != NULL)
		{
			x = x->next;
		}
		last = x->next;
		k = last->key;
		
		x->next = NULL;
		free(last);
	}
	
	return k;
}

// Traverse list and print all node key values
void linkedlist::showlist()
{
	if (!isEmpty())
	{
		int z;
		struct node *p = pHead;
		
		printf ("Here are the remaining nodes of the list: \n\n");
		while (p != NULL)
		{
			z = p->key;
			p = p->next;
			printf ("Node Key Value: %d\n", z);
		}
	}
	else
	{
		printf("List is empty\n");
	}
	
	return;
}

// insert a new node with key value of v after the node pHead
struct node* linkedlist::insertfront(int v)
{

	struct node *x;
	x = (struct node *) malloc(sizeof(struct node));
	x->key = v;
	x->next = pHead;
	pHead = x;
	
	return x;
}

int linkedlist::isEmpty()
{
	return (pHead == NULL);
}
