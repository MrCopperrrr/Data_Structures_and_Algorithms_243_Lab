#include "AVL.h"
#include <iostream>
using namespace std;

int main() {
    //2.1
    AVL_tree tree;
    int values[] = {71, 1, 4, 13, 87, 91, 72, 33, 19, 60, 59, 21, 17};
    int n = sizeof(values) / sizeof(values[0]);

    cout << "=== Insert Test ===\n";
    for (int i = 0; i < n; ++i) {
        cout << "Insert " << values[i] << ": ";
        tree.insert(values[i]);
        tree.printLNR();
    }
    //2.2
    cout << "\n=== Duplicate Insert Test ===\n";
    tree.insert(13); 
    tree.printLNR();  

    //2.3
    cout << "\n=== Remove Test ===\n";

    int to_remove[] = {13, 4};  
    for (int x : to_remove) {
        cout << "Remove " << x << ": ";
        tree.remove(x);
        tree.printLNR();
    }

    return 0;
}