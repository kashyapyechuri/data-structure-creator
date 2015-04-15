/*

Author: Kashyap Yechuri

*/

#include <iostream>
using std::cout;
using std::endl;

#include "doublehash.h"

/* Return a hash for the long s*/
int Double::hash(long s) {
  return s % table_size;
}

void Double::insert(long key) {
	//create an int that uses hash with the given key
	HashList* curr; 	
	int table = hash(key);
	//hashes into a hash list, then inserts key
	curr = hash_table[table];	

	curr->insert(key);
	
}

hNode* Double::find(long key) {
	int table = hash(key);

	HashList *curr = hash_table[table];	
	//if key is found then return curr
	curr->find(key);
}
void Double::remove(long key){
	HashList* curr;
	//hashes into a hashlist and removes
	int table = hash(key);
	curr = hash_table[table];
	
	curr->remove(key);
			

}

void Double::print() {
	for(int i = 0; i < table_size; ++i){
		//set curr to the spot you are at 
		HashList *curr = hash_table[i];
		curr->print();
		cout << endl;
		
	}
}


