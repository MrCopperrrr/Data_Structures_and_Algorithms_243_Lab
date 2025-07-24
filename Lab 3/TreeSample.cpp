#ifndef __TREESAMPLE__CPP__
#define __TREESAMPLE__CPP__

// TreeSample.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#include "TreeSample.h"

//---------------------------------------------------------
template<class Node_entry>
TreeNode<Node_entry>::TreeNode() {
	left = right = NULL;
}

//---------------------------------------------------------
template<class Node_entry>
TreeNode<Node_entry>::TreeNode(Node_entry item, TreeNode<Node_entry> * left, TreeNode<Node_entry> *right) {
	this->entry = item;
	this->left = left;
	this->right = right;
}

//---------------------------------------------------------
template<class Tree_entry>
Tree<Tree_entry>::Tree() {
	root = NULL;
}

//---------------------------------------------------------
template<class Tree_entry>
Tree<Tree_entry>::~Tree() {
	destroy(root);
	root = NULL;
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::destroy(TreeNode<Tree_entry> *subroot) {
	if (subroot != NULL) {
		destroy(subroot->left);
		destroy(subroot->right);
		delete subroot;
	}
}

//---------------------------------------------------------
template<class Tree_entry>
int Tree<Tree_entry>::size() {
	return 0;
}

//---------------------------------------------------------
template<class Tree_entry>
Error_code Tree<Tree_entry>::insertAt(TreeNode<Tree_entry> *parent, 
	bool left_or_right, Tree_entry x, TreeNode<Tree_entry> *&new_node)
{
	//This method make a new node of value x and insert into the left or 
	//the right of the parent node.
	//If the parent is NULL, and the root of the tree is NULL, the new node 
	//becomes the root of the tree
	//If the parent is not NULL, and the left_or_right is true (false), 
	//and the left (right) child of parent is NULL, 
	//the new node is added to the left (right) of the parent
	//The return value is success for those cases and the new_node points to the new node.
	//Otherwise, the return value is fail and the new_node is unchanged
	if (parent == NULL) {
		if (root != NULL)
		return fail;
	} else {
		if ((left_or_right && (parent->left != NULL))
			|| (!left_or_right && (parent->right != NULL)))
			return fail;
	}
	
	new_node = new TreeNode<Tree_entry>(x);
	if (parent == NULL) {
		root = new_node;
	} else {
		if (left_or_right)
			parent->left = new_node;
		else
			parent->right = new_node;
	}
	return success;
}

//---------------------------------------------------------
template<class Tree_entry>
bool Tree<Tree_entry>::empty() {
	return (root==NULL);
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printLNR_recursive(TreeNode<Tree_entry> *subroot) {
	if (subroot != NULL) {
	printLNR_recursive(subroot->left);
	cout << subroot->entry << " ";
	printLNR_recursive(subroot->right);
	}
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printLNR() {
	printLNR_recursive(root);
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printLRN_recursive(TreeNode<Tree_entry> *subroot){
	if(subroot != NULL){
		printLRN_recursive(subroot->left);
		printLRN_recursive(subroot->right);
		cout << subroot->entry << " ";
	}
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printLRN(){
	printLRN_recursive(root);
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printNLR_recursive(TreeNode<Tree_entry> *subroot){
	if(subroot != NULL){
		cout << subroot->entry << " ";
		printNLR_recursive(subroot->left);
		printNLR_recursive(subroot->right);
	}
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printNLR(){
	printNLR_recursive(root);
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printNRL_recursive(TreeNode<Tree_entry> *subroot){
	if(subroot != NULL){
		cout << subroot->entry << " ";
		printNRL_recursive(subroot->right);
		printNRL_recursive(subroot->left);
	}
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printNRL(){
	printNRL_recursive(root);
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printRNL_recursive(TreeNode<Tree_entry> *subroot){
	if(subroot != NULL){
		printRNL_recursive(subroot->right);
		cout << subroot->entry << " ";
		printRNL_recursive(subroot->left);
	}
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printRNL(){
	printRNL_recursive(root);
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printRLN_recursive(TreeNode<Tree_entry> *subroot){
	if(subroot != NULL){
		printRLN_recursive(subroot->right);
		printRLN_recursive(subroot->left);
		cout << subroot->entry << " ";
	}
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printRLN(){
	printRLN_recursive(root);
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::build_tree_from_keyboard () {
	root = build_tree_from_keyboard_recur() ;
}

//---------------------------------------------------------
template<class Tree_entry>
TreeNode<Tree_entry> * Tree<Tree_entry>::build_tree_from_keyboard_recur () {
	char ans;
	cout << "Enter more (Y/N)? ";
	cin >> ans;
	if (ans == 'Y') {
		Tree_entry data;
		cout << "Enter an entry: ";
		cin >> data;
		TreeNode<Tree_entry> * p = new TreeNode<Tree_entry>(data);
		cout << "Enter the left sub-tree of " << data << "\n";
		p->left = build_tree_from_keyboard_recur ();
		cout << "Enter the right sub-tree of " << data << "\n";
		p->right = build_tree_from_keyboard_recur ();
		return p;
	}
	return NULL;
}

#endif //__TREESAMPLE__CPP__