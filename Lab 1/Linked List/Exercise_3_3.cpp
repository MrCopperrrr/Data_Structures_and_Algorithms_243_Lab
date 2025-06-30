/*
g++ -o ex3_3 Exercise_3_3.cpp
./ex3_3
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

        int addFirstIfPerfectSquare(int n){
            if(sqrt(n) == round(sqrt(n))){
                addFirst(n);
                return 1;
            } else {
                return 0;
            }
        }
};


int main(){
	List* myList;
    cout << "Enter a number: n = ";
    int n;
    cin >> n;
    int result = myList->addFirstIfPerfectSquare(n);

	myList->display();
	
	return 0;
    
}
