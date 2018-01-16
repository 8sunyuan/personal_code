#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"
#include "Queue.h"

typedef struct bt_node 
{
   int data;
   struct bt_node *lchild; 
   struct bt_node *rchild;
} BT_Node;


class binaryTree
{
	public:
	
		binaryTree();
		~binaryTree();
	
	    void app_interface();
		void insert(BT_Node *current, BT_Node *new_node);
		void insert_horizontal(BT_Node *new_node);
		void inorder(BT_Node *temp);
		void preorder(BT_Node *temp);
		void postorder(BT_Node *temp);
		BT_Node *search(BT_Node *current, int key);
		BT_Node *search_horizontal(BT_Node *current, int key);
		BT_Node *search_vertical(BT_Node *current, int key);
		
	protected:
	private:
	
		BT_Node *get_node();
		void handle_create_bst_tree();
		void handle_create_tree();
		void handle_search();
		void handle_search_horizontally();
		void handle_search_vertically();
		void handle_traversals();
		void postorder_free(BT_Node *temp);

		BT_Node *pCurr;
		BT_Node *pRoot;
		BT_Node *pRoot_bst;
		Queue *pQueue;
		Stack *pStack;
	
	
};

#endif