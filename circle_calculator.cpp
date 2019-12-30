#include <iostream>
#include <iomanip>
#include <cmath>



int main() {
    
    const double pi{3.14159265};
    
    std::cout << "Circle Calculator\n" << std::endl;


    std::cout << "Enter radius: ";

    double radius{};
    std::cin >> radius;
    
    double diameter{2 * radius};

    double circumference{2 * pi * radius};

    double area{pi * std::pow(radius,2)};


    circumference = std::round(circumference * 100) / 100;
    area = std::round(area * 100) / 100;


    std::cout << std::left << std::setw(15) << "Diameter:" << diameter << std::endl;
    std::cout << std::setw(15) << "Cirumference:" << circumference << std::endl;
    std::cout << std::setw(15) << "Area:" << area << std::endl;


    


}





