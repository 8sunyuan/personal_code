#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>


struct node
{
	int key;
	struct node *next;
	struct node *prev;
};

class doublelinkedlist
{
	public:
		doublelinkedlist();
		~doublelinkedlist();
		
		int deletefront();
		int deletelast();
		
		void insertlast(int v);
		void insertfront(int v);
		
		void showlist();
		int isEmpty();
	
	protected:
	
	private:
		struct node *pHead;
		struct node *pTail;
};

#endif