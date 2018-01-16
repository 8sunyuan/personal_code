#include "binaryTree.h"


binaryTree::binaryTree()
{
	pCurr = NULL;
	pRoot = NULL;
	pRoot_bst = NULL;
	pQueue = new Queue;
	pStack = new Stack;
	return;
}

binaryTree::~binaryTree()
{
	postorder_free(pRoot);
	
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


BT_Node *binaryTree::get_node() 
{
   BT_Node *temp = (BT_Node *) malloc(sizeof(BT_Node));
   temp->data = 0;
   temp->lchild = NULL;
   temp->rchild = NULL;
   
   return temp;
}

void binaryTree::insert(BT_Node *current, BT_Node *new_node) 
{
   printf("\ncurrent_node = %d, new_node = %d ", current->data, new_node->data);
   
   if (new_node->data < current->data) 
   {
      if (current->lchild == NULL)
	  {
         current->lchild = new_node;
	  }
      else
	  {
         insert(current->lchild, new_node);
	  }
   }
   else
   {
      if (current->rchild == NULL)
	  {
         current->rchild = new_node;
	  }
      else
	  {
         insert(current->rchild, new_node);
	  }
   }  
}

void binaryTree::insert_horizontal(BT_Node *new_node)
{
	if (pCurr->lchild == NULL)
	{
		printf("new node has key value: %d", new_node->data);
		pCurr->lchild = new_node;
		pQueue->push(pCurr->lchild);
	}
	else if (pCurr->rchild == NULL)
	{
		printf("new node has key value: %d", new_node->data);
		pCurr->rchild = new_node;
		pQueue->push(pCurr->rchild);
		
		pCurr = (BT_Node*)pQueue->pop();
		if (pCurr)
		{
			printf("\npopout node has key value: %d", pCurr->data);
		}
	}
}

BT_Node *binaryTree::search(BT_Node *current, int key) 
{
	BT_Node * temp = current;
	BT_Node * parent = NULL;
   
	while (temp != NULL) 
	{
		printf("current_node = %d, search_node = %d ", temp->data, key);
		
		if (temp->data == key) 
		{
			printf("\nThe %d Element is Present", temp->data);

			if (parent != NULL)
			{
				printf("\nThe parent of %d Element is %d \n", temp->data, parent->data);
			}
			else
			{
				printf("\nThe %d Element is the ROOT of the tree \n", temp->data);
			}

			return temp;
		}

		parent = temp;

		if ( key < temp->data )
		{
			temp = temp->lchild;
		}
		else
		{
			temp = temp->rchild;
		}
		
	} // while
   
	return NULL;
}

BT_Node *binaryTree::search_horizontal(BT_Node *current, int key)
{
	BT_Node *temp = current;
	
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			// we are done, print some info
			printf(" key = %d is found \n", key);
			return temp;
		}
		else
		{
			printf("searched temp-data = %d \n", temp->data);
			if (temp->lchild)
			{
				pQueue->push(temp->lchild);
				// printf("pushed left node with key value: %d", temp->lchild->data);
			}
			if (temp->rchild)
			{
				pQueue->push(temp->rchild);
				// printf("	pushed right node with key value: %d \n", temp->rchild->data);
			}
			
			temp = (BT_Node*) pQueue->pop();
		}
	} // while
	
	// key not found, print some info
	return NULL;
}

BT_Node *binaryTree:: search_vertical(BT_Node*current, int key)
{
	BT_Node *temp = current;
	
	while (temp != NULL)
	{
		if (temp->data == key)
		{
			// we are done, print some info
			printf(" key = %d is found \n", key);
			return temp;
		}
		else
		{
			printf("searched temp-data = %d \n", temp->data);
			if (temp->lchild)
			{
				pStack->push(temp->lchild);
				// printf("pushed left node with key value: %d", temp->lchild->data);
			}
			if (temp->rchild)
			{
				pStack->push(temp->rchild);
				// printf("	pushed right node with key value: %d \n", temp->rchild->data);
			}
			
			temp = (BT_Node*) pStack->pop();
		}
	} // while
	
	// key not found, print some info
	return NULL;
}


void binaryTree::inorder(BT_Node *temp) 
{
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d ", temp->data);
      inorder(temp->rchild);
   }
}

