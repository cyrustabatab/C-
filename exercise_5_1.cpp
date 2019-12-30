#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <limits>
#include <fstream>
#include <string>


void display_results(std::string file_name) {
    
    std::ifstream input_file{file_name};

    double miles{},gallons{};
    
    double mpg{};
    const unsigned char width{8};
    std::cout << std::setw(width) << "Miles" << std::setw(width) << "Gallons" << std::setw(width) << "MPG" << std::endl;
    while(input_file >> miles >> gallons) {

        

        mpg = miles / gallons;
        mpg = std::round(mpg *100)/100;
        std::cout << std::setw(width) << miles << std::setw(width) << gallons << std::setw(width) << mpg << std::endl;
         


    }
    
    std::cout << std::endl;
    input_file.close();





}

int main()
{
	// print name of program
    std::cout << "Miles Per Gallon\n\n";

	char another_entry = 'y';
    
        std::string file_name{"trips.txt"};
        


        display_results(file_name);
        
        std::ofstream output_file{file_name,std::ios::app};

        output_file << std::fixed <<std::setprecision(1);
	while (std::tolower(another_entry) == 'y') {

		// get miles driven
		double miles = 0;
		while (true) {
                    std::cout << "Enter miles driven:        ";
                    if(std::cin >> miles) {
			if (miles <= 0) {
                            std::cout << "Miles driven must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
                    } else {
                        std::cout << "Please enter a number!\n";
                        std::cin.clear();    // clear error bits
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); // clear extra data
                    }


			// check the range of the number
		}

		// get gallons of gas used
		double gallons = 0;
		while (true) {
                    std::cout << "Enter gallons of gas used: ";
                    if(std::cin >> gallons) {
			if (gallons <= 0) {
                            std::cout << "Gallons used must be greater than zero. Please try again.\n";
				continue;
			}
			else {
				break;
			}
                    } else {
                        std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

                    }

			// check the range of the number
		}
                

                output_file << miles << '\t' << gallons << std::endl;
		// calculate miles per gallon
		double mpg = miles / gallons;
		mpg = std::round(mpg * 100) / 100;
                std::cout << "Miles per gallon:          " << mpg << std::endl << std::endl;

		// see if the user wants to enter more data
                //
                display_results(file_name);
                std::cout << "Get entries for another trip? (y/n): ";
                std::cin >> another_entry;
                std::cout << std::endl;
	}
    
        std::cout << "Bye!\n\n";
}


