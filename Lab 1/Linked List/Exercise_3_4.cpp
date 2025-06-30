/*
g++ -o ex3_4 Exercise_3_4.cpp
./ex3_4
*/


#include <iostream>
#include <cmath>
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

        void addLast(int n){
            Node* pTemp = new Node;
            pTemp->data = n;
            pTemp->next = NULL;

            if (pHead == NULL) {
                pHead = pTemp;
            } else {
                Node* current = pHead;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = pTemp;
            }
            count++;
        }
};


int main(){
	List* myList;
    myList->addLast(12);
    myList->addLast(6);
    myList->addLast(29);
    myList->addLast(12);
    myList->addLast(51);
    myList->addLast(35);

	myList->display();
	
	return 0;
    
}
