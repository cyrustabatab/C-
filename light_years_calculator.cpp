#include <iostream>
#include <iomanip>
#include <limits>


int main() {
    
    std::cout << "Light Years Calculator\n\n";

    double light_years{};
    
    while(true) {
        std::cout << "Enter Light Years: ";
        
        if(std::cin >> light_years)
            break;
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
            std::cout << "Please print a number\n";
    }


    const double miles_per_light_year{5.879e+13};
    const double km_per_light_year{9.461e+12};
    const double parsecs_per_light_year{0.306601};


    double miles{light_years * miles_per_light_year};
    double km{light_years * km_per_light_year};
    double parsecs{light_years *parsecs_per_light_year};
    
    
    const unsigned int width{19};
    std::cout << std::setprecision(8);
    std::cout << "\nSCIENTIFIC NOTATION\n";

    std::cout << std::left << std::setw(width) << "Miles:" << miles << std::endl 
              << std::setw(width) << "Kilometers:" << km << std::endl
              << std::setw(width) << "Parsecs:" << parsecs << std::endl << std::endl;

    

    std::cout << std::fixed 
              << "FIXED NOTATION\n"
              << std::setw(width) << "Miles:" << miles << std::endl
              << std::setw(width) << "Kilometers:" << km << std::endl
              << std::setw(width) << "Parsecs:" << parsecs << std::endl << std::endl;

            

    
    std::cout << "Bye!\n\n";


}
