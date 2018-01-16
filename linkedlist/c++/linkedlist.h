
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
		
		void deletefront();
		void showlist();
		struct node *insertfront(int v);
		int isEmpty();
	
	protected:
	
	private:
		struct node *head;
		struct node *tail;
};
