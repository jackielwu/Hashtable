
//
// CS251
// Implementation of a HashTable that stores void *
//
#include "HashTableVoid.h"

// Obtain the hash code of a key
int HashTableVoid::hash(const char * key)
{
  int sum = 0;
	int len = strlen(key);
	for(int i = 0; i < len; i++) {
		sum += (i+1)*key[i];
	}
  return sum % TableSize;
}

// Constructor for hash table. Initializes hash table
HashTableVoid::HashTableVoid()
{
  for (int i = 0; i < TableSize; i++) {
		_buckets[i] = NULL;
	}    
}

// Add a record to the hash table. Returns true if key already exists.
// Substitute content if key already exists.
bool HashTableVoid::insertItem( const char * key, void * data)
{
  int h = hash(key);
  HashTableVoidEntry *e = _buckets[h];
  while (e != NULL) {
    if(strcmp(key,e->_key)==0) {
	  	e->_data = data;
	  	return true;
		}
		e = e->_next;
	}
	e = new HashTableVoidEntry();
	e->_key = strdup(key);
	e->_data = data;
	e->_next = _buckets[h];
	_buckets[h] = e;
  return false;
}

// Find a key in the dictionary and place in "data" the corresponding record
// Returns false if key is does not exist
bool HashTableVoid::find( const char * key, void ** data)
{
  int h = hash(key);
  HashTableVoidEntry *e = _buckets[h];
  while (e != NULL) {
    if(strcmp(key,e->_key)==0) {
	  	e->_data = data;
	  	return true;
		}
		e = e->_next;
	}
  return false;
}

// Removes an element in the hash table. Return false if key does not exist.
bool HashTableVoid::removeElement(const char * key)
{
  int h = hash(key);
  HashTableVoidEntry *e = _buckets[h];
	HashTableVoidEntry *p = e;
  while (e != NULL) {
    if(strcmp(key,e->_key)==0) {
			p->_next = e->_next;	
			//delete(e);  	
	  	return true;
		}
		p = e;
		e = e->_next;
	}
  return false;
}

// Creates an iterator object for this hash table
HashTableVoidIterator::HashTableVoidIterator(HashTableVoid * hashTable)
{
	_hashTable = hashTable;
  _currentBucket = 0;
	_currentEntry = _hashTable->_buckets[_currentBucket];

}

// Returns true if there is a next element. Stores data value in data.
bool HashTableVoidIterator::next(const char * & key, void * & data)
{
	for(_currentBucket = 0; _currentBucket < _hashTable->TableSize; _currentBucket++) {
		_currentEntry = _hashTable->_buckets[_currentBucket];		
		while (_currentEntry != NULL) {
			if(strcmp(_currentEntry->_key,key) == 0) {
				data = _currentEntry->_data;
				return true;
			}
			_currentEntry = _currentEntry->_next;
		}
	}
  return false;
}

