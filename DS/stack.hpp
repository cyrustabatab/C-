
template <typename T>
class Stack;

template <typename T> class Node {
    public:
        Node(T value): value{value}{};
        friend class Stack<T>;
    private:
        Node<T>* next = nullptr;
        Node<T>* prev = nullptr;
        T value;


};

template <typename T>
class Stack {
    public:
        Stack(): size{0}, tail{nullptr}{};
        void push(T value);
        void display();
        T pop();
    private: 

        int size;
        Node<T>* tail;

};



template <typename T>
void Stack<T>::push(T value) {
    if(!tail) {
        tail = new Node<T>{value};
    } else {
        tail->next = new Node<T>{value};
        tail = tail->next;
    }

    ++size;

}

template <typename T>
void Stack<T>::push(T value) {


