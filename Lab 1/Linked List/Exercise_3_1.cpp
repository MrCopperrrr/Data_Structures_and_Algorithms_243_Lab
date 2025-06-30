/*
g++ -o ex3_1 Exercise_3_1.cpp
./ex3_1
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

int main(){
	List myList;
	myList.addFirst(12);
	myList.addFirst(6);
	myList.addFirst(29);
	myList.addFirst(12);
	myList.addFirst(51);
	myList.addFirst(35);
	myList.addFirst(83);
	myList.addFirst(35);
	myList.addFirst(78);
	myList.display(); 
	return 0;
}
