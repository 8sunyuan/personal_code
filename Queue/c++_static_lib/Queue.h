#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

class Queue
{
	public:
	
		Queue();
		~Queue();
		
		void push(int v);
		int pop();
		void emptyQueue();
		int isEmpty();
		
	private:
	
		linkedlist *pList;


};

#endif