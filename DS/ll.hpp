#include <iostream>
#include <stdexcept>
#include <string>



template<typename T>
class LinkedList;
template <typename T>
class Node;


template<typename T> std::ostream& operator<<(std::ostream& out,const Node<T>& node);

template <typename T>
class Node {
    public:
        Node(T value): value{value},next{nullptr}{};
        friend class LinkedList<T>;
        friend std::ostream& operator<<<T>(std::ostream& out,const Node<T>& node);
    private:
        T value;
        Node<T>* next;



};

template <typename T>
std::ostream& operator<<(std::ostream& out,const Node<T>& node) {
    
    std::cout << node.value << ' ';

}
template <typename T>
class LinkedList {
    public: 
        LinkedList(): size{0},head{nullptr},tail{nullptr} {};
        ~LinkedList();
        int getSize() {return size;};
        void addFront(T value);
        void addEnd(T value);
        void display();
        void insert(int index,T value);
        T remove(int index);
        T removeFront();
        T removeEnd();
    private:
        int size;
        Node<T>* head;
        Node<T>* tail;



};


template <typename T>
void LinkedList<T>::insert(int index,T value) {
    
    if(index < 0)
        throw std::invalid_argument("Cannot have negative index");

    if(index == 0)
        addFront(value);
    else if(index == size)  
        addEnd(value);
    else {
       int i{0}; 
       Node<T>* current = this->head;
       while(current && i + 1 != index) {
           current = current->next;
           ++i;
       }

       if(!current)
           throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");
        
       Node<T>* new_node = new Node<T>{value};
       new_node->next = current->next;
       current->next = new_node;
       ++size;

    }


    //}
}


template<typename T>
LinkedList<T>::~LinkedList() {
    
    Node<T>* current = head;

    while(current) {
        auto temp = current->next;
        delete current;
        current = temp;

    }

}

template<typename T>
void LinkedList<T>::display() {
    
    Node<T>* current = head;

    while(current)  {
    
        std::cout << current->value << (current->next ? "->": "\n");
        current = current->next;

    }


}

template <typename T>
void LinkedList<T>::addFront(T value) {
    
    if(!head) {
        head = new Node<T>{value}; 
        tail = head;

    } else {
        Node<T>* new_node = new Node<T>{value};
        new_node->next = head;
        if(new_node->next == nullptr) {
           tail= new_node; 
        }
        head = new_node;



    }
    ++size;

}


template <typename T>
void LinkedList<T>::addEnd(T value) {
    
    if(!tail) {
        head = new Node<T>{value};
        tail = head;
    } else {
        Node<T>* new_node = new Node<T>{value};
        tail->next = new_node;
        tail = new_node;

    }

    ++size;

}

template <typename T>
T LinkedList<T>::removeFront() {
    
    if(head) {
        
        auto value = head->value;
        auto new_head = head->next;

        delete head;
        head = new_head;

        return value;
    }

    throw std::runtime_error("Empty List");



}


template <typename T>
T LinkedList<T>::removeEnd() {
    
    if(tail) {
        
        T value = tail->value;
        if(head == tail) {
            head = tail = nullptr;

            
        } else {
            Node<T>* current = head;

            while(current->next != current) {
                current = current->next;
            }
            current->next = nullptr;
        }


        return value;
    }

    throw std::runtime_error("Empty List");

}
template <typename T>
T LinkedList<T>::remove(int index) {
    
    if(index < 0) {
        throw std::invalid_argument("Cannot have negative index")
    }
    if(index == 0) {
        return removeFront();
    } else if(index == size -1) {
        return removeEnd();
    } else {
        
        Node<T>* current = head;
        int i{};
        while(current && i + 1 != index) {
            current = current->next;
            ++i;
        }

        if(!current) {
            throw std::out_of_range("Index " + std::to_string(index) + " out of bounds");

        }

        auto temp = current->next;
        T value = temp->value;
        current->next = current->next->next;
        delete temp;
        
        return value;

    }



}



