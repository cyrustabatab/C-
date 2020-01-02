#include <cstring>
#include <iostream>



int main() {
    
    const int size{20};

    char string[size]{"Grace Hopper"};
    
    std::cout << size << " elements, string length of " << std::strlen(string) << std::endl;

    size_t length{std::strlen(string)};



}






