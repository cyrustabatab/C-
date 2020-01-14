#ifndef DLL_HPP
#define DLL_HPP


#include <iostream>

//template <typename T>
//class Node {
//    public:
//        Node(T value):value{value},next{nullptr},prev{nullptr}{};
//    private:
//        T value;
//        Node<T>* next,prev;
//
//
//
//
//
//}

template <typename T>
class DLL {
    public:
        DLL(): size{0},head{nullptr},tail{nullptr}{};
        void addFront(T value);
        void addEnd(T value);
        inline bool empty() {return size == 0;}; 
        T removeFront();
        T removeEnd();
        bool contains(T value);
        T remove(int index);
        void insert(int index,T value);
        void display();
    private:

        class Node {
            public:
                Node(T value): value{value},next{nullptr},prev{nullptr}{};
                T value;
                Node *next;
                Node* prev;
        };

        int size;
        Node* head;
        Node* tail;





};



template <typename T>
void DLL<T>::addFront(T value) {

    if(!head) {
        head = new Node{value};
        tail = head;
    } else {
        Node* new_node = new Node{value};
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
    ++size;

}

template <typename T>
void DLL<T>::addEnd(T value) {
    
    if(!tail) {
        tail = new Node{value};
        head = tail;
    } else {
        Node* new_node = new Node{value};
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    ++size;

}

template <typename T>
T DLL<T>::removeEnd() {
     
    if(!empty()) {
        T value{};     
        if(size == 1) {
            value = head->value;
            head = tail = nullptr;
        } else {
             value = tail->value;
            
            Node* temp = tail->prev;
            temp->next = nullptr;

            delete tail;

            tail = temp;
        }

        --size;

        return value;


    }
    
    throw std::runtime_error("Empty Linked List");
}


template <typename T>
bool DLL<T>::contains(T value) {
    
    Node* current = head;

    while(current) {
        
        if(current->value == value)
            return true;

    }
    return false;

}
template <typename T>
T DLL<T>::removeFront() {
    
    if(!empty()) {
        T value = head->value;
        if(size == 1) {
           head = tail = nullptr;
        } else {
        
            Node* temp = head->next;
            delete head;
            head = temp;



        }

        --size;
        return value;



    }

    throw std::runtime_error("Empty Linked List");

}

template <typename T>
void DLL<T>::insert(int index,T value) {
    
    if(index ==0)
        addFront(value);
    else if(index == size) 
        addEnd(value);
    else {

        int i{0};
        Node* current = head; 
        while(current && i != index) {
            ++i;
            current = current->next;
        }

        if(!current) {
            throw std::out_of_range("Index out of bounds");
        }

        
        
        Node* new_node = new Node{value};
        new_node->next = current;
        current->prev->next = new_node;
        new_node->prev = current->prev;
        current->prev = new_node;
        ++size;



    }


}

template <typename T>
T DLL<T>::remove(int index) {
   if(index == 0)  
       return removeFront();
   else if(index == size -1)
       return removeEnd();
   else {
        
       Node* current = head;
       int i{0};

       while(current && i != index) {
            ++i;
            current = current->next;

       }

       if(!current)
           throw std::out_of_range("Index out of bounds");

       current->prev->next = current->next;
       current->next->prev = current->prev;

       delete current;

       --size;

   }


}
template <typename T>
void DLL<T>::display() {
    
    Node* current = head;
    while(current) {
        std::cout << current->value << (current->next ? "->": "\n");
        current = current->next;
    }
}

#endif
