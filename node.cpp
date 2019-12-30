#include <iostream>

struct Node {
    private:
        int value;    
        Node* next;
    public:
        Node(int value) {
            this->value = value;
            this->next = nullptr;
        }


        Node* set_next(Node n1) {
            next = &n1;

            return next;

        }

        Node* get_next() {
            return next;

        }

        int get_value() {
            return value;

        }


};


int main() {

    
    Node n1{1};
    Node n2{2};
    Node n3{3};

    
    n1.set_next(n2);
    n2.set_next(n3);
    

    std::cout << n1.get_value() << ' ' << (n1.get_next())->get_value()<< std::endl;


}
