#include <iostream>
#include <iomanip>
#include <cmath>



int main() {
    
    const short width{18};

    std::cout << "Invoice Total Calculator 1.0\n\n";

    std::cout << std::left << std::setw(width) << "Enter subtotal:"; 

    double subtotal{};

    std::cin >> subtotal;

    double discount_percent{};


    if(subtotal >= 200)
        discount_percent = 0.2;
    else if (subtotal >= 100)
        discount_percent = 0.1;
    else
        discount_percent = 0.05;


    double discount_amount{discount_percent *  subtotal};
    
    discount_amount = std::round(discount_amount * 100) / 100;
    
    double total{subtotal - discount_amount};
    
    total = std::round(total * 100) / 100; 


    std::cout << std::setw(width) << "Discount Percent:" << discount_percent << std::endl;
    std::cout << std::setw(width) << "Discount Amount:" << discount_amount << std::endl;
    std::cout << std::setw(width) << "Invoice total:" << total << std::endl;



    std::cout << "\n\nBye!\n";

    std::cin.ignore(1000,'\n');
    std::cout << "Press Enter to Exit Program...";
    std::cin.get();



    



}
