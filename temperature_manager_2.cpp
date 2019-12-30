#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>
#include <limits>



void save_temperatures(const std::vector<double>& lows,const std::vector<double>& highs,std::string file_name) {
    
    std::ofstream output_file{file_name};


    for(int i = 0;i < lows.size();i++) {
        auto low = lows.at(i);
        auto high = highs.at(i);

        output_file << low << '\t' << high << std::endl;

    }

    output_file.close();


}

void view_temperatures(const std::vector<double>& lows,const std::vector<double>& highs) {
    std::cout << "TEMPERATURES\n"; 
    
    const char width_1{4};
    const char width_2{8};
    std::cout << std::left << std::setw(width_1) << "Day" 
             << std::right  << std::setw(width_2) << "Low"
             << std::setw(width_2) << "High" << std::endl;
    
    
    std::string filler_1(width_1,'-');
    std::string filler_2(width_2 - 1,'-');
        

    std::cout << filler_1 << std::setw(width_2) << filler_2 << std::setw(width_2) << filler_2 << std::endl;
    
    std::cout << std::fixed << std::setprecision(1);
    for(int i=0;i < lows.size();i++) {
        auto low = lows.at(i);
        auto high = highs.at(i);

        std::cout << std::left << std::setw(width_1) << i + 1 << std::right << std::setw(width_2) << low << std::setw(width_2) << high << std::endl;




    }





}

void remove_temperature(std::vector<double>& lows,std::vector<double>& highs) {
    
    int index{};
    while(true) {
        std::cout << "Enter Day to Remove: ";

        if(std::cin >> index) {
            if(index < 0 || index >= lows.size()) {
                std::cout << "Please enter valid day!\n";

            } else {
                lows.erase(lows.begin() + index - 1);
                highs.erase(highs.begin() + index - 1);
                break;
            }

        } else {
            std::cout << "Please enter a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        }


    }

    std::cout  << "Temperatures at day " << index << " removed!";


}

void read_file(std::vector<double>& lows,std::vector<double>& highs,std::string file_name) {
    
    std::ifstream input_file{file_name};
    
    double low{},high{};
    if(input_file) {
        
        while(input_file >> low >> high) {
            lows.push_back(low);   
            highs.push_back(high);

        }

    }


}

void add_temperature(std::vector<double>& lows,std::vector<double>& highs) {
    
    double low{},high{};
    double* current = &low;
    std::string type{"Low"}; 
    for(size_t i =0;i < 2;i++) {
        while(true) {
            std::cout << "Enter " << type << " Temp: ";

            if(std::cin >> *current) {
               break ;
            } else  {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                std::cout << "Please enter a number!\n";
            }
        }

        current = &high;
        type = "High";
    }

    lows.push_back(low);
    highs.push_back(high);

}

int main() {
    
    std::cout << "The Temperature Manager Program\n\n";
    
    std::string file_name{"temperatures.txt"};
    char command{};
    

    std::vector<double> lows;
    std::vector<double> highs;

    read_file(lows,highs,file_name);
    bool exit{false};
    while(true) {
        std::cout << "COMMANDS\n"
                  << "v - View Temperatures\n"
                  << "a - Add a Temperature\n"
                  << "r - Remove a Temperature\n"
                  << "s - Save Changes\n"
                  << "x - Exit\n\n";

        

        while(true) {
            std::cout << "Command: ";

            std::cin >> command;

            command = std::tolower(command);

            if(command != 'v' && command != 'a' && command != 'r' && command != 's' && command != 'x') {
                std::cout << "Invalid Command! Try Again!\n";
                continue; 
            }
            break;
        }


        switch(command) {
            case 'v':
                view_temperatures(lows,highs);
                break;
            case 's':
                save_temperatures(lows,highs,file_name);
                break;
            case 'a':
                add_temperature(lows,highs);
                break;
            case 'r':
                remove_temperature(lows,highs);
                break;
            case 'x':
                exit = true;
                break;
            default:
                break;




        }


        if(exit)
            break;

        std::cout << std::endl;
    }


    std::cout << "\n\nBye!";

}




