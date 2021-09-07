//Arafat Iqbal
//File for BST functions
//Stores all functions from the BST.h File

#include "bst.h"

//Functions for Node Class
node::node():left(0),right(0)
{

}
node::node(info * p):left(0),right(0)
{
	zoom * ptr1 = dynamic_cast<zoom*> (p);
	project * ptr2 = dynamic_cast<project*> (p);
	lecture * ptr3 = dynamic_cast<lecture*> (p);

	if(ptr1) {data = new zoom(*ptr1); return;}
	if(ptr2) {data = new project(*ptr2); return;}
	if(ptr3) {data = new lecture(*ptr3); return;}

}
node::~node()
{
	delete left;
	left = NULL;	
	delete right;
	right = NULL;

}
node *& node::go_left()
{
	return left;

}
node *& node::go_right()
{
	return right;
}
info *& node::get_data(){return data;}

//Functions for BST Class
bst::bst():root(0)
{

}
bst::~bst()
{
	delete_all(root);
}
void bst::delete_all(node *& root)
{
	if(!root) return;
	delete_all(root->go_left());
	delete_all(root->go_right());
	delete root;
	root = NULL;
	return;
}
int bst::input(info * p)
{
	return input(root,p);
}
int bst::input(node *& root,info * p)
{
	if(!root)
	{
		root = new node(p);
	}	
	else if(*p < *root->get_data())
	{
		input(root->go_left(),p);
	}
	else
	{
		input(root->go_right(),p);
	}
	return 1;
}
void bst::display()
{
	return display(root);
}

void bst::display(node * root)
{
	if(!root) return;

	display(root->go_left());
	cout << *(root->get_data()) << endl;
	display(root->go_right());

	return;
}
