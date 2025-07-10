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

    // 3.5
    cout << "\n=== 3.5 ===" << endl;
    // retrieve gọi ra giá trị tại index
	cout << "Retrieve i: ";
	int val,i1,i2;
    cin >> i1;
	myList.retrieve(i1, val); 
	cout << "Retrieve value: " << val << endl;

    // remove gọi ra giá trị tại index và xóa
	cout << "Remove i: ";
    cin >> i2;
	myList.remove(i2, val); 
	cout << "List after remove: ";
	myList.printAll(); 

	return 0;
}
