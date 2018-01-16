#include "doublelinkedlist.h"

int main ()
{
	int i = 9;
	int N;
	int M;
	doublelinkedlist * pList = NULL;
	

	printf("Please type two integars: \n");
	scanf("%d %d", &N, &M);
	
	// creat an list object
	// class linkedlist list;
	// how to use the object:
	//    list.insertfront(i);
	//
	// Dynamic creating object
	if (pList == NULL)
	{
		pList = new doublelinkedlist;
	}
	
	// adding N nodes, each with value N
	for (i = 1; i <= N; i++)
	{
		pList->insertlast(i);
	}
	
	// M is number of nodes to delete
	if (M < N)
	{
		for (i = 1; i <= M; i++)
		{
			pList->deletelast();
		}
	}
	// If there does not exist M nodes to remove then remove until one node left
	else
	{
		while (!pList->isEmpty())
		{
			pList->deletefront();
		}
	}
	
	
	pList->showlist();
	
	delete pList;
	pList = NULL;
	
	// ... ...
	
	return 0;
}