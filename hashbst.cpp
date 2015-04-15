/*

Author: Kashyap Yechuri

*/
#include <iostream>
using std::cout;
using std::endl;

#include "hashbst.h"

/* Return a hash for the long s*/
int HashBST::hash(long s) {
  return s % table_size;
}

void HashBST::insert(long key) {
	//create an int that uses hash with the given key
	int table = hash(key);
	//set up two nodes, one to hold current and the other with key 
	//bstNode *node;
	
	BST *curr = hash_table[table];	


	curr->insert(key);
	
}

bstNode* HashBST::find(long key) {
	//hash the key to an int and create curr
	int table = hash(key);

	BST *curr = hash_table[table];

	
	//if key is found then return curr

	return curr->search(key);	

}
void HashBST::remove(long key){
	BST* curr;
	//hashes into an int, and sets equal to a bst, then removes a key
	int table = hash(key);
	curr = hash_table[table];
	
	curr->remove(key);

}

void HashBST::print() {
	//loop through the table 
	for(int i = 0; i < table_size; ++i){
		//set curr to the spot you are at 
		BST *curr = hash_table[i];
		curr->print();
		
	}
}


