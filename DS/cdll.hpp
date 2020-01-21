#include <iostream>



template <typename T>
class CDLL {
    public: 
        CDLL();
        inline bool empty() {return size == 0;};
        void addFront(T value); 
        void addEnd(T value);
        void insert(int index,T value);
        T remove(int index);
        T removeEnd();
        T removeFront();
        void display();
    private:

        class Node {
            public:
                Node(): value{},next{nullptr},prev{nullptr} {};
                Node(T value): value{value},next{nullptr},prev{nullptr} {};
                T value;
                Node* next;
                Node* prev;

        };
        void _insert(Node* node,Node* new_node);
        void _remove(Node* node);
        int size;
        Node*  head;




};



template <typename T>
CDLL<T>::CDLL(): size{0} {
   
    head = new Node{};
    head->next = head;
    head->prev = head;

}


template <typename T>
void CDLL<T>::insert(int index,T value) {
    
    if(index ==0) {
        addFront(value);
    }
    else if(index == size) {
        addEnd(value);
    } else {

        int i{0};
        bool first{true};
        Node* current = head;

        while((current != head || first) && i != index) {
            if(first) 
                first = false;

            current = current->next;
            ++i;
    }

    }



}
template <typename T>
void CDLL<T>::addFront(T value) {
    
    Node* new_node = new Node{value};

    _insert(head,new_node);
}


template <typename T>
void CDLL<T>::addEnd(T value) {
    
    Node* new_node = new Node{value};
    
    _insert(head->prev,new_node);
}


template <typename T>
void CDLL<T>::_insert(Node* node,Node* new_node) {
    new_node->prev = node; 
    new_node->next = node->next;
    node->next->prev = new_node;
    node->next = new_node;

    ++size;

}


template <typename T>
T CDLL<T>::remove(int index) {
    
    if(index == 0) {
        return removeFront();
    } else if(index == size - 1) {
        return removeEnd();
    } else {
        
        int i{0};
        
        Node* current = head->next;

        while(current != head && i != index) {
            current = current->next;
            ++i;
        }

        if(current == head) {
            throw std::out_of_range("index out of bounds");
        }

        T value = current->value;
        _remove(current);
        
        return value;

    }


}

template <typename T>
T CDLL<T>::removeEnd() {

    if(!empty()) {
        
        T value{head->prev->value};
        _remove(head->next);
        return value;

    }

    throw std::runtime_error("Empty Linked List");
}

template <typename T>
T CDLL<T>::removeFront() {
    
    if(!empty()) {
        
        T value{head->next->value};
        _remove(head->next);
        return value;

    }

    throw std::runtime_error("Empty Linked List");

}

template <typename T>
void CDLL<T>::_remove(Node* node) {
    
    node->prev->next = node->next;
    node->next->prev = node->prev;
    --size;

}


template <typename T>
void CDLL<T>::display() {
    
    Node* current = head->next;
    while(current != head) {
        
        std::cout << current->value << (current->next != head ? "->" : "\n");
        current = current->next;
    }


}

