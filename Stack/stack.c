
# include <stdio.h>
# include <stdlib.h>

struct node
{
	int key;
	struct node *next;
};

struct node *head;
struct node *z;
struct node *t;



void stackinit()
{
	// creating an empty stack
	head = (struct node *) malloc(sizeof *head);
	z = (struct node*) malloc(sizeof(struct node));
	head->key = 0;
	head->next = z;
	z->next = z;
	
	head = z;
	
	return;
}

// remove the node after t from the list
int pop()
{
	int x;
	t = head->next;
	head->next = t->next;
	x = t->key;
	free(t);
	return x;
}

// Traverse list and print all node key values
void emptystack()
{
	int x;
	
	while (!isempty())
	{
		x = pop();
		printf ("Stack Key Value: %d\n", x);
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
	return (head->next ==z);
}

void main()
{
	stackinit();
	int x;
	printf ("Please enter a Stack item value: \n");
	while (scanf("%d", &x) != EOF)
	{
		push(x);
		printf ("Please enter the next item value: \n");
	}
	emptystack();
	
	return;
}
