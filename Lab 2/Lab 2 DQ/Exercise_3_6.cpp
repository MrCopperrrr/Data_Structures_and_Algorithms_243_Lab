#include "List.cpp"
#include <iostream>
using namespace std;

int main() {

	// 3.6: 
    cout << "=== 3.6 ===" << endl;
    List<int> aList;
    int alist[] = {1, 2, 3, 4, 5, 6, 7, 3, 8, 3, 0, 2};
    for (int i = 0; i < 12; i++) aList.insert(i, alist[i]);
    cout << "aList = ";
	aList.printAll();
    if (aList.remove_by_value(6) == success)
        cout << "Remove 6 in aList => ";
    else
        cout << "6 not removed\n";
	aList.printAll();
    
	List<int> bList;
	int blist[] = {1, 2, 3, 4, 5, 6, 7, 3, 8, 3, 0, 2};
	for (int i = 0; i < 12; i++) bList.insert(i, blist[i]);
    cout << "bList = ";
	bList.printAll();
	if (bList.remove_by_value(3) == success)
		cout << "Remove 3 in bList => ";
	else{
		cout << "Remove 3 in bList => "; 
		bList.printAll();
		cout << "(bList remains unchanged)\n";
	}

	return 0;
}
