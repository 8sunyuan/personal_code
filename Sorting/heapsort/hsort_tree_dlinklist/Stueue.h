#ifndef __STUEUE_H__
#define __STUEUE_H__

#include <stdio.h>
#include <stdlib.h>

#include "doublelinkedlist.h"

class Stueue
{
	public:
	
		Stueue();
		~Stueue();
		
		void* deletefront();
		void* deletelast();
		
		void insertfront(void* v);
		void insertlast(void* v);
		
		void showlist();
		int isEmpty();
	private:
	
		doublelinkedlist *pList;


};

#endif