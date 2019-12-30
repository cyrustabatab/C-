#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "console.hpp"


double calculate_mpg(double miles,double gallons);
void write_data(std::ofstream& file,double miles,double gallons,double mpg);

int main() {
    
    const int w{10};
    std::string file_name{"mpg.txt"};
    std::ofstream output_file{file_name,std::ios::app};  
    
    char choice{'y'};

    double miles{},gallons{},mpg{};
    while(choice != 'n') {
        
        miles = console::get_double("Miles: ");
        gallons = console::get_double("Gallons: ");



        mpg = calculate_mpg(miles,gallons);
        
        write_data(output_file,miles,gallons,mpg);


        choice = console::get_char("Continue(y/n): ");

    }


    std::cout << "\n\nBye!";

    return 0;
}


double calculate_mpg(double miles,double gallons) {
    
    return miles/gallons;

}

void write_data(std::ofstream& file,double miles,double gallons,double mpg) {
    file << miles << '\t' << gallons << '\t' << mpg;

}

