# include <stdio.h>
# include <stdlib.h>
# include <string.h>

const int N = 20;

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
	char str[N];
	int x;
	stackinit();
	
	memset(str, 0, N);
	printf("Please type a post-fix expression of arithmatics:\n");
	while (scanf("%s", str) != EOF)
	{
		if (strcmp(str, "+") == 0)
		{
			x = pop() + pop();
			push(x);
		}
		else if (strcmp(str, "-") == 0)
		{
			x = pop();
			x = pop() - x;
			push(x);
		}
		else if (strcmp(str, "/") == 0)
		{
			x = pop();
			x = pop() / x;
			push(x);
		}
		else if (strcmp(str, "*") == 0)
		{
			x = pop() * pop();
			push(x);
		}
		else 
		{
			printf("input str = %s\n", str);
			x = atoi(str);
			
			push(x);
			printf("pushed x = %d \n", x);
		}
		memset(str, 0, N);
	}
	x = pop();
	printf ("x = %d\n", x);
}