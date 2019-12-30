#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>

int main() {
    
    std::cout << "Temperature Analyzer\n\n";
    
    
    std::string file_name{};
    std::ifstream input_file;
    bool opened{false};
    while(!opened) {
        std::cout<< "Enter input filename: ";
        

        std::cin >> file_name;

        input_file.open(file_name);

        if(!input_file) {
            std::cout << "Unable to open " << file_name << "!. Please try again.\n"; 


        } else {
            opened = true;
            std::cout << "Input file (" << file_name << ") opened successfully!\n\n";


        }
        


    }

    const int width{8};

    std::cout << std::fixed << std::setprecision(1);


    std::cout << std::setw(width) << "Low" << std::setw(width) << "High" << std::setw(width) << "Avg" << std::endl;


    std::string filler(width * 3 + 3,'-');

    std::cout << filler << std::endl;

    
    double low{};
    double high{};
    double average{};

    double average_total{};
    unsigned int successes{};
    unsigned int total{};
    
    double min{std::numeric_limits<int>::max()};
    double max{std::numeric_limits<int>::min()};
    
    
    std::stringstream ss;
    
    std::string line{};

    /*
    while(std::getline(input_file,line)) {
        
        total++;
        ss.str(line);
        ss.clear();
        if(ss >> low >> high)  {
            average = (low + high) / 2;
            min = std::min(min,low);
            max = std::max(max,high);
            average_total += average;
            std::cout << std::setw(width) << low << std::setw(width)  << high << std::setw(width) << average << std::endl;
            successes++;

        }
        
    }
    */
    while(true) {
        
        input_file >> low >> high;
        
        total++;
        if(input_file.good()) {
            average = (low + high) / 2;
            min = std::min(min,low);
            max = std::max(max,high);
            average_total += average;
            std::cout << std::setw(width) << low << std::setw(width)  << high << std::setw(width) << average << std::endl;
            successes++;
        } else if (input_file.eof())
                break;
        else if (input_file.fail()) {
            input_file.clear();
            input_file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else {
            std::cout << "Unrecoverable Error Occured" << std::endl;
            return EXIT_FAILURE;
        }


    }

    input_file.close();


    
    std::cout << successes << " out of " << total << " days successfully processed\n\n";


    double average_temperature{average_total / successes};
    std::cout << std::left << std::setw(20) << "Lowest Temp:" << std::right << std::setw(width *2) << min << std::endl;
    std::cout << std::left << std::setw(20) << "Highest Temp:" << std::right << std::setw(width* 2) << max << std::endl;
    std::cout << std::left << std::setw(20) << "Average Daily Temp:" << std::right << std::setw(width * 2) << average_temperature << std::endl;








}
