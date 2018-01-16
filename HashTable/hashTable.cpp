#include "hashTable.h"
 
// constructor
HashTable::HashTable(int size)
{
    table_size = size;
    total_elements = 0;
    
    // create the table: an array of pointers
    hashtable = new HashNode* [table_size];
    
    // assign each pointer to NULL
    for (int i = 0; i < table_size; i++)
        hashtable[i] = NULL;
}

// destructor
HashTable::~HashTable()
{
    for (int i = 0; i < table_size; ++i)
    {
        HashNode* entry = hashtable[i];
        while (entry != NULL)
        {
            HashNode* prev = entry;
            entry = entry->next;
            delete prev;
        }
    }
    delete [] hashtable;
    
    table_size = 0;
    total_elements = 0;
}

int HashTable::HashFunc(int key)
{
	return key % table_size;
}

int HashTable::HashFunc(char* key) 
{ 
    unsigned int hash = 0;
	
	while (*key)
	{
		// hash += *key++;
		hash = (hash<<3) ^ (*key++); // ^ bitwise XOR used in C++ book
	}
	
	printf("raw-hash = %d \n", hash);
    return (hash % table_size);
}


 

// --------------------------------------------------
// Inseart Element at a id; 
// Return:  OK: total # of elements in the table; Fail: -1     
int HashTable::Insert(int id, int value, char* name)
{
    int hash = HashFunc(id);
    HashNode* entry = hashtable[hash];
    HashNode* prev = NULL;
	HashNode* next = NULL;
    
    // go to the end of the list
    while (entry != NULL && entry->id != id)
    {
        prev = entry;
        entry = entry->next;
    }
	
	if (entry != NULL)
	{
		printf("Element with same id is deleted: id = %d, name = %s, hash_table[%d] = %d chain-head \n", id, entry->name, hash, entry->value);
		next = entry->next;
		delete entry;
		entry = NULL;
		--total_elements;
	}
    
    // (entry == NULL)
    entry = new HashNode(id, value, name);
    if (prev == NULL)
    {
        hashtable[hash] = entry;
		entry->next = next;
		printf("Element Inserted: id = %d, name = %s, value = %d, hash_table[%d] chain-head \n", id, entry->name, entry->value, hash);
    }
    else
    {
        prev->next = entry;
		entry->next = next;
		printf("Element Inserted: id = %d, name = %s, value = %d, hash_table[%d] chain-tail \n", id, entry->name, entry->value, hash);
    }

    return ++total_elements;
}

int HashTable::Insert(char* name, int id, int value)
{
	int hash = HashFunc(name);
	HashNode* entry = hashtable[hash];
	HashNode* prev = NULL;
	HashNode* next = NULL;
	
	// go to the end of the list
    while (entry != NULL && entry->name != name)
    {
        prev = entry;
        entry = entry->next;
    }
	
	if (entry != NULL)
	{
		printf("Element with same id is deleted: id = %d, name = %s, hash_table[%d] = %d chain-head \n", id, entry->name, hash, entry->value);
		next = entry->next;
		delete entry;
		entry = NULL;
		--total_elements;
	}
	// (entry == NULL)
    entry = new HashNode(id, value, name);
    if (prev == NULL)
    {
        hashtable[hash] = entry;
		entry->next = next;
		printf("Element Inserted: id = %d, name = %s, value = %d, hash_table[%d] chain-head \n", id, entry->name, entry->value, hash);
    }
    else
    {
        prev->next = entry;
		entry->next = next;
		printf("Element Inserted: id = %d, name = %s, value = %d, hash_table[%d] chain-tail \n", id, entry->name, entry->value, hash);
    }
	
	return ++total_elements;
}

// --------------------------------------------------
// Remove Element at a id; 
// Return:   OK: total # of elements remaining; Fail: -1                   
int HashTable::Remove(int id)
{
    int ret_value = -1;  // not found
    
    int hash = HashFunc(id);
    HashNode* entry = hashtable[hash];
    HashNode* prev = NULL;
    
    while (entry != NULL)
    {
        if (entry->id == id)
        {
            if (prev == NULL)
            {
				// it is the chain head
                hashtable[hash] = entry->next;
				printf("Element Deleted: id = %d, name = %s, value = %d from hash_table[%d] chain head \n", id,entry->name, entry->value, hash);
            }
            else
            {
                // it is the middle or end
                prev->next = entry->next;
				printf("Element Deleted: id = %d, name = %s, value = %d from hash_table[%d] chain \n", id, entry->name, entry->value, hash);
            }
            
            // ready to free the entry memory
            delete entry;
            ret_value = --total_elements;
            break;
        }
        else
        {
            // check the next node
            prev = entry;
            entry = entry->next;
        }
    }
    
    return ret_value;
}

