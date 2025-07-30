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
    cout << "Insert 13: ";
    tree.insert(13); 
    tree.printLNR();  

    //2.3
    cout << "\n=== Remove Test ===\n";

    int to_remove[] = {13, 4, 21};  
    for (int x : to_remove) {
        cout << "Remove " << x << ": ";
        tree.remove(x);
        tree.printLNR();
    }

    //mix test
    cout << "\n=== Mixed Insert and Remove Test ===\n";
    int rand_ins_val[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60};
    for (int i = 0; i < 12; ++i) {
        cout << "Insert " << rand_ins_val[i] << ": ";
        tree.insert(rand_ins_val[i]);
        tree.printLNR();
    }
    int rand_rem_val[] = {10, 20, 30, 40, 50, 72, 33, 19, 60, 59, 21, 17};
    for (int i = 0; i < 12; ++i) {
        cout << "Remove " << rand_rem_val[i] << ": ";
        tree.remove(rand_rem_val[i]);
        tree.printLNR();
    }
    cout << "Insert multiple 13: ";
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);
    tree.insert(13);

    tree.printLNR();

    for (int i = 0; i < 20; ++i) {
        cout << "Remove 13: ";
        tree.remove(13);
        tree.printLNR();
    }

    int remove_all[] = {1, 5, 13, 15, 25, 35, 45, 55, 60, 71, 87, 91};  
    for (int x : remove_all) {
        cout << "Remove " << x << ": ";
        tree.remove(x);
        tree.printLNR();
    }

    return 0;
}