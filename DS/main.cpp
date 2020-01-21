#include "cdll.hpp"
#include <iostream>


int main() {

    
    CDLL<int> ll;

    ll.addFront(4);
    ll.addFront(6);
    ll.addEnd(3);
    ll.display();
    std::cout << ll.removeFront() << std::endl;
    ll.display();
    ll.remove(3);
    //DLL<int> ll;
    //ll.addFront(4);
    //ll.display();
    //ll.addEnd(6);
    //ll.display();
    //ll.addFront(3);
    //ll.display();

    //std::cout <<ll.removeFront() << std::endl;
    //ll.display();

    //ll.addFront(5);
    //ll.insert(2,10);
    //ll.display();
    //

    //ll.addFront(4);
    //ll.addEnd(6);
    //ll.addEnd(7);
    //ll.addEnd(10);
    //ll.addFront(3);
    //ll.insert(4,2);
    //ll.display();
    //ll.remove(1);
    //ll.display();


}