void binaryTree::preorder(BT_Node *temp) 
{
   if (temp != NULL) {
      printf("%d ", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}

void binaryTree::postorder(BT_Node *temp) 
{
   if (temp != NULL) {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d ", temp->data);
   }
}

void binaryTree::postorder_free(BT_Node *temp)
{
	if (temp != NULL) 
	{
      postorder_free(temp->lchild);
      postorder_free(temp->rchild);
	  printf("Node = %d is freed\n", temp->data);
	  free(temp);
	}
	
}

void binaryTree::handle_create_bst_tree()
{
	int element = -1;
	BT_Node *new_node = NULL;
	
	printf("\nEnter the tree node Element ");
	while(scanf("%d", &element) != EOF) 
	{
		new_node = get_node();
		new_node->data = element;
		
		if (pRoot == NULL)
		{
			// pRoot_bst = new_node;
			pRoot = new_node;
		   
		}
		else
		{
			// insert(pRoot_bst, new_node);
			insert(pRoot, new_node);
		}

		printf("\nEnter another node Element or end with CTL-D ");
	}
}

void binaryTree::handle_create_tree()
{
	int element = -1;
	BT_Node *new_node = NULL;
	BT_Node *x = NULL;
	
	printf("\nEnter the tree BT_Node Element ");
	while(scanf("%d", &element) != EOF) 
	{
		new_node = get_node();
		new_node->data = element;
		
		if (pRoot == NULL)
		{
			pRoot = new_node;
			pCurr = pRoot;
		}
		else
		{
			insert_horizontal(new_node);
		}

		printf("\nEnter another BT_Node Element or end with CTL-D ");
	}
	
	// Empty queue
	pQueue->emptyQueue();
}

void binaryTree::handle_search()
{
	int key;
	BT_Node *tmp = NULL;
	
	printf("\nEnter BT_Node Element to be searched :");
	scanf("%d", &key);

	tmp = search(pRoot, key);
	if ( tmp == NULL )
	{
		printf("\nnode %d is not found! \n", key);
	}
}

void binaryTree::handle_search_horizontally()
{
	int key;
	BT_Node *tmp = NULL;
	
	printf("\nEnter BT_Node Element to be searched :");
	scanf("%d", &key);

	tmp = search_horizontal(pRoot, key);
	if ( tmp == NULL )
	{
		printf("\nnode %d is not found! \n", key);
	}
	// pQueue_srch->emptyQueue();
	
}

void binaryTree::handle_search_vertically()
{
	int key;
	BT_Node *tmp = NULL;
	
	printf("\nEnter BT_Node Element to be searched :");
	scanf("%d", &key);

	tmp = search_vertical(pRoot, key);
	if ( tmp == NULL )
	{
		printf("\nnode %d is not found! \n", key);
	}
	// pQueue_srch->emptyQueue();
	
}

void binaryTree::handle_traversals()
{
	if (pRoot == NULL)
	{
		printf("\nTree Is Not Created! Please create tree first! \n");
	}
	else 
	{
		printf("\nThe Inorder display : ");
		inorder(pRoot);
		
		printf("\nThe Preorder display : ");
		preorder(pRoot);
		
		printf("\nThe Postorder display : ");
		postorder(pRoot);
	}
}

void binaryTree::app_interface()
{
	int choice;
	
	while (1) 
	{
		printf("\n\nProgram For Binary Search Tree: ");
		printf("\n1.Create Binary Search Tree");
		printf("\n2.Create Binary Tree");
		printf("\n3.Binary Search");
		printf("\n4.Search Horizontally");
		printf("\n5.Search Vertically");
		printf("\n6.Recursive Traversals");
		printf("\n7.Exit");
		printf("\nEnter your choice :");
		scanf("%d", &choice);
		printf("\n");

		if (choice == 7) 
		  break;

		switch (choice) 
		{
			case 1:
				handle_create_bst_tree();
				break;
				
			case 2:
				handle_create_tree();
				break;

			case 3:
				handle_search();
				break;
				
			case 4:
				handle_search_horizontally();
				break;
				
			case 5:
				handle_search_vertically();
				break;

			case 6:
				handle_traversals();
				break;
			 
			default: 
				{}
		} // switch
	} // while
	
	return;
}
