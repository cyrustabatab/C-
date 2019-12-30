#include <iostream>
#include <climits>
#include <cfloat>


const double pi {3.1415926};

int main() {

    
    std::cout << "char: " << sizeof(char) << " bytes." << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes." << std::endl;
    std::cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << std::endl;
    std::cout << "short: " << sizeof(short) << " bytes." << std::endl;
    std::cout << "long: " << sizeof(long) << " bytes." << std::endl;
    std::cout << "long long: " << sizeof(long long) << " bytes." << std::endl;



    std::cout << "int max: " << INT_MAX << std::endl;


}
