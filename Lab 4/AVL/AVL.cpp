#ifndef __AVL__CPP__
#define __AVL__CPP__

#include <iostream>
#include "AVL.h"

using namespace std;

//---------------------------------------------------------
AVL_node::AVL_node()
{
	left = right = NULL;
	balance = equal_height;
}
//---------------------------------------------------------
AVL_node::AVL_node(const int &x)
{
	data = x;
	left = right = NULL;
	balance = equal_height;
}
//---------------------------------------------------------
void AVL_node::set_balance(Balance_factor b)
{
	balance = b;
}
//---------------------------------------------------------
Balance_factor AVL_node::get_balance() const
{
	return balance;
}
//---------------------------------------------------------
AVL_tree::AVL_tree()
{
	root = NULL;
}
//---------------------------------------------------------
AVL_tree::~AVL_tree()
{
	destroy(root);
	root = NULL;
}
//---------------------------------------------------------
void AVL_tree::destroy(AVL_node *subroot) {
	if (subroot != NULL) {
		destroy(subroot->left);
		destroy(subroot->right);
		delete subroot;
	}
}
//---------------------------------------------------------
bool AVL_tree::empty() {
	return (root == NULL);
}
//---------------------------------------------------------
Error_code AVL_tree::insert(const int &new_data)
{ 
	bool taller;
	return avl_insert(root, new_data, taller);
}
//---------------------------------------------------------
Error_code AVL_tree::avl_insert(AVL_node *&sub_root,
								const int &new_data, bool &taller)
{ 
	Error_code result = success;
	if (sub_root == NULL) {
		sub_root = new AVL_node(new_data);
		taller = true;
	}
	// change: allow duplicates, insert to right subtree
	else if (new_data == sub_root->data) {
		result = avl_insert(sub_root->right, new_data, taller);
		if (taller == true)
			switch (sub_root->get_balance()) {
			case left_higher:
				sub_root->set_balance(equal_height);
				taller = false;
				break;
			case equal_height:
				sub_root->set_balance(right_higher);
				break;
			case right_higher:
				right_balance(sub_root, taller);
				taller = false;
				break;
			}
	}
	else if (new_data < sub_root->data) { 
		result = avl_insert(sub_root->left, new_data, taller);
		if (taller == true)
			switch (sub_root->get_balance()) { 
			case left_higher:
				left_balance(sub_root, taller);
				taller = false; 
				break;
			case equal_height:
				sub_root->set_balance(left_higher); 
				break;
			case right_higher:
				sub_root->set_balance(equal_height);
				taller = false; 
				break;
			}
	}
	else {
		result = avl_insert(sub_root->right, new_data, taller);
		if (taller == true)
			switch (sub_root->get_balance()) {
			case left_higher:
				sub_root->set_balance(equal_height);
				taller = false; 
				break;
			case equal_height:
				sub_root->set_balance(right_higher);
				break;
			case right_higher:
				right_balance(sub_root, taller);
				taller = false; 
				break;
			}			
	}
	return result;
}
//---------------------------------------------------------
Error_code AVL_tree::remove(const int &old_data)
{ 
	bool shorter;
	return avl_remove(root, old_data, shorter);
}
//---------------------------------------------------------
Error_code AVL_tree::avl_remove(AVL_node *&sub_root,
								const int &old_data, bool &shorter)
{ 
	Error_code result = success;
	if (sub_root == NULL) {
		result = not_present;
		shorter = false;
	}
	else if (sub_root->data == old_data) {
		AVL_node *to_delete = sub_root; 
		if (sub_root->right == NULL) {
			sub_root = sub_root->left;
			shorter = true;
			delete to_delete;
		}
		else if (sub_root->left == NULL) {
//please fill your code here
		}
		else {
			to_delete = sub_root -> left;
			while (to_delete->right != NULL) 
				to_delete = to_delete->right; 
			sub_root -> data = to_delete -> data;
			result = avl_remove(sub_root -> left,to_delete -> data,shorter);
			if(shorter == true)
			switch(sub_root->get_balance()) {
			case equal_height:
			sub_root->set_balance(right_higher);
			shorter = false;
			break;
			case left_higher:
//please fill your code here
			break;
			case right_higher:
//please fill your code here
				break;
			}
		}
	}
	else if (old_data < sub_root->data) {
		result = avl_remove(sub_root -> left,old_data,shorter);
		if(shorter == true)
			switch(sub_root->get_balance()) {
			case equal_height:
				sub_root->set_balance(right_higher);
				shorter = false;
				break;
			case left_higher:
				sub_root->set_balance(equal_height);
				break;
			case right_higher:
				right_balance(sub_root,shorter);
				break;
			}
	}
	else {
//please fill your code here		
	}
	return result;
}
//---------------------------------------------------------
void AVL_tree::rotate_left(AVL_node *&sub_root)
{
	if (sub_root == NULL || sub_root->right == NULL) 
		cout<<"WARNING: program error detected in rotate_left"<<endl;
	else {
		AVL_node *right_tree = sub_root->right;
		sub_root->right = right_tree->left;
		right_tree->left = sub_root;
		sub_root = right_tree;
	}
}
//---------------------------------------------------------
void AVL_tree::rotate_right(AVL_node *&sub_root)
{
	if (sub_root == NULL || sub_root->left == NULL) 
		cout<<"WARNING: program error detected in rotate_right"<<endl;
	else {
		AVL_node *left_tree = sub_root->left;
		sub_root->left = left_tree->right;
		left_tree->right = sub_root;
		sub_root = left_tree;
	}
}
//---------------------------------------------------------	
void AVL_tree::left_balance(AVL_node *&sub_root,
									bool &changeHeight)		
{
	AVL_node *&left_tree = sub_root->left;
	switch (left_tree->get_balance()) {
	case equal_height: 
		left_tree -> set_balance(right_higher);
		changeHeight = false;
		rotate_right(sub_root);
		break;
	case left_higher: 
		sub_root->set_balance(equal_height);
		left_tree->set_balance(equal_height);
		rotate_right(sub_root);
		break;
	case right_higher: 
		AVL_node *sub_tree = left_tree->right;
		switch (sub_tree->get_balance()) {
		case equal_height:
			sub_root->set_balance(equal_height);
			left_tree->set_balance(equal_height);
			break;
		case left_higher:
			sub_root->set_balance(right_higher);
			left_tree->set_balance(equal_height);
			break;
		case right_higher:
			sub_root->set_balance(equal_height);
			left_tree->set_balance(left_higher);
			break;
		}
		sub_tree->set_balance(equal_height);
		rotate_left(left_tree);
		rotate_right(sub_root);
		break;
	}
}
//---------------------------------------------------------
void AVL_tree::right_balance(AVL_node *&sub_root,
									bool &changeHeight)		
{
	AVL_node *&right_tree = sub_root->right;
	switch (right_tree->get_balance()) {
	case equal_height:
		right_tree -> set_balance(left_higher);
		changeHeight = false;
		rotate_left(sub_root);
		break;
	case right_higher:
		sub_root -> set_balance(equal_height);
		right_tree -> set_balance(equal_height);
		rotate_left(sub_root);
		break;
	case left_higher:
		AVL_node *sub_tree = right_tree->left;
		switch (sub_tree->get_balance()) {
		case equal_height:
			sub_root->set_balance(equal_height);
			right_tree->set_balance(equal_height);
			break;
		case left_higher:
			sub_root->set_balance(equal_height);
			right_tree->set_balance(right_higher);
			break;
		case right_higher:
			sub_root->set_balance(left_higher);
			right_tree->set_balance(equal_height);
			break;
		}
		sub_tree->set_balance(equal_height);
		rotate_right(right_tree);
		rotate_left(sub_root);
		break;
	}
}
//---------------------------------------------------------
void AVL_tree::printLNR_recursive(AVL_node *subroot) {
	if (subroot != NULL) {
	printLNR_recursive(subroot->left);
	cout << subroot->data << " ";
	printLNR_recursive(subroot->right);
	}
}

//---------------------------------------------------------
void AVL_tree::printLNR() {
	printLNR_recursive(root);
	cout << endl;
}

#endif //__AVL__CPP__
