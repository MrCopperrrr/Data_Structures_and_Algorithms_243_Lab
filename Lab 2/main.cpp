#include "List.cpp"
#include <iostream>
using namespace std;

int main() {
	List<int> myList;

	// 3.3
	int initial[] = {12, 5, 79, 82, 21, 43, 31, 35, 57};
	for (int i = 0; i < 9; i++) myList.insert(i, initial[i]); 

	// 3.4
    cout << "=== 3.4 ===" << endl;
	cout << "List: ";
	myList.printAll(); 

	// 3.5
    cout << "\n=== 3.5 ===" << endl;
	cout << "Retrieve i: ";
	int val,i1,i2;
    cin >> i1;
	myList.retrieve(i1, val); 
	cout << "Retrieve value: " << val << endl;

	cout << "Remove i: ";
    cin >> i2;
	myList.remove(i2, val); 
	cout << "List after remove: ";
	myList.printAll(); 

	// 3.6: 
    cout << "\n=== 3.6 ===" << endl;
    List<int> removeList;
    int values[] = {1, 2, 3, 4, 5, 6, 7, 3, 8, 3, 0, 2};
    for (int i = 0; i < 12; i++) removeList.insert(i, values[i]);
    cout << "Before: ";
	removeList.printAll();
    if (removeList.remove_by_value(6) == success)
        cout << "=> Removed 6" << endl;
    else
        cout << "6 not removed\n"; //duplicate
    cout << "After: ";
	removeList.printAll();

	// 3.7
    cout << "\n=== 3.7 ===" << endl;
    List<int> removeLastList;
    int removeLastValues[] = {1, 2, 3, 4, 5, 6, 7, 3, 8, 9, 3, 0, 0, 2};
    for (int i = 0; i < 14; i++) removeLastList.insert(i, removeLastValues[i]);
    cout << "Before: ";
    removeLastList.printAll();
    if(removeLastList.remove_last(3) == success)
        cout << "=> Removed last value 3" << endl;
    else
        cout  << "3 not removed\n";
    cout << "After: ";
    removeLastList.printAll();

	// 3.8
    cout << "\n=== 3.8 ===" << endl;
	List<int> primeTestList;
	int vals[] = {1, 2, 8, 9, 4, 0, 3, 2};
	for (int i = 0; i < 8; i++) primeTestList.insert(i, vals[i]); 
	cout << "Before: ";
	primeTestList.printAll();
	primeTestList.remove_prime_positions(); 
    cout << "=> Removed prime positions" << endl;
	cout << "After: ";
	primeTestList.printAll();

	// 3.9
	cout << "\n=== 3.9 ===\n";
	List<int> allList;
	int bigList[] = {1,2,3,4,5,6,7,3,8,9,3,0,0,2};
	for (int i = 0; i < 14; i++) allList.insert(i, bigList[i]); 
	cout << "Before: ";
	allList.printAll();
	allList.remove_all(3); 
    cout << "=> Removed all 3 from the list" << endl;
	cout << "After: ";
	allList.printAll();

	return 0;
}
