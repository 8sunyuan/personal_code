
#include "hash_table.h"



HashTable::HashTable(int size)
{
    table_size = size;
    total_elements = 0;
    
	hashtable = new HashEntry* [table_size];
	
	for (int i = 0; i< table_size; i++)
	{
		hashtable[i] = NULL;
	}
}

HashTable::~HashTable()
{
	for (int i = 0; i < table_size; i++)
	{
		if (hashtable[i] != NULL)
			delete hashtable[i];
		
		delete[] hashtable;
	}
    
    table_size = 0;
    total_elements = 0;
}

// Primary-hash       
int HashTable::HashFunc1(int key)
{
	return key % table_size;
}

// Double-hash special case:  linear probing
int HashTable::HashFunc2(int hash)
{
	return (hash+1) % table_size;
}

// --------------------------------------------------
// Inseart Element at a key; 
// Return:  OK: total # of elements in the table; Fail: -1        
int HashTable::Insert(int key, int value)
{
	int hash = HashFunc1(key);
	
	while (hashtable[hash] != NULL && hashtable[hash]->key != key)
	{
		hash = HashFunc2(hash);
	}
	
	// replace the old element of the same key
	if (hashtable[hash] != NULL)
		delete hashtable[hash];
	
	hashtable[hash] = new HashEntry(key, value);
	printf("Element Inserted: key = %d, hashtable[%d] = %d \n", key, hash, hashtable[hash]->value);
    
    return ++total_elements;
}

/ --------------------------------------------------
// Search Element at a key; 
// Return:  OK: element value; Fail: -1       
int HashTable::Search(int key)
{
	int  hash = HashFunc1(key);
	
	while (hashtable[hash] != NULL && hashtable[hash]->key != key)
	{
		hash = HashFunc2(hash);
	}
	
	if (hashtable[hash] == NULL)
	{
		return -1;
	}
	else
	{
		printf("Element found: key = %d, hashtable[%d] = %d \n", key, hash, hashtable[hash]->value);
		return hashtable[hash]->value;
	}
}
 
// --------------------------------------------------
// Remove Element at a key; 
// Return:   OK: total # of elements remaining; Fail: -1             
int HashTable::Remove(int key)
{
	int hash = HashFunc1(key);
	
	while (hashtable[hash] != NULL)
	{
		if (hashtable[hash]->key == key)
			break;
		
		hash = HashFunc2(hash);
	}
	
	if (hashtable[hash] == NULL)
	{
        printf("No Element found at key = %d \n", key);
        return -1;
    }
    else
    {
        printf("Element Deleted: key = %d, hashtable[%d] = %d \n", hashtable[hash]->key, hash, hashtable[hash]->value);
        delete hashtable[hash];
		hashtable[hash] = NULL;
    }

    return --total_elements;
}
 


int main()
{
    HashTable hashtable(127);
    int key;
    int value;
    int total;
    int choice;
    
    while (1)
    {
		printf("\n------------------------\n");
        printf("       Hash Table\n");
        printf("------------------------\n");
        printf("1: Insert element into the table\n");
        printf("2: Search element from the key\n");
        printf("3: Delete element at a key\n");
        printf("4: Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter element value: ");
                scanf("%d", &value);
                printf("Enter element key : ");
                scanf("%d", &key);
                
                total = hashtable.Insert(key, value);
                printf("Total = %d elements in HashTable after inseart \n", total);
                break;
                
            case 2:
                printf("Enter key of the element to be searched: ");
                scanf("%d", &key);
                
                value = hashtable.Search(key);
                if (value == -1)
                {
                    printf("No element found at key = %d \n", key);
                    continue;
                }
                printf("HashTable[%d] = %d", key, value);
                break;
                
            case 3:
                printf("Enter key of the element to be deleted: ");
                scanf("%d", &key);
                total = hashtable.Remove(key);
                if (total == -1)
                {
                    printf("No element found at key = %d \n", key);
                    continue;
                }
                printf("Total = %d elements in HashTable after remove \n", total);
                break;
                
            case 4:
                exit(0);  // code 0: "success"; or other code
                
            default:
                printf("\nEnter correct option: 1 .. 4 \n");
       }
    }
    
    return 0;
}