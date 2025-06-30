/*
g++ -o ex3_5 Exercise_3_5.cpp
./ex3_5
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
        void addEvenFirst(int n){
            if (n % 2 == 0) addFirst(n);
            else addLast(n);
        }
};


int main(){
	List* myList;
    
    myList->addEvenFirst(12);
    myList->addEvenFirst(6);
    myList->addEvenFirst(83);
    myList->addEvenFirst(29);
    myList->addEvenFirst(14);
    myList->addEvenFirst(51);
    myList->addEvenFirst(35);

	myList->display();
	
	return 0;
    
}
