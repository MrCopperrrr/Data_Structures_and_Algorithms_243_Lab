#ifndef __AVL__H__
#define __AVL__H__

enum Error_code {success,fail,rangeerror,overflow,not_present,
				dupplicated,found};
enum Balance_factor {left_higher,equal_height,right_higher};
//---------------------------------------------------------
struct AVL_node {
	int data;
	AVL_node *left;
	AVL_node *right;
	Balance_factor balance;
	AVL_node();
	AVL_node(const int &x);
	void set_balance(Balance_factor b);
	Balance_factor get_balance() const;
};
//---------------------------------------------------------
class AVL_tree {
public:
	AVL_tree();
	~AVL_tree();
	Error_code insert(const int &new_data);
	Error_code remove(const int &old_data);
	bool empty();
	void printLNR();
private: 
	Error_code avl_insert(AVL_node *&sub_root,
							const int &new_data, bool &taller);
	Error_code avl_remove(AVL_node *&sub_root,
							const int &old_data,bool &shorter);
	void rotate_left(AVL_node *&sub_root);
	void rotate_right(AVL_node *&sub_root);
	void left_balance(AVL_node *&sub_root,bool &changeHeight);	
	void right_balance(AVL_node *&sub_root,bool &changeHeight);
	
	AVL_node *root;
	void destroy(AVL_node *);
	void printLNR_recursive(AVL_node *);
};

#endif //__AVL__H__
