#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>


struct node
{
	void* key;
	struct node *next;
};

class linkedlist
{
	public:
		linkedlist();
		~linkedlist();
		
		void* deletefront();
		void* deletelast();
		void showlist();
		void insertfront(void* v);
		int isEmpty();
	
	protected:
	
	private:
		struct node *pHead;
};

#endif