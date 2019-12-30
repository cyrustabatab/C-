#include <iostream>
#include <iomanip>
#include <limits>



int main() {
    
    int i{};

    std::cout << "Enter an integer: ";

    std::cin >> i;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    

    double d{};

    std::cout << "Enter a double: ";

    std::cin >> d;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    char c{};

    std::cout << "Enter a character: ";
    std::cin >> c;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


    std::string s{};

    std::cout << "Enter a string: ";

    std::cin >> s;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');



    std::cout << "You entered\n" << i << ' ' <<  d << ' ' << c << ' ' << s;




}


