#ifndef __HEAP_H__
#define __HEAP_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Stueue.h"


class Heap
{
public:	
        
    Heap();
    ~Heap();

    void Insert(int v);
    int  Remove();
	
	int isEmpty();
    void show_heap();
	
protected:

    void Upheap(BT_Node *new_node);
	void Downheap();
	
	BT_Node *get_node();
	BT_Node *insert_horizontal(int key);
	int remove_root();
    
private:

	BT_Node *new_node;
	BT_Node *pCurr;
	BT_Node *pRoot;
	Stueue  *pQueue;
	Stueue  *pStack;
};

#endif