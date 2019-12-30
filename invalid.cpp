#include <iostream>
#include <iomanip>


int main() {
    
    double num{};

    std::cout << "Enter a number: ";

    if (std::cin >> num) {
        std::cout << "Your number is " << num << std::endl;
    } else
        std::cout << "That's not a valid number" << std::endl;


}
