
#include <stdio.h>
#include <stdlib.h>


struct node 
{
   int data;
   struct node *lchild; 
   struct node *rchild;
};

class bst
{
	public:
	
		bst();
		~bst();
	
	    void app_interface();
		void insert(node *current, node *new_node);
		void inorder(node *temp);
		void preorder(node *temp);
		void postorder(node *temp);
		struct node *search(node *current, int key);
		
	protected:
	private:
	
		node *get_node();
		void handle_create_tree();
		void handle_search();
		void handle_traversals();
		void postorder_free(node *temp);

		struct node *root;
	
	
};