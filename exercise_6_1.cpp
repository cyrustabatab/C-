#include <vector>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

template <typename T>
void getValidNumber(std::string message,const int width, T& value) {
    
    while(true) {
        std::cout << std::setw(width) << message + ':';

        if(std::cin >> value) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            return;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Please enter a number!\n";
        }

    }



}

int main() {
    

    const int width{29};
    std::cout << "The Future Value Calculator\n\n";
    

    double monthly_investment{},yearly_interest_rate{};
    int years{};
    double future_value{};
    char choice{};
    
    std::vector<double> monthly_investments;
    std::vector<double> yearly_interest_rates;
    std::vector<int> num_years;
    std::vector<double> future_values;

    std::cout << std::left;
    while(true) {
        
    
        getValidNumber("Enter Monthly Investment",width,monthly_investment);
        
        monthly_investments.push_back(monthly_investment);
        getValidNumber("Enter Yearly Interest Rate",width,yearly_interest_rate);
        yearly_interest_rates.push_back(yearly_interest_rate);

        getValidNumber("Enter Number of Years",width,years);
        num_years.push_back(years);

        
        double monthly_rate{yearly_interest_rate /12.0 /100.0};
        int months{years * 12};

        for(size_t i=1;i <= months;++i)
            future_value = (future_value + monthly_investment) * (1 + monthly_rate);

        
        future_value = std::round(future_value * 100)/100;
            
        future_values.push_back(future_value);
        std::cout << std::setw(width) << "Future Value:" << future_value << std::endl << std::endl;

        
        bool leave{false};
        
        
        while(true) {
            std::cout << "Continue? (y/n): ";

            std::cin >> choice;

            if(choice == 'n') {
                leave = true;
                break;
            } else if(choice == 'y') {
                break;
            } else {
                std::cout << "Invalid Choice!\n";
            }

            std::cout << std::endl;
        
        }
        
        if(leave)
            break;

        



    }


    std::cout << std::fixed << std::setprecision(2);

    std::cout << std::right << std::endl;

    std::cout << std::setw(10) << "Monthly" << std::setw(8) << "Yearly" << std::endl;
    std::cout << std::setw(10) << "Investment" << std::setw(8) << "Rate" << std::setw(6) << "Years" << std::setw(14) << "Future Value" << std::endl; 
    for(size_t i = 0;i < monthly_investments.size();i++){
        monthly_investment = monthly_investments.at(i);
        yearly_interest_rate = yearly_interest_rates.at(i);
        years = num_years.at(i);
        future_value = future_values.at(i);

        std::cout << std::setw(10) << monthly_investment << std::setw(8) << yearly_interest_rate
                  << std::setw(6) << std::defaultfloat << years << std::fixed << std::setprecision(2) << std::setw(14) << future_value << std::endl;






    }









}
