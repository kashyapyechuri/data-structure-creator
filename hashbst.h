/*

Author: kyechur, Kashyap Yechuri

Filename: hashbst.h

Description: This file is a hashbst file for project part 1.

*/
#include "bst.h"

class HashBST {
  private:
  BST **hash_table;
  int table_size; 
  int hash(long s);
	
  public:
  HashBST () : table_size(0) {}
  HashBST (int ts) {
    table_size = ts;

    hash_table = new BST* [table_size];
    for (int i = 0; i < table_size; ++i) {
      hash_table[i] = new BST();		
    }
  }
  ~HashBST () {
    for (int i = 0; i < table_size; ++i) {
      BST *x = hash_table[i];
      /*while (x != NULL) {
	BST *temp = x;
	x = x->next;
	delete temp;
      }*/
	 x->~BST();	
    }
  }
  
  void insert(long key);
  bstNode* find(long key);
  void remove(long key); 	
  void print();
};


