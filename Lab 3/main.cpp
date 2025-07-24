#include <stdio.h>

#include "TreeSample.cpp"  //include the .cpp file, not the .h file

int main() {
	// Tree<int> aTree;
	// TreeNode<int> *p1, *p2, *p3, *p4, *p5, *p6, *p7;
	
	// aTree.insertAt(NULL, true, 1, p1); //p1 will be the root
	// aTree.insertAt(p1, true, 2, p2);   //p2 is on the left of p1 (root)
	// aTree.insertAt(p1, false, 3, p3);  //p3 is on the right of p1 (root)
	// aTree.insertAt(p2, true, 4, p4);   //p4 is on the left of p2
	// aTree.insertAt(p2, false, 5, p5);  //p5 is on the right of p2
	// aTree.insertAt(p3, true, 6, p6);   //p6 is on the left of p3
	// aTree.insertAt(p3, false, 7, p7);  //p7 is on the right of p3
	// aTree.printLNR(); //should print 4 2 5 1 6 3 7
	// cout << endl;
	/* At this point, the tree is
	           1
			 /   \
		   2	   3
		  / \     / \
		 4	 5	 6	 7
	*/


	// 4.1
	/*
	expression tree 
	(12-7)+(3*(16/4))
	*/
	Tree<string> expressiontree;
	TreeNode<string> *e1, *e2, *e3, *e4, *e5, *e6, *e7, *e8, *e9;
	expressiontree.insertAt(NULL, true, "+", e1);
	expressiontree.insertAt(e1, true, "-", e2);
	expressiontree.insertAt(e1, false, "*", e3);
	expressiontree.insertAt(e2, true, "12", e4);
	expressiontree.insertAt(e2, false, "7", e5);
	expressiontree.insertAt(e3, true, "3", e6);
	expressiontree.insertAt(e3, false, "/", e7);
	expressiontree.insertAt(e7, true, "16", e8);
	expressiontree.insertAt(e7, false, "4", e9);
	// 4.2
	expressiontree.printLNR(); //should print 12 - 7 + 3 * 16 / 4 //inorder
	cout << endl;
	expressiontree.printLRN(); //should print 12 7 - 3 16 4 / * + //postorder
	cout << endl;
	expressiontree.printNLR(); //should print + - 12 7 * 3 / 16 4 //preorder
	cout << endl;
	expressiontree.printNRL(); //should print + - 12 7 * 3 4 16 /
	cout << endl;
	expressiontree.printRNL(); //should print 4 / 16 * 3 + 7 - 12
	cout << endl;
	expressiontree.printRLN(); //should print 4 16 / 3 * 7 - 12 +
	cout << endl;
	// 4.3
	expressiontree.print_tree_height(); //should print 4

	// 4.4
	expressiontree.print_isbalanced(); //should print true

	// 4.5
	expressiontree.printafterswap(); //print NLR after swap

	// 4.6
	expressiontree.printcount_leaves(); // 5

	// 4.7
	expressiontree.delete_leaves_and_printNLR(); //should print 


	return 0;
}