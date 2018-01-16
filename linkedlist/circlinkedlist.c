
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

struct node* listinitialize(int v, struct node* t)
{
	// creating a circular list with one node only
	t = (struct node*) malloc(sizeof *t);
	t->key = 1;
	t->next = t;
	
	return t;
}

// remove the node after t from the list
void deletenext(struct node *t)
{
	struct node *x;
	
	x = t->next;
	printf("Deleted node with key=%d\n", x->key);
	
	t->next = t->next->next;
	free(x);
	
	return;
}

// Traverse list and print all node key values
void showlist(struct node *t)
{
	int z;
	struct node *p;
	p = (struct node*) malloc(sizeof *t);
	
	printf ("Here are the remaining nodes of the list: \n\n");
	p = t->next;
	while (t != p)
	{
		z = p->key;
		p = p->next;
		printf ("Node Key Value: %d\n", z);
	}
	printf ("Node Key Value: %d\n", t->key);
	
	return;
}

// insert a new node with key value of v after the node t
struct node *insertafter(int v, struct node *t)
{
	struct node *x;
	x = (struct node *) malloc(sizeof(struct node));
	x->key = v;
	x->next  = t->next;
	t->next = x;
	
	return x;
}

void main ()
{
	int i;
	int N;
	int M;
	
	struct node *t;
	struct node *x;
	printf("Please type two integars: \n");
	scanf("%d %d", &N, &M);
	
	// create the first node of the list
	t = listinitialize(1, t);
	
	// adding N-1 nodes, each with value N
	for (i = 2; i <= N; i++)
	{
		t = insertafter(i, t);
	}
	
	// M is number of nodes to delete
	if (M < N)
	{
		for (i = 1; i <= M; i++)
		{
			deletenext(t);
		}
	}
	// If there does not exist M nodes to remove then remove until one node left
	else
	{
		while (t != t->next)
		{
			deletenext(t);
		}
	}
	
	showlist(t);
	
	return;
}