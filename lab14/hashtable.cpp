#include "hashtable.h"
#include <iostream>
#include<iterator>
#include<vector>

using namespace std;

#define A 54059 
#define B 76963 
#define C 86969 

/**
Hash function for the CS104 hash table.

@param s c-string to hash
@return unsigned int value hashed from the input
*/
unsigned hash_str(const char* s)
{
   unsigned h = 31;
   while (*s) {
     h = (h * A) ^ (s[0] * B);
     s++;
   }
   return h % C; 
}

/**
Creates a hash table of the given input size. Creates the array and vectors used for the hash table.

@param size The size of the hash table.
*/
HashTable::HashTable(int size) {
	this->size = size;
	data = new vector<string>*[size];

	for(int i = 0; i < size; i++) {
		data[i] = new vector<string>;
	}
}

/**
Deletes the vectors and array used for the hash table.
*/
HashTable::~HashTable() {
	for(int i = 0; i < size; i++) {
		delete data[i];
	}
	delete [] data;
}

/**
Inserts a string into the hash table Insert should do nothing if the name already exists in the hash table.


@param string that you want to insert

*/
void HashTable::insert(string name) {
	unsigned hash = hash_str(name.c_str());
	hash = hash % size;

	if (data[hash] == NULL && find(name) == false)
	{
		
	   data[hash]->push_back(name);

	 

		
	}

	else if (data[hash] != NULL && find(name) == false)
	{
	  data[hash]->push_back(name);
	}

	// TODO
}


/**
Finds a string in the hash table. Find should return true if the name exists in the hash table.


@param string that you want to find

*/

bool HashTable::find(string name) {
	unsigned hash = hash_str(name.c_str());
	hash = hash % size;

	// TODO

	std::vector<std::string>::iterator it = data[hash]->begin();

	while (it != data[hash]->end())
	{

		if (*it == name)
		{
			return true;
		}

		it++;
	}

	return false;
}

/**
Removes a string in the hash table. Remove should do nothing if the name does not exist in the hash table.


@param string that you want to remove

*/

void HashTable::remove(string name) {
	unsigned hash = hash_str(name.c_str());
	hash = hash % size;

	if (find(name) == true)
	{
		std::vector<std::string>::iterator it = data[hash]->begin();

		while (it != data[hash]->end())
		{

			if (*it == name)
			{
				data[hash]->erase(it);
					return;
			}

			it++;
		}
		
	}

	
}
