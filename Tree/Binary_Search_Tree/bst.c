// =============================================================
// Preorder traversal sequence : (root, left, right)
// Inorder traversal sequence  : (left, root, right)
// Postorder traversal sequence: (left, right, root)
// =============================================================

# include <stdio.h>
# include <stdlib.h>

// gloal data types and variables 
// ---------------------------------------------
struct BST 
{
   int data;
   struct BST *lchild; 
   struct BST *rchild;
};

typedef struct BST node;
 
node *root = NULL; 

// public functions
// ----------------------------------------------
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *search(node *, int);

// some internal functions
node *get_node();
void handle_create_tree();
void handle_search();
void handle_traversals();
void postorder_free(node *);

// Implementations of the functions
// ----------------------------------------------
/*
 This function is for allocating memory for a node
 */
node *get_node() 
{
   node *temp = (node *) malloc(sizeof(node));
   temp->data = 0;
   temp->lchild = NULL;
   temp->rchild = NULL;
   
   return temp;
}

/*
 This function is for creating a binary search tree
 */
void insert(node *current, node *new_node) 
{
   printf("\ncurrent_node = %d, new_node = %d \n", current->data, new_node->data);
   
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

/*
 This function is for searching the node from
 binary Search Tree
 */
node *search(node *current, int key) 
{
	node * temp = current;
	node * parent = NULL;
   
	while (temp != NULL) 
	{
		printf("current_node = %d, search_node = %d \n", temp->data, key);
		
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

/*
 This function displays the tree in inorder fashion
 */
void inorder(node *temp) 
{
   if (temp != NULL) {
      inorder(temp->lchild);
      printf("%d ", temp->data);
      inorder(temp->rchild);
   }
}

/*
 This function displays the tree in preorder fashion
 */
void preorder(node *temp) 
{
   if (temp != NULL) {
      printf("%d ", temp->data);
      preorder(temp->lchild);
      preorder(temp->rchild);
   }
}
 
/*
 This function displays the tree in postorder fashion
 */
void postorder(node *temp) 
{
   if (temp != NULL) {
      postorder(temp->lchild);
      postorder(temp->rchild);
      printf("%d ", temp->data);
   }
}

void postorder_free(node *temp)
{
	if (temp != NULL) 
	{
      postorder_free(temp->lchild);
      postorder_free(temp->rchild);
	  printf("\nNode = %d is freed \n", temp->data);
	  free(temp);
	}
	
}



/*
 Handle Case 1
 */
void handle_create_tree()
{
	int element = -1;
	node *new_node = NULL;
	
	printf("\nEnter the tree node Element ");
	while(scanf("%d", &element) != EOF) 
	{
		new_node = get_node();
		new_node->data = element;
		
		if (root == NULL)
		{
		   root = new_node;
		}
		else
		{
		   insert(root, new_node);
		}

		printf("\nEnter another node Element or end with CTL-D ");
	}
}

/*
 Handle Case 2
 */
void handle_search()
{
	int key;
	node *tmp = NULL;
	
	printf("\nEnter node Element to be searched :");
	scanf("%d", &key);

	tmp = search(root, key);
	if ( tmp == NULL )
	{
		printf("\nnode %d is not found! \n", key);
	}
}

/*
 Handle Case 3
 */
void handle_traversals()
{
	if (root == NULL)
	{
		printf("\nTree Is Not Created! Please create tree first! \n");
	}
	else 
	{
		printf("\nThe Inorder display : ");
		inorder(root);
		
		printf("\nThe Preorder display : ");
		preorder(root);
		
		printf("\nThe Postorder display : ");
		postorder(root);
	}
}

// --------------------------------------------------------------------------
//   M A I N
// --------------------------------------------------------------------------
int main() 
{
	int choice;
	
	while (1) 
	{
		printf("\n\nProgram For Binary Search Tree: ");
		printf("\n1.Create");
		printf("\n2.Search");
		printf("\n3.Recursive Traversals");
		printf("\n4.Exit");
		printf("\nEnter your choice :");
		scanf("%d", &choice);

		if (choice == 4) 
		  break;

		switch (choice) 
		{
			case 1:
				handle_create_tree();
				break;

			case 2:
				handle_search();
				break;

			case 3:
				handle_traversals();
				break;
			 
			default: 
				{}
		} // switch
	} // while

	// free the tree nodes
	// TBD 
	postorder_free(root);
	return 0;
}