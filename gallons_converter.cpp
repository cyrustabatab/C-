#include <iostream>
#include <iomanip>
#include <cmath>



int main() {
    
    const short width{15};
    const double liters_per_gallons{3.7854};
    const double quarts_per_gallons{4.0};
    const double ounces_per_gallons{128.0};
    std::cout << "Gallon Converter\n\n";

    std::cout << std::left << std::setw(width) << "Enter Gallons:";
    double gallons{};

    std::cin >> gallons;

    
    double liters{gallons * liters_per_gallons};
    double quarts{gallons * quarts_per_gallons};
    double ounces{gallons * ounces_per_gallons};
    

    liters = std::round(liters * 100) / 100;
    quarts = std::round(quarts * 100) / 100;
    ounces = std::round(gallons * 100) / 100;


    std::cout << std::setw(width) << "Liters:" <<  liters << std::endl;;
    std::cout << std::setw(width) << "Quarts:" <<  quarts << std::endl;;
    std::cout << std::setw(width) << "Ounces:" <<  ounces << std::endl;;
    

    
    std::cout << "\n\nBye!";




}




