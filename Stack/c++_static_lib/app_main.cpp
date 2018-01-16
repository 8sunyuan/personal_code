
#include "Stack.h"

int main()
{
	Stack * pStack = NULL;
	pStack = new Stack;
	
	int x;
	printf ("Please enter a Stack item value: \n");
	while (scanf("%d", &x) != EOF)
	{
		pStack->push(x);
		printf ("Please enter the next item value: \n");
	}
	
	pStack->emptyStack();
	
	delete pStack;
	pStack = NULL;
	
	return 0;
}
