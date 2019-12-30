#include <iostream>

enum class Command: char {view='v',add='a',del='d',exit='x'};

int main() {
    
    char command{};
    std::cout << "Command: ";
    std::cin >> command;


    Command c = static_cast<Command>(command);

    std::cout << static_cast<char>(c) << std::endl;
    

    return 0;
}
