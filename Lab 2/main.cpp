#include "List.cpp"
#include <iostream>
using namespace std;

int main() {
	List<int> myList;

	// 3.3
	myList.insert(0, 12);
	myList.insert(1, 5);
	myList.insert(2, 79);
	myList.insert(3, 82);
	myList.insert(4, 21);
	myList.insert(5, 43);
	myList.insert(6, 31);
	myList.insert(7, 35);
	myList.insert(8, 57);

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
    removeList.insert(0, 1);
	removeList.insert(1, 2);
	removeList.insert(2, 3);
	removeList.insert(3, 4);
	removeList.insert(4, 5);
	removeList.insert(5, 6);
	removeList.insert(6, 7);
	removeList.insert(7, 3);
	removeList.insert(8, 8);
	removeList.insert(9, 3);
	removeList.insert(10, 0);
	removeList.insert(11, 2);
    cout << "aList = ";
	removeList.printAll();
	int removeValue;
	cout << "Remove value: ";
	cin >> removeValue;
    if (removeList.remove_by_value(removeValue) == success)
        cout << "Remove " << removeValue << " in aList => ";
    else{
    	cout << "Remove " << removeValue << " in aList =>";
		removeList.printAll();
		cout << " (aList remains unchanged)" << endl;
	}
	removeList.printAll();

	// 3.7
    cout << "\n=== 3.7 ===" << endl;
    List<int> removeLastList;
	removeLastList.insert(0, 1);
	removeLastList.insert(1, 2);
	removeLastList.insert(2, 3);
	removeLastList.insert(3, 4);
	removeLastList.insert(4, 5);
	removeLastList.insert(5, 6);
	removeLastList.insert(6, 7);
	removeLastList.insert(7, 3);
	removeLastList.insert(8, 8);
	removeLastList.insert(9, 9);
	removeLastList.insert(10, 3);
	removeLastList.insert(11, 0);
	removeLastList.insert(12, 0);
	removeLastList.insert(13, 2);
    cout << "aList = ";
    removeLastList.printAll();
	int removeLastValue;
	cout << "Remove last value: ";
	cin >> removeLastValue;
    if (removeLastList.remove_last(removeLastValue) == success)
		cout << "Remove the last " << removeLastValue << " in aList => ";
	else{
		cout << "Remove the last " << removeLastValue << " in aList =>";
		removeLastList.printAll();
		cout << " (aList remains unchanged)" << endl;
	}
	removeLastList.printAll();

	// 3.8
    cout << "\n=== 3.8 ===" << endl;
	List<int> primeList;
	primeList.insert(0, 1);
	primeList.insert(1, 2);
	primeList.insert(2, 8);
	primeList.insert(3, 9);
	primeList.insert(4, 4);
	primeList.insert(5, 0);
	primeList.insert(6, 3);
	primeList.insert(7, 2);
	cout << "aList = ";
	primeList.printAll();
	cout << "Remove prime positions: ";
	primeList.remove_prime_positions();
	cout << "=> ";
	primeList.printAll();

	// 3.9
	cout << "\n=== 3.9 ===\n";
	List<int> allList;
	allList.insert(0, 1);
	allList.insert(1, 2);
	allList.insert(2, 3);
	allList.insert(3, 4);
	allList.insert(4, 5);
	allList.insert(5, 6);
	allList.insert(6, 7);
	allList.insert(7, 3);
	allList.insert(8, 8);
	allList.insert(9, 9);
	allList.insert(10, 3);
	allList.insert(11, 0);
	allList.insert(12, 0);
	allList.insert(13, 2);
	cout << "aList = ";
	allList.printAll();
	int removeAllValue;
	cout << "Remove all value: ";
	cin >> removeAllValue;
	allList.remove_all(removeAllValue);
	cout << "Remove all " << removeAllValue << " in aList => ";
	allList.printAll();
	return 0;
}
