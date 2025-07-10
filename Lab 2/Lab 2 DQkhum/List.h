#ifndef __LIST__H__
#define __LIST__H__

#include <stdio.h>

enum Error_code {
    success,
    fail,
    rangeerror,
    overflow,
    not_present,
    dupplicated,
    found
};

template<class Node_entry> 
struct Node {
    Node_entry entry;
    Node<Node_entry> *next;
    Node();
    Node(Node_entry item, Node<Node_entry> * link = NULL);
};

template <class List_entry>
class List {
public:
    List(); 
    ~List(); 

    void clear(); 
    bool empty(); 
    int size(); 
    Error_code insert(int position, List_entry x); 
    Error_code remove(int position, List_entry &x); 
    Error_code retrieve(int position, List_entry &x); 
    void printAll(); 

    Error_code remove_by_value(List_entry x); 
    Error_code remove_last(List_entry x); 
    void remove_prime_positions(); 
    void remove_all(List_entry x); 

private:
    int count; 
    Node<List_entry> *head; 
    Node<List_entry> *set_position(int position); 
};

#endif // __LIST__H__
