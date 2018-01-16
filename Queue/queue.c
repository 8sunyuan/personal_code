
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *next;
};

struct node *head;
struct node *tail;




void queueinit()
{
	// creating an empty queue
	head = (struct node *) malloc(sizeof (struct node));
	tail = (struct node *) malloc(sizeof (struct node));
	head->key = 0;
	head->next = tail;
	tail->next = tail;
	
	return;
}

// remove the node after t from the list
int pop()
{
	int x = 0;
	struct node *s = head;
	struct node *last = NULL;
	
	if (!isempty())
	{
		while (s->next->next != tail)
		{
			s = s->next;
		}
		last = s->next;
		x = s->next->key;
		
		s->next = s->next->next;
		free(last);
	}
	
	return x;
}

// Traverse list and print all node key values
void emptyqueue()
{
	int x;
	
	while (!isempty())
	{
		x = pop();
		printf ("queue Key Value: %d\n", x);
	}
	
	return;
}

// insert a new node with key value of v after the node t
void push(int v)
{
	struct node *x;
	x = (struct node *) malloc(sizeof(struct node));
	x->key = v;
	x->next  = head->next;
	head->next = x;
	
	return;
}

int isempty()
{
	return (head->next == tail);
}

void main()
{
	int x;
	queueinit();
     
	printf ("Please enter a queue item value: \n");
	while (scanf("%d", &x) != EOF)
	{
		push(x);
		printf ("Please enter the next item value: \n");
	}
	printf("exited loop\n");
	
	emptyqueue();
	
	return;
}
