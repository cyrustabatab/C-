


template <typename T>
class Queue {
    public:
        Queue(): size{0},head{nullptr},tail{nullptr} {}; 
        inline bool empty() {return size == 0;};
        void enqueue(T value);
        T dequeue();
        void display();
    private:

        class Node {
            public:
                Node(T value): value{value},next{nullptr} {};
                T value;
                Node* next;

        };
        Node* head;
        Node* tail;
        int size;

};


template <typename T>
void Queue<T>::enqueue(T value) {
    
    Node* new_node = new Node{value};
    if(!tail) {
        head = tail = new_node;
    } else {
       
        tail->next = new_node;
        tail = new_node;

    }
    ++size;

}


template <typename T>
T Queue<T>::dequeue() {
    if(!empty()) {

        T value = head->value;

        Node* temp = head->next;
        delete head;
        --size;
        if(size == 0) 
            tail = nullptr;
        head = temp;


        return value;
        


    } 


    throw std::runtime_error("Empty Queue");

}


template <typename T>
void Queue<T>::display() {
    
    Node* current = head;

    while(current) {
        
        std::cout << current->value << (current->next ? "->" : "\n");
        current = current->next;

    }


}



