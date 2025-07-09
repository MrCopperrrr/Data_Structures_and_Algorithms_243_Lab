/*
g++ -o ex3_1 Exercise_3_1.cpp
./ex3_1
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
public:
    LinkedList();
    ~LinkedList();
    void display();
    void pushElement(int value); 
    int popElement(); 
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

void LinkedList::pushElement(int value) {
    Node*temp = new Node;
    temp->data = value;
    temp->next = head;
    head = temp;
    count ++;
}

int LinkedList::popElement() {
    if (head == nullptr) return -1;
    Node* temp = new Node;
    int value = head->data;
    temp = head;
    head = head->next;
    delete temp;
    count--;
    return value;
}

int main(){
    LinkedList stack;

    //push
    stack.pushElement(12);
    stack.pushElement(5);
    stack.pushElement(79);
    stack.pushElement(82);
    stack.pushElement(21);
    //pop
    stack.popElement();
    stack.popElement();
    //push
    stack.pushElement(43);
    stack.pushElement(31);
    stack.pushElement(35);
    stack.pushElement(57);
    //display
    stack.display();

    return 0;
}