/*
g++ -o ex3_6 Exercise_3_6.cpp
./ex3_6
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
        int addPost(int n, int index){
            if (index < 1 || index > count + 1) { //bắt đầu ở 1
                return 0;
            }
            Node* pTemp = new Node;
            pTemp->data = n;
            if (index == 1) { //add first
                pTemp->next = pHead;
                pHead = pTemp;
            } else {
                Node* current = pHead;
                if(pHead == NULL) return 0;

                //duyệt đến vị trí index - 1
                for (int i = 1; i < index -1; i++) {
                    if(current == NULL) return 0;
                    current = current->next;
                }
                pTemp->next = current->next;
                current->next = pTemp;
            }
        count++;
        return 1;
        }
};

int main(){
	List myList;
    myList.addFirst(3);
    myList.addFirst(2);
    myList.addFirst(1);

    myList.display();
    cout << endl;

    int result = myList.addPost(4, 2);
	myList.display(); 
	return 0;
}
