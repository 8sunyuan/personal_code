#ifndef __HASHTABLE__
#define __HASHTABLE__


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX_NAME_SZ 40
 
 
 
// ----------------------------------------------
// Hash Table chaining with Singly Linked Lists
// ----------------------------------------------

class HashNode
{
    public:
        int id;
        int value;
        HashNode* next;
		char name[MAX_NAME_SZ];
		
        HashNode(int id, int value, char* name)
        {
			int len = strlen(name);
            this->id = id;
            this->value = value;
            this->next = NULL;
			
			if (len > MAX_NAME_SZ -1)
			{
				printf("Max name size = %d, Len = %d\n", MAX_NAME_SZ, len);
				strncpy(this->name, name, MAX_NAME_SZ-1);
				name[MAX_NAME_SZ] = '\0';
			}
			else strcpy(this->name, name);
			// printf("nmae = %s\n", this->name);
        }
};
 

// HashTable Class Declaration
class HashTable
{  
    public:
        HashTable(int size);
        ~HashTable();

        int HashFunc(int key);
		int HashFunc(char* key);
 
        int Insert(int id, int value, char* name);
		int Insert(char* name, int id, int value);
		
        int Remove(int key);
		int Remove(char* key);
		
        int Search(int key);
		int Search(char* key);
		
		void ShowAll();
    
    protected:

    private:
        HashNode** hashtable;
        int table_size;
        int total_elements;
};

#endif