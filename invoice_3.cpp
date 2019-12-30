#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>


int main() {
    std::cout << "The Invoice 3.0 Program\n\n";
    
    const int width{27};
    char choice{};
    while(true) {
        std::cout << std::left << std::setw(width) << "Enter Customer Type (r/w):";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


        if(std::tolower(choice) == 'r' || std::tolower(choice) == 'w')
            break;
        else
            std::cout << "Please enter either \'r\' or \'w\' only!" << std::endl;
        

    }
    
    double subtotal{};
    while(true) {
        std::cout << std::setw(width) << "Enter Subtotal: ";
        
        std::cin >> subtotal;

        if(std::cin.fail()) {
            std::cout << "Please enter a number!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        } else if(std::cin.bad()) {
            std::cout << "Unrecoverable Error. Exiting Program"; 
            return 1;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        break;

    }
    
    double discount_percent{};
    switch (std::tolower(choice)) {
    
        case 'r':
            if (subtotal < 100) {
                discount_percent = 0.0;
            } else if(subtotal < 250 && subtotal >= 100)
                discount_percent = 0.1;
            else
                discount_percent = 0.2;
            break;
        case 'w':
            if (subtotal < 500)
                discount_percent = 0.4;
            else
                discount_percent = 05.;
            break;
        default:
            discount_percent = 0.0;
            break;

    }


    double discount_amount{subtotal *discount_percent};
    double invoice_total{subtotal - discount_amount};


    const int col1{18};
    const int col2{8};


    std::cout << std::fixed << std::setprecision(2) << std::endl
        << "INVOICE" << std::endl
        << std::left << std::setw(col1) << "Subtotal:" 
        << std::right << std::setw(col2) << subtotal << std::endl
        << std::left << std::setw(col1) << "Discount Percent:"
        << std::right << std::setw(col2) << discount_percent << std::endl
        << std::left << std::setw(col1) << "Discount Amount:"
        << std::right << std::setw(col2) << discount_amount << std::endl
        << std::left << std::setw(col1) << "Invoice Total:"
        << std::right << std::setw(col2) << invoice_total << std::endl;



}
