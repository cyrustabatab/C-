#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>



int main() {
    
    std::cout << "The Future Value Calculator\n\n";
    
    const unsigned char width{21};
    
    double monthly_investment{};
    double yearly_rate{};
    int years{};
    char choice{};
    do {
        std::cout << std::left << std::setw(width) << "Enter Monthly Investment:"; 
        std::cin >> monthly_investment;
        
        std::cout << std::setw(width) << "Enter Yearly Investment Rate:"; 
        std::cin >> yearly_rate;

        std::cout << std::setw(width) << "Enter Number of Years:"; 

        std::cin >> years;

        double monthly_rate{(static_cast<double>(years)/12)/100};

        int months{years * 12};

        double future_value{};

        for(int i= 1;i <= months;++i)
        {

            if(i % 12 == 0) {
                std::cout << std::setw(30) << "Year   =   "  + std::to_string(i /12) << "Future Value = " << std::round(future_value * 100)/100 << std::endl;
            }
            future_value = (future_value + monthly_investment) * (1 +monthly_rate);

        }

        
        //round to 2 decimal places
        


        std::cout << "Continue(y/n): ";
        choice = std::cin.get();
        std::cin.ignore(100,'\n');

    } while(std::tolower(choice) == 'y');


}


