#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

class Stack
{
	public:
	
		Stack();
		~Stack();
		
		void push(void* v);
		void* pop();
		
		void emptyStack();
		int isEmpty();
		
		
	protected:
	
	private:
	
		linkedlist *pList;
	
};

#endif