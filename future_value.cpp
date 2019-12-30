#include <iostream>
#include <cmath>
#include "console.hpp"
#include <iomanip>


double calculate_future_value(double monthly_investment,double yearly_interest_rate,int years);

void display_results(double monthly_investment,double yearly_interest_rate,int years,double future_value);

int main() {
    
    const char width{22};
    std::cout << std::left <<  "The Future Value Calculator\n\n";
    
    char choice{'y'};
    
    
    double monthly_investment{};
    double yearly_interest_rate{};
    int years{};
    while(choice != 'n') {
        std::cout << "INPUT\n";

        monthly_investment = console::get_double("Monthly Investment:",0,10000,width); //limit investments from 0 to 10000


        yearly_interest_rate = console::get_double("Yearly Interest Rate:",0,30,width); //limit investments from 0 to 10000


        years = console::get_int("Years:",0,100,width);

        
        double future_value{calculate_future_value(monthly_investment,yearly_interest_rate,years)};

    
        display_results(monthly_investment,yearly_interest_rate,years,future_value);
        
        choice = console::get_char("Continue(y/n): ");

        


    }
    



}



void display_results(double monthly_investment,double yearly_interest_rate,int years,double future_value) {
    
    std::cout << "\nOUTPUT\n";
    const int width{22};
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(width) << "Monthly Investment:" << monthly_investment << std::endl;
    std::cout << std::setw(width) << "Yearly Interest Rate:" << std::setprecision(1) << yearly_interest_rate << std::endl;

    std::cout << std::setw(width) << "Years:" << std::scientific<< years << std::endl;

    std::cout << std::setw(width) << "Future Value:" <<  std::fixed << std::setprecision(2) << future_value << std::endl;




}


double calculate_future_value(double monthly_investment,double yearly_interest_rate,int years) {
    

    double monthly_interest_rate{yearly_interest_rate/100.0/12.0};

    int months{years * 12};
    
    double future_value{};
    for(int i=1;i<=months;++i) {
        future_value = (future_value + monthly_investment) * (1 + monthly_interest_rate);
    }
    future_value = std::round(future_value * 100) / 100;
    return future_value;

}

