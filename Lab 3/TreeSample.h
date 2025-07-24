#ifndef __TREESAMPLE__H__
#define __TREESAMPLE__H__

enum Error_code {success,fail,rangeerror,overflow,not_present,
				dupplicated,found};

//---------------------------------------------------------
template<class Node_entry> 
struct TreeNode {
	Node_entry entry;
	TreeNode<Node_entry> *left, *right;
	TreeNode();
	TreeNode(Node_entry item, TreeNode<Node_entry> * left = NULL, TreeNode<Node_entry> * right = NULL);
};

//---------------------------------------------------------
template <class Tree_entry>
class Tree  {
public:
	Tree();
	~Tree();
	
	bool empty();
	int size();
	Error_code insertAt(TreeNode<Tree_entry> *, bool, Tree_entry, TreeNode<Tree_entry> *&);
	void printLNR();
	void printLRN();
	void printNLR();
	void printNRL();
	void printRNL();
	void printRLN();

    void build_tree_from_keyboard ();

	int treeheight();
	void print_tree_height();
	void print_isbalanced();
	void printafterswap();

	
	protected:
	TreeNode<Tree_entry> *root;
	void destroy(TreeNode<Tree_entry> *);
	void printLNR_recursive(TreeNode<Tree_entry> *);
	void printLRN_recursive(TreeNode<Tree_entry> *);
	void printNLR_recursive(TreeNode<Tree_entry> *);
	void printNRL_recursive(TreeNode<Tree_entry> *);
	void printRNL_recursive(TreeNode<Tree_entry> *);
	void printRLN_recursive(TreeNode<Tree_entry> *);
    TreeNode<Tree_entry> * build_tree_from_keyboard_recur ();
	
	int tree_left_height(TreeNode<Tree_entry> *);
	int tree_right_height(TreeNode<Tree_entry> *);
	bool isbalanced(TreeNode<Tree_entry> *);

	void swapleftandright(TreeNode<Tree_entry> *);
};

#endif //__TREESAMPLE__H__