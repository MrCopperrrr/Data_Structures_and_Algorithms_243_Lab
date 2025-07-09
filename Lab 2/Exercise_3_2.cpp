/*
g++ -o ex3_2 Exercise_3_2.cpp
./ex3_2
*/

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class LinkedList{
private:
    int count;
    Node* head;
    Node* tail;
public:
    LinkedList();
    ~LinkedList();
    void display();
    void encodeElement(int value);
    int decodeElement();
};

LinkedList::LinkedList() {
    count = 0;
    head = nullptr;
}

LinkedList::~LinkedList() {
    Node* curr = head;
    while(curr != nullptr) {
        curr = curr->next;
        delete head;
        head = curr;
    }
}

void LinkedList::display(){
    Node* temp = head;
			cout << "{";
			while (temp!=NULL) {
				cout << temp->data;
				if(temp->next != NULL)
					cout << ", ";
				temp = temp->next;
			}
			cout << "}";
}

void LinkedList::encodeElement(int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
    count++;
}

int LinkedList::decodeElement() {
    if(head == nullptr) return -1;
    Node* temp = head;
    int value = head->data;
    head = head->next;
    if(head == nullptr) tail = nullptr;
    delete temp;
    count--;
    return value;

}



int main(){
    LinkedList queue;

    //push
    queue.encodeElement(12);
    queue.encodeElement(5);
    queue.encodeElement(79);
    queue.encodeElement(82);
    queue.encodeElement(21);
    //pop
    queue.decodeElement();
    queue.decodeElement();
    //push
    queue.encodeElement(43);
    queue.encodeElement(31);
    queue.encodeElement(35);
    queue.encodeElement(57);
    
    //display
    queue.display();

    return 0;
}