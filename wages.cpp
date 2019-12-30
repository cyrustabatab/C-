#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>



int main() {
    
    
    std::string file_name{"wages.txt"};

    std::ifstream input_file{file_name};
    
    std::stringstream ss;

    if(input_file) {
        
        const int width_1{18};
        const int width_2{12};
        
        std::cout << std::left << std::setw(width_1) << "Name";
        std::cout << std::right << std::setw(width_2) << "Hourly wage";
        std::cout << std::setw(width_2) << "Hours";
        std::cout << std::setw(width_2) << "Total" << std::endl;
    
        std::cout << std::fixed << std::setprecision(2);
        std::string filler_1(width_1 - 1,'-');
        std::string filler_2(width_2 - 1,'-');

        std::cout <<  std::left << std::setw(width_1) << filler_1 << std::right << std::setw(width_2) << filler_2 <<  std::setw(width_2) << filler_2 << std::setw(width_2) << filler_2 << std::endl;

        
        unsigned int not_processed{};
        std::string name{};
        double hourly_wage{};
        double hours{};
        
        std::string line{};
        while(std::getline(input_file,line)) {

            ss.str(line);
            ss.clear();

            if(ss >> name >> hourly_wage >> hours) {
                double total{hourly_wage * hours};
                total = std::round(total * 100) / 100;
                std::cout << std::left << std::setw(width_1) << name;
                std::cout << std::right << std::setw(width_2) << hourly_wage;
                std::cout << std::setw(width_2) << hours;
                std::cout << std::setw(width_2) << total << std::endl ;

            }  else {
                not_processed++;
            
            }
            

            

        }
        
        if(not_processed) 
            std::cout << "\n\n" << not_processed << (not_processed == 1? " line": " lines") << " not processed." << std::endl;
        input_file.close();
    
    } else {

        std::cout << "File does not exist" << std::endl;

    }




}
