/*
g++ -o ex3_2_a Exercise_3_2_a.cpp
./ex3_2_a
*/

#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

class List{
	private:
		int count;
		Node* pHead;
	public:
		List() {pHead=NULL; count = 0;}
		void addFirst(int newdata) 	{
			Node* pTemp = new Node;
			pTemp->data = newdata;
			pTemp->next = pHead;
			pHead = pTemp;
			count++;
		}
		void display() {
			Node* pTemp = pHead;
			cout << "{";
			while (pTemp!=NULL) {
				cout << pTemp->data;
				if(pTemp->next != NULL)
					cout << ", ";
				pTemp = pTemp->next;
			}
			cout << "}";
		}
		~List() {
			Node* pTemp = pHead;
			while (pTemp!=NULL) {
				pTemp = pTemp->next;
				delete pHead;
				pHead = pTemp;
			}
		}
    };

List* buildPosLinkedList()
{
	List* pList = new List;
    int valid=1;
    char choice;
    int num;
    while (valid) {
        cout << "Do you want to enter a number? (Y/N):";
        cin >> choice;
        if ((choice == 'Y') || (choice == 'y')) {
            cin >> num;
			if (num>0) pList->addFirst(num);
        } else  	valid = 0;
    }
    return pList;
}

int main(){
	List myList = *buildPosLinkedList();
	
	myList.display();
	return 0;
}
