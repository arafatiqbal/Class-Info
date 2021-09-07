//Arafat Iqbal
//File for my binary search tree
//CS202
//Program 3

//File for the data structure for this program.
//It insert into a BST

#ifndef H_class
#define H_class
#include "class.h"

using namespace std;

class node
{
	public:
		node();
		node(info * p);
		~node();
		
		node *& go_left();
		node *& go_right();	
			
		info *& get_data();

	protected:
		node * left;
		node * right;
		info * data;

};
class bst
{
	public:
		bst();
		~bst();

		void display();		
		int input(info * p);		

	protected:
		node * root;
		
		int input(node *& root,info * p);
		void display(node * root);
		void delete_all(node *& root);	

};

#endif
