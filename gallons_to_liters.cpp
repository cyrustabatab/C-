#include <iostream>
#include <iomanip>
#include <cmath>


int main() {
    
    const double LITERS_PER_GALLON{3.7854};
    std::cout << std::left << "Gallons Converter" << std::endl;

    std::cout << std::setw(15) << "Enter Gallons:";
    
    double gallons{};
    std::cin >> gallons;

    double liters{std::round(LITERS_PER_GALLON * gallons * 100) / 100};

    std::cout << std::setw(15) << "Liters:" <<    liters << std::endl;



}
