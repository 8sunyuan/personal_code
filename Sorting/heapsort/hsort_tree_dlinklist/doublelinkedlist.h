#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct bt_node 
{
   int data;
   struct bt_node *lchild; 
   struct bt_node *rchild;
   struct bt_node *parent;
} BT_Node;


struct node
{
	void* key;
	struct node *next;
	struct node *prev;
};

class doublelinkedlist
{
	public:
		doublelinkedlist();
		~doublelinkedlist();
		
		void* deletefront();
		void* deletelast();
		
		void insertlast(void* v);
		void insertfront(void* v);
		
		void showlist();
		int isEmpty();
	
	protected:
	
	private:
		struct node *pHead;
		struct node *pTail;
};

#endif