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

//---------------------------------------------------------
template<class Tree_entry>
int Tree<Tree_entry>::treeheight() {
	if(root == NULL) return 0;
	int left_height = tree_left_height(root->left);
	int right_height = tree_right_height(root->right);
	return max(left_height, right_height) + 1;
}

//---------------------------------------------------------
template<class Tree_entry>
int Tree<Tree_entry>:: tree_left_height(TreeNode<Tree_entry> *subroot) {
	if(subroot != NULL){
		return tree_left_height(subroot->left) + 1;
	}
	return 0;
}

//---------------------------------------------------------
template<class Tree_entry>
int Tree<Tree_entry>:: tree_right_height(TreeNode<Tree_entry> *subroot) {
	if(subroot != NULL){
		return tree_right_height(subroot->right) + 1;
	}
	return 0;
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::print_tree_height() {
	int height = treeheight();
	cout << "The height of the tree is: " << height << endl;
}

//---------------------------------------------------------
template<class Tree_entry>
bool Tree<Tree_entry>::isbalanced(TreeNode<Tree_entry> *root) {
	if(abs(tree_left_height(root) - tree_right_height(root)) <= 1) {
		if(root->left != NULL && !isbalanced(root->left)) return false; //neu left con khong can bang
		if(root->right != NULL && !isbalanced(root->right)) return false; //neu right con khong can bang
		return true;
	}
	return false;
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::print_isbalanced() {
	if(isbalanced(root)) {
		cout << "The tree is balanced." << endl;
	} else {
		cout << "The tree is not balanced." << endl;
	}
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::swapleftandright(TreeNode<Tree_entry> *subroot) {
	if (subroot != NULL) {
		TreeNode<Tree_entry> *temp = subroot->left;
		subroot->left = subroot->right;
		subroot->right = temp;
		swapleftandright(subroot->left);
		swapleftandright(subroot->right);
	}
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>:: printafterswap(){
	swapleftandright(root);
	cout << "Print after swap (NLR): ";
	printNLR();
	cout << endl;
}

//---------------------------------------------------------
template<class Tree_entry>
int Tree<Tree_entry>::count_leaves_recursive(TreeNode<Tree_entry> *subroot) {
	if(subroot == NULL) return 0;
	if(subroot->left == NULL && subroot->right == NULL)
		return 1;
	return count_leaves_recursive(subroot->left) + count_leaves_recursive(subroot->right);	
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::printcount_leaves() {
	cout << "Number of leaves in the tree: ";
	cout << count_leaves_recursive(root) << endl;
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::delete_leaves(TreeNode<Tree_entry>* &subroot) {
	if(subroot == NULL) return;
	if(subroot->left == NULL && subroot->right == NULL) {
		delete subroot;
		subroot = NULL;
		return;
	}
	delete_leaves(subroot->left);
	delete_leaves(subroot->right);
	
}

//---------------------------------------------------------
template<class Tree_entry>
void Tree<Tree_entry>::delete_leaves_and_printNLR() {
    swapleftandright(root);      // đảo cây để xóa cho giống vd
    delete_leaves(root);         
    cout << "Print NLR after deleting all leaves: ";
    printNLR();
    cout << endl;
}

// LinkList implementation
template <class T>
LinkList<T>::~LinkList() {
    ListNode<T> *cur = head;
    while (cur) {
        ListNode<T> *tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

template <class T>
void LinkList<T>::append(const T& value) {
    ListNode<T> *node = new ListNode<T>(value);
    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

template <class T>
void LinkList<T>::print() const {
    ListNode<T> *cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

// Tree LNR to list
template<class Tree_entry>
void Tree<Tree_entry>::tree_to_list_LNR(TreeNode<Tree_entry> *subroot, LinkList<Tree_entry>& list) {
    if (subroot == NULL) return;
    tree_to_list_LNR(subroot->left, list);
    list.append(subroot->entry);
    tree_to_list_LNR(subroot->right, list);
}

template<class Tree_entry>
void Tree<Tree_entry>::to_list_LNR(LinkList<Tree_entry>& list) {
    tree_to_list_LNR(root, list);
}

#endif //__TREESAMPLE__CPP__