#include <iostream>
#include "node.hpp"






template <typename T>
class LinkedList {
    public:
        LinkedList(): size{0},head{nullptr},tail{nullptr}{};
        void addFront(T value);
        void addEnd(T value);
        unsigned int getSize() {return size;};
        void display();
    private:
        unsigned int size;
        Node<T>* head;
        Node<T>* tail;

};




template <typename T>
void LinkedList<T>::display() {
    
    Node<T>* current = head;

    while(current != nullptr) {
        std::cout << current->value << (current->next ? "->": "\n");
        current = current->next;
    }

}


template <typename T>
void LinkedList<T>::addEnd(T value) {
    Node<T>* new_node =  new Node<T>{value};
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;

    }

    size++;


}




template <typename T>
void LinkedList<T>::addFront(T value) {
    Node<T>* new_node =  new Node<T>{value};
    if(head == nullptr) {
        head = new_node;
        tail = new_node;
    } else {
       new_node->next = head;
       head = new_node;


    }

    size++;

}



