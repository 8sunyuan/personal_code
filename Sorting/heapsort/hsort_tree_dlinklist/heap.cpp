#include "heap.h"

Heap::Heap()
{
	pCurr = NULL;
	pRoot = NULL;
	new_node = NULL;
	pQueue = new Stueue;
	pStack = new Stueue;
}

Heap::~Heap()
{
	if (pQueue)
	{
		delete pQueue;
		pQueue = NULL;
	}
	if (pStack)
	{
		delete pStack;
		pStack = NULL;
	}
}
    
void Heap::Insert(int v)
{
   new_node = insert_horizontal(v);
   Upheap(new_node);
}

int Heap::Remove()
{
	int v = -1;
	if (!isEmpty())
	{
	   v = remove_root();
	   Downheap();
	}
	return v;
}

BT_Node *Heap::get_node() 
{
   BT_Node *temp = (BT_Node *) malloc(sizeof(BT_Node));
   temp->data = 0;
   temp->lchild = NULL;
   temp->rchild = NULL;
   temp->parent = NULL;
   
   return temp;
}


BT_Node *Heap::insert_horizontal(int key)
{
	BT_Node *new_node = get_node();
	new_node->data = key;
	if (pRoot == NULL)
	{
		pRoot = new_node;
		pCurr = pRoot;
		//printf("Root has value of %d\n", pRoot->data);
	}
	else
	{
		if (pCurr->lchild == NULL)
		{
			//printf("new left node has key value: %d\n", new_node->data);
			
			pCurr->lchild = new_node;
			new_node->parent = pCurr;
			pQueue->insertfront(pCurr->lchild);
			pStack->insertfront(pCurr->lchild);
			// pQueue->showlist();
		}	
		else if (pCurr->rchild == NULL)
		{
			//printf("new right node has key value: %d\n", new_node->data);
			pCurr->rchild = new_node;
			new_node->parent = pCurr;
			pQueue->insertfront(pCurr->rchild);
			pStack->insertfront(pCurr->rchild);
			// pQueue->showlist();
			pCurr = (BT_Node*)pQueue->deletelast();
			//printf("new pCurr has value of %d", pCurr->data);

		}
	}
	return new_node;
}

void Heap::Upheap(BT_Node *new_node)
{
	BT_Node *temp = new_node;
	int v = temp->data;
	while (temp->parent != NULL)
	{
		if (temp->parent->data < v)
		{
			temp->data = temp->parent->data;
			temp = temp->parent;
		}
		else break;
	}
	temp->data = v;
	
	return;
}

int Heap::remove_root()
{
	int v = 0;

    if (pRoot)
	{
		v = pRoot->data;
	}

	
	if (pStack->isEmpty())
	{
		v = pRoot->data;
		free(pRoot);
		pRoot = NULL;
	}
	else
	{
		BT_Node *temp = (BT_Node*)(void*)pStack->deletefront();
		BT_Node *temp_2 = (BT_Node*)(void*)pQueue->deletefront();
		if (temp != temp_2)
			pQueue->insertfront(temp_2);
		
		//printf("deletefront:  temp->data = %d \n", temp->data);
		if (temp == temp->parent->rchild)
		{
			pQueue->insertlast(pCurr);
			pCurr = temp->parent;
			pRoot->data = temp->data;
			free(temp);
			pCurr->rchild = NULL;
		}
		else
		{
			pCurr = temp->parent;
			pRoot->data = temp->data; 
			pCurr->lchild = NULL;
			free(temp);
		}
	}
	
	return v;
}

void Heap::Downheap()
{
	BT_Node *temp = pRoot;
	
	if (temp == NULL)
		return;
	
	int v = temp->data;
	
	//printf("Downheap called ... \n");
		
	// Loop until a leaf node is reached
	while (temp->lchild != NULL)
	{
		
		// do we have a right-child
		if (temp->rchild != NULL && temp->rchild->data > temp->lchild->data)
		{
			if (temp->rchild->data > v)
			{
				temp->data = temp->rchild->data;
				temp = temp->rchild;
			}
			else break;
		}
		// Comparing with left child because it is smaller than the right child
		// or because there is no right child
		else 
		{
			if (temp->lchild->data > v)
			{
				temp->data = temp->lchild->data;
				temp = temp->lchild;
			}
			else break;
		}
		
	}
	
	temp->data = v;
	
	return;
}

void Heap::show_heap()
{
	BT_Node *temp = pRoot;
	while (temp != NULL)
	{
		printf("searched temp-data = %d \n", temp->data);
		if (temp->lchild)
		{
			pQueue->insertfront(temp->lchild);
			printf("pushed left node with key value: %d", temp->lchild->data);
		}
		if (temp->rchild)
		{
			pQueue->insertfront(temp->rchild);
			printf("	pushed right node with key value: %d \n", temp->rchild->data);
		}
		
		if (pQueue->isEmpty())
			temp = (BT_Node*) pQueue->deletelast();
	}
	return;
}

int Heap::isEmpty()
{
	return (pRoot == NULL);
}

