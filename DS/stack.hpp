
//template <typename T>
//class Stack;
//
//template <typename T> class Node {
//    public:
//        Node(T value): value{value}{};
//        friend class Stack<T>;
//    private:
//        Node<T>* next = nullptr;
//        Node<T>* prev = nullptr;
//        T value;
//
//
//};

template <typename T>
class Stack {
    public:
        Stack(): size{0}, tail{nullptr}{};
        inline bool empty() {return size == 0;};
        void push(T value);
        void display();
        T pop();
    private: 
        
        class Node {
            public:
                Node(T value): value{value},next{nullptr} {};
                T value; 
                Node* next;

        }
        int size;
        Node* head;

};



template <typename T>
void Stack<T>::display() {
    
    Node* current = head;

    while(current) {
        std::cout << current->value << (current->next ? "->" : "\n");
        current = current->next;

    }

}

template <typename T>
void Stack<T>::push(T value) {
    if(!head) {
        head = new Node{value};
    } else {
        Node* new_node = new Node{value};
        new_node->next = head;
        head = new_node;
    }

    ++size;

}

template <typename T>
void Stack<T>::pop() {
    
    if(!empty()) {
       
        T value{head->value};
        Node* temp = head->next;
        delete head;
        head = temp
        --size;
        return value;


    }

}


