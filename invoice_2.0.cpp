#include <iostream>
#include <cmath>
#include <iomanip>



int main() {
    
    const short width{27};
    std::cout << "The Invoice Total Calculator 2.0\n\n";

    std::cout << std::left << std::setw(width) << "Enter customer type (r/w/c):";


    char customer_type{};


    customer_type = static_cast<char>(std::cin.get());
    std::cin.ignore(1000,'\n');

    std::cout << std::setw(width) << "Enter Subtotal:";

    double subtotal{};

    std::cin >> subtotal;
    
    double discount_percent{};
    /*
    if(std::tolower(customer_type) == 'r') {
        // if retail
        
        if(subtotal < 100)
            discount_percent = 0.0;
        else if(subtotal >= 100 && subtotal < 250)
            discount_percent = 0.1;
        else
            discount_percent = 0.2;
    } else if(std::tolower(customer_type) == 'w') {
        
        if(subtotal < 500) {
            discount_percent = 0.4;
        } else 
            discount_percent = 0.5;

    } else {
        discount_percent = 0.0;
    }
    */
    

    switch(std::tolower(customer_type)) {
        case 'r':
            if(subtotal < 100)
                discount_percent = 0.0;
            else if(subtotal >= 100 && subtotal < 250)
                discount_percent = 0.1;
            else if(subtotal >= 250 && subtotal < 500)
                discount_percent = 0.2;
            else
                discount_percent = 0.3;
            break;
        case 'w':
            if(subtotal < 500) {
                discount_percent = 0.4;
            } else 
                discount_percent = 0.5;
            break;
        case 'c':
            discount_percent = 0.25;
            break;
        default:
            discount_percent= 0.0; 
            break;


    }


    double discount_amount{discount_percent * subtotal};

    discount_amount = std::round(discount_amount * 100) / 100;

    double invoice_total{subtotal - discount_amount};

    
    std::cout << std::setw(width) << "Discount Percent:" << discount_percent << std::endl;
    std::cout << std::setw(width) <<"Discount Amount:" << discount_amount << std::endl;
    std::cout << std::setw(width) << "Invoice Total:" << invoice_total << std::endl;

    







}
