#include <iostream>
#include <cstdlib>
#include <ctime>


int main() {

    int elapsed_seconds{std::time(nullptr)};

    std::srand(elapsed_seconds);

    int die1{std::rand() % 6 + 1};

    int die2{std::rand() % 6 + 1};


    std::cout << "Your rolls " << die1 << " " << die2 << std::endl;


}
