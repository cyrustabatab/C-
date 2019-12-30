#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>



int main() {
    
    std::cout << "Temperature Manager Program\n\n";


    std::string file_name{"temps.txt"};

    
    char command{};
    std::ofstream output_file;
    std::ifstream input_file;
    double low{},high{};
    while(true) {

        std::cout << "Commands\n"
                  << "v - View Temperatures\n"
                  << "s - Add Temperature\n"
                  << "x - Exit\n\n";

        
        while(true) {

            std::cout << "Command: ";
            std::cin >> command;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            
            if(std::tolower(command) == 'v' || std::tolower(command) == 's' || std::tolower(command) == 'x') {
               break; 
            } else {
                std::cout << "Invalid Command. Please type one of \'v\',\'s\',or \'x\'" << std::endl;
            }

        }


        if(command == 'x')
            break;

        
        if(command == 'v') {
            input_file.open(file_name);

            const int width{8}; 
            std::string filler(width,'-');

            std::cout << "TEMPERATURES\n\n";
            
            std::cout << std::fixed << std::setprecision(1);
            std::cout << std::setw(width) << "Low" << std::setw(width) << "High" << std::endl;
            
            std::cout << filler << ' ' << filler << std::endl;
            while(input_file >> low >> high) {

                std::cout << std::setw(width) << low << std::setw(width) << high << std::endl;
            

            }


            input_file.close();

            std::cout << std::endl << std::endl;


            

        } else {
            output_file.open(file_name,std::ios::app);
            

            double* temp = &low;
            std::string s{"Low"};
            for(size_t i =0;i < 2;i++) {
                while(true) {
                    std::cout << "Enter " << s << " Temp: ";
                        
                    output_file << std::fixed << std::setprecision(1);
                    if(std::cin >> *temp) {
                        break;
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                        std::cout << "Please enter a number!\n";
                    }

                }

                output_file << *temp << std::endl;
                temp = &high;
                s = "High";

            }

            
            std::cout << "Changes have been saved!\n\n";
            output_file.close();

        }




    }

    
    std::cout << "\n\nBye!";

}






