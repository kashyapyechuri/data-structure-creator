/*

Author: Kashyap Yechuri

*/
#ifndef AVL_H
#define AVL_H

class avlNode {
  long key;
  int height;		
  avlNode *left;
  avlNode *right;
  avlNode *parent;

  public:
  avlNode () : key(0), height(0), left(NULL), right(NULL), parent(NULL) {}
  avlNode (long k) : key(k), height(0), left(NULL), right(NULL), parent(NULL) {}
  avlNode (long k, avlNode *l, avlNode *r) : key(k), height(0), left(l), right(r), parent(NULL) {}
  avlNode (long k, avlNode *l, avlNode *r, avlNode *p) : key(k), height(0), left(l), right(r), parent(p) {}
	int getKey(){return key;}

  friend class AVL;
};

class AVL {
  avlNode* root;
  avlNode* insert (avlNode* x, long key);
  void remove (avlNode* x, long key);	
  avlNode* search (avlNode* x, long key);
  void inOrder (avlNode *x);
  avlNode* findMin (avlNode *x); 
  void rotate (avlNode *x); 	
  int avlheight (avlNode* x); 
  int max(int a, int b);				
  void balance(avlNode *x); 

  public:
  AVL () : root(NULL) {}
  
  void insert (long key);
  avlNode* search (long key);
  void remove (long key);	
  void print ();
  	
};

#endif
