#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int key;
	struct node *next;
};

class linkedlist
{
	public:
		linkedlist();
		~linkedlist();
		
		int deletefront();
		int deletelast();
		void showlist();
		struct node *insertfront(int v);
		int isEmpty();
	
	protected:
	
	private:
		struct node *pHead;
};

#endif