#include <iostream>
#include <iomanip>
#include <cmath>


int main() {
    
    const double PI{3.14159265};
    const char width{15};
    std::cout << "Circle Calculator\n\n";
    
    char choice{};

    double radius{-1};
    double diameter{};
    double circumference{};
    double area{};
    do {
        
         
        while(true)  {
            std::cout << std::left << std::setw(width) << "Enter Radius:";

            std::cin >> radius;

            if (radius < -1)
                std::cout << "Radius most be non-negative\n";
            else
                break
        }

        diameter = radius * 2;

        circumference = 2 * PI * radius;
        circumference = std::round(circumference * 100) / 100;
        area = std::pow(radius,2) * PI;
        area = std::round(area * 100) / 100;

        
        std::cout << std::setw(width) << "Diameter:" << diameter << std::endl;
        std::cout << std::setw(width) << "Circumference:" << circumference << std::endl;
        std::cout << std::setw(width) << "Area:" << area << std::endl;





    } while(std::tolower(choice) == 'y');




}








