/*

Author: kyechur, Kashyap Yechuri

Filename: bst.h

Description: This file is a bst file for project part 1.

*/
#ifndef BST_H
#define BST_H

class bstNode {
  long key;
  bstNode *left;
  bstNode *right;
  bstNode *parent;

  public:
  bstNode () : key(0), left(NULL), right(NULL), parent(NULL) {}
  bstNode (long k) : key(k), left(NULL), right(NULL), parent(NULL) {}
  bstNode (long k, bstNode *l, bstNode *r) : key(k), left(l), right(r), parent(NULL) {}
  bstNode (long k, bstNode *l, bstNode *r, bstNode *p) : key(k), left(l), right(r), parent(p) {}
	

  friend class BST;
};

class BST {
  bstNode* root;
  bstNode* insert (bstNode* x, long key);
  void remove (bstNode* x, long key);	
  bstNode* search (bstNode* x, long key);
  void inOrder (bstNode *x);
  bstNode* findMin (bstNode *x); 	

  public:
  BST () : root(NULL) {}

  void insert (long key);
  bstNode* search (long key);
  void remove (long key);	
  void print ();

};

#endif
