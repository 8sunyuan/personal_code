
#include "linkedlist.h"


linkedlist::linkedlist()
{
	// creating an empty list
	head = (struct node*) malloc(sizeof (struct node));
	head->key = 0;
	
	tail = (struct node*) malloc(sizeof (struct node));
	tail->next = tail;
	head->next = tail;
	
	printf("linkedlist constructor called \n");
	
	return;
}

linkedlist::~linkedlist()
{
	if (head != NULL)
	{
		free(head);
		head = NULL;
	}
	
	if(tail != NULL)
	{
		free(tail);
		tail = NULL;
	}
	
	printf("linkedlist destructor called ! \n");
	
}

// remove the node from front of the list
void linkedlist::deletefront()
{
	struct node *x;
	if (head->next != tail)
	{
		x = head->next;
		head->next = head->next->next;
	}
	printf("Deleted node with key=%d\n", x->key);
	free(x);
	
	return;
}

// Traverse list and print all node key values
void linkedlist::showlist()
{
	if (!isEmpty())
	{
		
		int z;
		struct node *p = head->next;
		
		printf ("Here are the remaining nodes of the list: \n\n");
		while (p->next != tail)
		{
			z = p->key;
			p = p->next;
			printf ("Node Key Value: %d\n", z);
		}
		printf ("Node Key Value: %d\n", p->key);
		
	}
	else
	{
		printf("List is empty\n");
	}
	
	return;
}

// insert a new node with key value of v after the node head
struct node* linkedlist::insertfront(int v)
{
	struct node *x;
	x = (struct node *) malloc(sizeof(struct node));
	x->key = v;
	x->next = head->next;
	head->next  = x;
	
	return x;
}

int linkedlist::isEmpty()
{
	return (head->next == tail);
}