int HashTable::Remove(char* key)
{
	int ret_value = -1;  // not found
    
    int hash = HashFunc(key);
    HashNode* entry = hashtable[hash];
    HashNode* prev = NULL;
    
    while (entry != NULL)
    {
        if (strcmp(entry->name, key) == 0)
        {
            if (prev == NULL)
            {
				// it is the chain head
                hashtable[hash] = entry->next;
				printf("Element Deleted: id = %d, name = %s, value = %d from hash_table[%d] chain head \n", entry->id,entry->name, entry->value, hash);
            }
            else
            {
                // it is the middle or end
                prev->next = entry->next;
				printf("Element Deleted: id = %d, name = %s, value = %d from hash_table[%d] chain \n", entry->id, entry->name, entry->value, hash);
            }
            
            // ready to free the entry memory
            delete entry;
            ret_value = --total_elements;
            break;
        }
        else
        {
            // check the next node
            prev = entry;
            entry = entry->next;
        }
    }
    
    return ret_value;
}


// --------------------------------------------------
// Search Element at a id; 
// Return:  OK: element value; Fail: -1
int HashTable::Search(int id)
{
    int ret_value = -1;  // not found
   
    int hash = HashFunc(id);
    HashNode* entry = hashtable[hash];
    
    while (entry != NULL)
    {
        if (entry->id == id)
        {
            ret_value = entry->value;
			printf("Element found: id = %d, name = %s, value = %d from hash_table[%d] chain \n", id, entry->name, ret_value, hash);
			break;
        }
        entry = entry->next;
    }
    
    return ret_value;
}

int HashTable::Search(char* key)
{
	int ret = 0;
	
	int hash = HashFunc(key);
    HashNode* entry = hashtable[hash];
    
	while (entry != NULL)
    {
		if (strcmp(entry->name, key) == 0)
        {
			ret = 1;
			printf("Element found: id = %d, name = %s, value = %d from hash_table[%d] chain \n", entry->id, entry->name, entry->value, hash);
			break;
        }
        entry = entry->next;
	}

	return ret;
}

void HashTable::ShowAll()
{
	int i;
	int j = 0;
	HashNode* entry = NULL;

	for (i = 0; i < table_size; i++)
	{
		entry = hashtable[i];
		while(entry != NULL)
		{
			printf("Element found: id = %d, name = %s, value = %d from hash_table[%d] chain \n", entry->id, entry->name, entry->value, i);
			entry = entry->next;
			j++;
		}
	}
	printf("\ntotal_elements = %d, actual total_elements = %d\n", total_elements, j);
	
	return;
}

int main(int argc, char** argv)
{
    HashTable hashtable(127);
    int id;
    int value;
    int total;
    int choice;
	int ret;
	char name[MAX_NAME_SZ];
    
    while (1)
    {
        printf("\n------------------------\n");
        printf("       Hash Table\n");
        printf("------------------------\n");
		printf("Hashfunction with id\n");
        printf("1: Insert element into the table\n");
        printf("2: Search element from the id\n");
        printf("3: Delete element at a id\n\n");
		printf("Hashfunction with name\n");
		printf("4: Insert element into the table\n");
        printf("5: Search element from the id\n");
        printf("6: Delete element at a id\n\n");
		printf("7: Show table elements\n");
        printf("8: Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("Enter element value: ");
                scanf("%d", &value);
                printf("Enter element id : ");
                scanf("%d", &id);
				printf("Enter name : ");
				//fgets(name, sizeof(name), stdin);
				scanf(" %[^\n]", name);  // ??? need a space before %
				
                total = hashtable.Insert(id, value, name);
                printf("Total = %d elements in HashTable after inseart \n", total);
                break;
                
            case 2:
                printf("Enter id of the element to be searched: ");
                scanf("%d", &id);
                
                value = hashtable.Search(id);
                if (value == -1)
                {
                    printf("No element found at id = %d \n", id);
                    continue;
                }
                break;
                
            case 3:
                printf("Enter id of the element to be deleted: ");
                scanf("%d", &id);
                total = hashtable.Remove(id);
                if (total == -1)
                {
                    printf("No element found at id = %d \n", id);
                    continue;
                }
                printf("Total = %d elements in HashTable after remove \n", total);
                break;
            
			case 4:
                printf("Enter element value: ");
                scanf("%d", &value);
                printf("Enter element id : ");
                scanf("%d", &id);
				printf("Enter name : ");
				scanf(" %[^\n]", name);  // ??? need a space before %
				
                total = hashtable.Insert(name, id, value);
                printf("Total = %d elements in HashTable after inseart \n", total);
                break;
				
			case 5:
                printf("Enter name of the element to be searched: ");
                scanf(" %[^\n]", name);
                
                ret = hashtable.Search(name);
                if (!ret)
                {
                    printf("No element found at name = %s \n", name);
                    continue;
                }
                break;
			
			case 6:
				printf("Enter name of the element to be deleted: ");
                scanf(" %[^\n]", name);
                total = hashtable.Remove(name);
                if (total == -1)
                {
                    printf("No element found at name = %s \n", name);
                    continue;
                }
                printf("Total = %d elements in HashTable after remove \n", total);
                break;
			
			case 7:
				hashtable.ShowAll();
				break;
				
            case 8:
                exit(0);  // code 0: "success"; or other code
                
            default:
                printf("\nEnter correct option: 1 .. 4 \n");
       }
    }
    
    return 0;
}