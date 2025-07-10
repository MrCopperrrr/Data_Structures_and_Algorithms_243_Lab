#include "List.cpp"
#include <iostream>
using namespace std;

int main() {
	List<int> myList;

	// 3.3 hiện thực list
	int initial[] = {12, 5, 79, 82, 21, 43, 31, 35, 57};
	for (int i = 0; i < 9; i++) myList.insert(i, initial[i]); 

	// 3.4 in list 
    cout << "=== 3.4 ===" << endl;
	cout << "List: ";
	myList.printAll(); 

	return 0;
}
