/*

Author: kyechur, Kashyap Yechuri

Filename: doublehash.h

Description: This file is a doublehash file for project part 1.

*/
#include "hashlist.h"

class Double {
  private:
  int table_size;
  int table_size2; 	 	
  HashList **hash_table;

  int hash(long s);

  public:
  Double () : table_size(0) {}
  Double (int ts) {
    table_size = ts;

    hash_table = new HashList* [table_size];
    for (int i = 0; i < table_size; ++i) {
      hash_table[i] = new HashList();	
    }
  }
  Double (int ts, int s) {
    table_size = ts;

    hash_table = new HashList* [table_size];
    for (int i = 0; i < table_size; ++i) {
      hash_table[i] = new HashList(s);	
    }
  }	
  ~Double () {
    for (int i = 0; i < table_size; ++i) {
      HashList *x = hash_table[i];
	x->~HashList();
    }
  }
  
  void insert(long key);
  hNode* find(long key);
  void remove(long key); 	
  void print();
};
