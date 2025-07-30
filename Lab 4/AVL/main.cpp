#include "AVL.h"
#include <iostream>
using namespace std;

//2.1
int main() {
	AVL_tree tree;
	int values[] = {71, 1, 4, 13, 87, 91, 72, 33, 19, 60, 59, 21, 17};
	int n = sizeof(values) / sizeof(values[0]);
	for (int i = 0; i < n; ++i) {
		tree.insert(values[i]);
		tree.printLNR();
	}
	return 0;
}