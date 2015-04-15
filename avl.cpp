/*

Author: Kashyap Yechuri

*/

#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

#include "avl.h"



int count = 0;
// Inserts key into a tree represented by x.
avlNode* AVL::insert (avlNode* x, long key) {
	//check if the root null
	if(root == NULL){
		//make the root a avlnode w/ key and return	
		root = new avlNode(key);
		count++;	
		return root;	
  	}
	//check if key is less than x's key
	if(key < x->key){
		if(x->left == NULL){
			//if the left child is null then make new avlnode and return 
			x->left = new avlNode(key, NULL, NULL, x);
			
		}
		else{
			//if not, then return left's key
			return insert(x->left,key);
		}
	}
	else{
		if(x->right == NULL){
			//if the right child is null then make new avlnode and return 			
			x->right = new avlNode(key, NULL, NULL, x);
		}
		else{
			//if not, then return right's key 	
			return insert(x->right,key);
		}
	}

	//x->height = max(avlheight(x->left), avlheight(x->right)) +1;
	count++;
	balance(x);
	return root;	
}

// This is a wrapper function that calls the actual insert routine. It is an error to call this function
// with a duplicate key.
void AVL::insert (long key) {
  assert(!search(key));
  root = insert(root, key);
}

void AVL::balance(avlNode* x){
	//initialize variables	
	int difference;
	int l, r;		
	avlNode* leftnode;
	avlNode* rightnode;	
	

	if(x == NULL)
		return;
	while(x != NULL){
		//make left and right nodes	
		leftnode = x->left;
		rightnode = x->right;
		//set heights of those nodes and make difference	
		l = avlheight(leftnode);
		r = avlheight(rightnode);
		
		difference = l - r;
		//left heavy		
		if(difference == 2){	
			if(avlheight(leftnode->right) > avlheight(leftnode->left)){	
				//left right 		
				rotate(x->left->right);
				rotate(x->left);				
			}
			else{
				rotate(leftnode); //left 
			}	
		}
		//right heavy	
		else if(difference == -2){
			if(avlheight(rightnode->right) < avlheight(rightnode->left)){ 
				//right left			
				rotate(x->right->left);
				rotate(x->right);					
			}
			else{
				rotate(rightnode); //right
			}		
		}
		x = x->parent;
	}
}

int AVL::max(int a, int b){

	return (a < b) ? b : a; //returns the greater between a and b

}
int AVL::avlheight(avlNode *x){
	//recursively returns height of avl		
  if(x == NULL) 
	return -1;
  if(x->left == NULL && x->right == NULL)
	return 0;
  else return max(avlheight(x->left),avlheight(x->right)) + 1;
 
}

void AVL::rotate (avlNode *x) {
	//sets parent and granparent nodes	
 	avlNode *parental = x->parent;
 	avlNode *grand = NULL;
 	bool rot = false;
    if(parental == NULL) 
		return;
	//sets grand
  	grand = parental->parent;	
	if(parental == root)
  		rot = true;
  	if(grand != NULL){
     	//if there is no grand
		if(grand->left == parental)
        	grand->left = x;
		else 
			grand->right = x;
    }

  	if(parental->right == x){ //x is a right child
       parental->right = x->left;
	if(x->left)  
	   x->left->parent = parental;
	   x->left = parental;
    }

  else if(parental->left == x){ //x is a left child
  
       parental->left = x->right;
  	if(x->right)  
		x->right->parent = parental;
    x->right = parental;
  }
		
  x->parent = grand;
  parental->parent = x;
  if(rot)
	root = x;
	
}
// Searches for key in tree represented by x.
avlNode* AVL::search (avlNode *x, long key) {
	//go through making sure x isn't null and that there isn't key in that spot
	while(x != NULL && x->key != key){
		//place key on the correct side by checking its relative value
		if(x->key > key)
			x = x->left;
		else if(x->key < key)
			x = x->right;
	}
	return x;
}

// This is a wrapper function that calls the actual search routine.
avlNode* AVL::search (long key) {
	return search (root, key);
}

void AVL::remove(avlNode *x, long key){
	avlNode* temp;
	//recursively decides which side of the tree to go to	
	if(x == NULL)
		return;
	else if(key < x->key)
		remove(x->left, key);
	else if(key > x->key){
		remove(x->right, key);			
	}
	//in the situation that there are 2 children, uses temp to remove the right node
	else if(x->left != NULL && x->right != NULL){
		temp = findMin(x->right);				
		if(temp != NULL){
			x->key = temp->key;
			remove(x->right, temp->key);
		}
		else{
			x->left = NULL;	 
		}	
	}
	//when there are no children, sets itself as null	
	else if(x->left == NULL && x->right == NULL){
		if(x->parent != NULL){
			if(x == x->parent->left)	
				x->parent->left = NULL;
			if(x == x->parent->right)	
				x->parent->right = NULL;
			balance(x->parent);	
		}	
	}
	//left case
	else if	(x->left != NULL){
		if(x->parent != NULL){
			//if it is the left, set parent's left to left
			if(x == x->parent->left){
				x->parent->left = x->left;
				x->left->parent = x->parent;
			}
			//if it is the right, set parent's right to left 
			if(x == x->parent->right){
				x->parent->right = x->left;
				x->left->parent = x->parent;			
			}
			balance(x->parent);
		}
		else{		
			root = x->left;
			x->left->parent = NULL;
		}		
	}
	//right case
	else if	(x->right != NULL){
		if(x->parent != NULL){	
			//if it is the left, set parent's left to left
			if(x == x->parent->left){
				x->parent->left = x->right;
				x->right->parent = x->parent;
			}
			//if it is the right, set parent's right to right
			if(x == x->parent->right){
				x->parent->right = x->right;
				x->right->parent = x->parent;
			}
			balance(x->parent);
		}
		else{
			root = x->right;
			x->right->parent = NULL;
		}			
	}
}
//uses this function to find the successor
avlNode* AVL::findMin(avlNode *x){
	if(x == NULL)
		return NULL;
	if(x->left == NULL)
		return NULL;
	while(x->left != NULL)	
		x = x->left;
	
	return x;	

}	
// deletes a avlnode from the tree
void AVL::remove(long key) {
	assert(search(key));
	remove(root, key);
}

void AVL::inOrder (avlNode *x) {
	//checks if it is null
	if(x == NULL)
		return;
	//checks left
	inOrder(x->left);
	//cout the key 
	cout << ((long)x->key) << " " << "height: " << avlheight(x) << endl;

	//moves right

	inOrder(x->right);
}

// This is a wrapper function that calls the inorder routine to enumerate contents of the set.
void AVL::print() {
  inOrder(root);
  cout << endl;	
}


