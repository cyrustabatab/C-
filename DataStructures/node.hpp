#ifndef NODE_HPP
#define NODE_HPP
template <typename T>
class Node {
    public:
        T value;
        Node<T>* next;
        Node(T value): value{value},next{nullptr}{};
    private:
        


};


#endif
