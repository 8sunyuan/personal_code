#ifndef __HASH_TABLE__
#define __HASH_TABLE__

 
#include <stdlib.h>
#include <stdio.h>
#include <string>
 
// ----------------------------------------------
// Hash Table chaining with Double Hashing
// ----------------------------------------------
 
class HashEntry
{
	public:
		int key;
		int value;
		
		HashEntry(int key, int value)
		{
			this->key = key;
			this->value = value;
		}
};
 
/*
 * HashTable Class Declaration
 */
class HashTable
{
    public:   
        HashTable(int size);
		 ~HashTable();
        
        int HashFunc1(int key);
		int HashFunc2(int hash);

		int Insert(int key, int value);
        int Remove(int key);
        int Search(int key);
		
	protected:
	private:
        HashEntry **hashtable;	
        int table_size;
        int total_elements;
};

#endif