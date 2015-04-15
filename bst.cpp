/*

Author: kyechur, Kashyap Yechuri

Filename: bst.cpp

Description: This file is the bst file for project part 1.

*/
#include <iostream>
using std::cout;
using std::endl;

#include <cassert>

#include "bst.h"

// Inserts key into a tree represented by x.
bstNode* BST::insert (bstNode* x, long key) {
	//check if the root null
	if(root == NULL){
		//make the root a bstnode w/ key and return	
		root = new bstNode(key);	
		return root;	
  	}
	//check if key is less than x's key
	if(key < x->key){
		if(x->left == NULL){
			//if the left child is null then make new bstnode and return 
			x->left = new bstNode(key, NULL, NULL, x);
			return root;
		}
		else{
			//if not, then return left's key
			return insert(x->left,key);
		}
	}
	else{
		if(x->right == NULL){
			//if the right child is null then make new bstnode and return 			
			x->right = new bstNode(key, NULL, NULL, x);
			return root; 
		}
		else{
			//if not, then return right's key 	
			return insert(x->right,key);
		}
	}	
}

// This is a wrapper function that calls the actual insert routine. It is an error to call this function
// with a duplicate key.
void BST::insert (long key) {
  assert(!search(key));
  root = insert(root, key);
}

// Searches for key in tree represented by x.
bstNode* BST::search (bstNode *x, long key) {
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
bstNode* BST::search (long key) {
	return search (root, key);
}

void BST::remove(bstNode *x, long key){
	//set up a temp node 
	bstNode* temp;	
	if(x == NULL)
		return;
	//recursively uses remove in the left and right subtrees
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
		}
		else{
			root = x->right;
			x->right->parent = NULL;
		}			
	}		
}

bstNode* BST::findMin(bstNode *x){
	//uses this function to find the successor	
	if(x == NULL)
		return NULL;
	if(x->left == NULL)
		return NULL;
	while(x->left != NULL)	
		x = x->left;
	
	return x;	

}	
// deletes a bstnode from the tree
void BST::remove(long key) {
	assert(search(key));
	remove(root, key);
}


void BST::inOrder (bstNode *x) {
	//checks if it is null
	if(x == NULL)
		return;
	//checks left
	inOrder(x->left);
	//cout the key 
	cout << ((long)x->key) << " ";
	//moves right

	inOrder(x->right);
}

// This is a wrapper function that calls the inorder routine to enumerate contents of the set.
void BST::print() {
  inOrder(root);
  cout << endl;
}



