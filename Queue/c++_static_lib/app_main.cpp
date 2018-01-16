
#include "Queue.h"


int main()
{
	Queue *pQueue = NULL;
	pQueue = new Queue;
	
	int x;
     
	printf ("Please enter a queue item value: \n");
	while (scanf("%d", &x) != EOF)
	{
		pQueue->push(x);
		printf ("Please enter the next item value: \n");
	}
	
	pQueue->emptyQueue();
	
	delete pQueue;
	pQueue = NULL;
	
	return 0;
}
