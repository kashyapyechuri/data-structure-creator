/*

Author: kyechur, Kashyap Yechuri

Filename: main.cpp

Description: This file is the driver file for project part 1.

*/
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <assert.h>
#include <stdlib.h>
#include <string>	
#include <cstring>	
using namespace std;		

//#include "bst.h"
#include "avl.h"
//#include "hashlist.h"
#include "hashbst.h"
#include "doublehash.h"
#define TABLESIZE 997
#define TABLESIZE2 50

int main(){
	int x = -1; int y = -1; 
	long number;
	//sets up filename and ifstream in order to read stuff in	
	char* filename = new char[50];	
	ifstream myfile;
 
	while(x != 0){
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~WELCOME TO THE MAIN MENU~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;	
		cout << "Please type a number between 1-5 to access one of the below dictonaries" << endl;
		cout << "(0)--> Exit" << endl;	 
		cout << "(1)--> Binary Search Tree" << endl;
		cout << "(2)--> AVL Tree" << endl;
		cout << "(3)--> Hash Table Chaining" << endl;
		cout << "(4)--> Hash Table Binary Search Tree" << endl;
		cout << "(5)--> Double Hashing" << endl;

		cin >> x;
		//BST
		if(x == 1){
			BST *btree = new BST();
			while(y != 0){
				
				cout << "Please select the function you wish to perform within BST" << endl;
				cout << "(0)--> Back" << endl;			
				cout << "(1)--> Insert" << endl;
				cout << "(2)--> Search" << endl;
				cout << "(3)--> Remove" << endl;
		
				cin >> y;
				if(y > 0 && y < 4){
					
					cout << "Enter the filename to use:" << endl;
					cin >> filename;
					myfile.open(filename);
					//insert	
					if(y == 1){
						long token;
						myfile >> token;	
						while(!myfile.eof()){	
					        //check if token isn't in the tree	
							if(!btree->search(token))
									btree->insert(token);
							myfile >> token;
						}	
						myfile.close();
						btree->print();
					}
					if(y == 2){ //search
						long token;
						myfile >> token;
						while(!myfile.eof()){										
							if(btree->search(token)){
								cout << token << " found within BST" << endl;
							}
							else 
								cout << token << " not found within BST" << endl;	
							myfile >> token;	
						}	
						myfile.close();

					}
					if(y == 3){ //remove
						long token;
						myfile >> token;
						while(!myfile.eof()){		
							if(btree->search(token))
								//insert to the tree
								btree->remove(token);
							myfile >> token;
								
						}
						myfile.close();
						btree->print();
					}
			
				}
				else{
					cout << endl << "ERROR: Invalid number input" << endl;
				}					
			}
		}
		else if(x == 2){ //AVL
			//create avl outside 
			AVL *avltree = new AVL();
			while(y != 0){
				
				cout << "Please select the function you wish to perform within AVL" << endl;
				cout << "(0)--> Back" << endl;			
				cout << "(1)--> Insert" << endl;
				cout << "(2)--> Search" << endl;
				cout << "(3)--> Remove" << endl;
		
				cin >> y;
				if(y > 0 && y < 4){
					
					cout << "Enter the filename to use:" << endl;
					cin >> filename;
					myfile.open(filename);

					if(y == 1){  //insert
						long token;
						myfile >> token;	
						while(!myfile.eof()){	
					        //check if token isn't in the tree	
							if(!avltree->search(token))
									avltree->insert(token);
							myfile >> token;
						}	
						myfile.close();
						avltree->print();
					}
					if(y == 2){ //search
						long token;
						myfile >> token;
						while(!myfile.eof()){										
							if(avltree->search(token)){
								cout << token << " found within AVL" << endl;
							}
							else 
								cout << token << " not found within AVL" << endl;	
							myfile >> token;	
						}	
						myfile.close();
	
					}
					if(y == 3){  //delete
						long token;
						myfile >> token;
						while(!myfile.eof()){		
							if(avltree->search(token))
								//insert to the tree
								avltree->remove(token);
							myfile >> token;
								
						}
						myfile.close();
						avltree->print();
					}
			
				}
				else{
					cout << endl << "ERROR: Invalid number input" << endl;
				}					
			}
		}
		else if(x == 3){ //Hashlist 
			HashList s(TABLESIZE);
			while(y != 0){
				
				cout << "Please select the function you wish to perform within Hashlist" << endl;
				cout << "(0)--> Back" << endl;			
				cout << "(1)--> Insert" << endl;
				cout << "(2)--> Search" << endl;
				cout << "(3)--> Remove" << endl;
		
				cin >> y;
				if(y > 0 && y < 4){
					
					cout << "Enter the filename to use:" << endl;
					cin >> filename;
					myfile.open(filename);

					if(y == 1){
						long token;
						myfile >> token;	
						while(!myfile.eof()){	
					        //check if token isn't in the tree	
							if(!s.find(token))
									s.insert(token);
							myfile >> token;
						}	
						myfile.close();
						s.print();
					}
					if(y == 2){
						long token;
						myfile >> token;
						while(!myfile.eof()){										
							if(s.find(token)){
								cout << token << " found within BST" << endl;
							}
							else 
								cout << token << " not found within BST" << endl;	
							myfile >> token;	
						}	
						myfile.close();

					}
					if(y == 3){
						long token;
						myfile >> token;
						while(!myfile.eof()){		
							if(s.find(token))
								//insert to the tree
								s.remove(token);
							myfile >> token;
								
						}
						myfile.close();
						s.print();
					}
			
				}
				else{
					cout << endl << "ERROR: Invalid number input" << endl;
				}					
			}
		}
		else if(x == 4){  //hashbst
			HashBST s(TABLESIZE);
			while(y != 0){
				
				cout << "Please select the function you wish to perform within BSTHash" << endl;
				cout << "(0)--> Back" << endl;			
				cout << "(1)--> Insert" << endl;
				cout << "(2)--> Search" << endl;
				cout << "(3)--> Remove" << endl;
		
				cin >> y;
				if(y > 0 && y < 4){
					
					cout << "Enter the filename to use:" << endl;
					cin >> filename;
					myfile.open(filename);

					if(y == 1){
						long token;
						myfile >> token;	
						while(!myfile.eof()){	
					        //check if token isn't in the tree	
							if(!s.find(token))
									s.insert(token);
							myfile >> token;
						}	
						myfile.close();
						s.print();
					}
					if(y == 2){
						long token;
						myfile >> token;
						while(!myfile.eof()){										
							if(s.find(token)){
								cout << token << " found within BST" << endl;
							}
							else 
								cout << token << " not found within BST" << endl;	
							myfile >> token;	
						}	
						myfile.close();

					}
					if(y == 3){
						long token;
						myfile >> token;
						while(!myfile.eof()){		
							if(s.find(token))
								//insert to the tree
								s.remove(token);
							myfile >> token;
								
						}
						myfile.close();
						s.print();
					}
			
				}
				else{
					cout << endl << "ERROR: Invalid number input" << endl;
				}					
			}
		}
		else if(x == 5){ //double hashing
			Double s(TABLESIZE, TABLESIZE2);
			while(y != 0){
				
				cout << "Please select the function you wish to perform within Double Hash" << endl;
				cout << "(0)--> Back" << endl;			
				cout << "(1)--> Insert" << endl;
				cout << "(2)--> Search" << endl;
				cout << "(3)--> Remove" << endl;
		
				cin >> y;
				if(y > 0 && y < 4){
					
					cout << "Enter the filename to use:" << endl;
					cin >> filename;
					myfile.open(filename);

					if(y == 1){
						long token;
						myfile >> token;	
						while(!myfile.eof()){	
					        //check if token isn't in the tree	
							if(!s.find(token))
									s.insert(token);
							myfile >> token;
						}	
						myfile.close();
						s.print();
					}
					if(y == 2){
						long token;
						myfile >> token;
						while(!myfile.eof()){										
							if(s.find(token)){
								cout << token << " found within BST" << endl;
							}
							else 
								cout << token << " not found within BST" << endl;	
							myfile >> token;	
						}	
						myfile.close();
	
					}
					if(y == 3){
						long token;
						myfile >> token;
						while(!myfile.eof()){		
							if(s.find(token))
								//insert to the tree
								s.remove(token);
							myfile >> token;
								
						}
						myfile.close();
						s.print();
					}
			
				}
				else if(x > 5 || x < 0){
					cout << endl << "ERROR: Invalid number input" << endl;
				}										
			}							
		}
	}
}
