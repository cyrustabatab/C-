#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <limits>


void displayMenu();
double convert_fahrenheit_to_celsius(double);
double convert_celsius_to_fahrenheit(double);
double getValidNumber(std::string type);

int main() {
    
    std::cout << "Convert Temperatures\n\n";
    
    
    while(true) {
        displayMenu();
        
        char choice{};
        while(true) {
            std::cout << "Enter a Choice: ";
            std::cin >> choice;

            if(choice != '1' && choice != '2') {
                std::cout << "Please either enter 1 or 2!\n";
                continue;
            }

            break;



        }

        std::string type{ (choice == '1') ? "Fahrenheit": "Celsius"};
        

        double number{getValidNumber(type)};
        


        double result{};
        switch (choice) {
            case '1':
                result = convert_fahrenheit_to_celsius(number);
                std::cout << "Degrees Celsius: " << result << std::endl;
                break;
            case '2':
                result = convert_celsius_to_fahrenheit(number);
                std::cout << "Degrees Fahrenheit: " << result << std::endl;
                break;
            default:
                break;

        }

        std::cout << "Do you want to convert another temperature(y/n): ";

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        if(choice  == 'n')
            break;

    }


}


double getValidNumber(std::string type) {
    
    double number{};
    while(true) {
        std::cout << "Enter Degree " << type << ": ";

        if(std::cin >> number) {
            break;
        }

        std::cout << "Please enter a number!\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


    }

    
    return number;



}

void displayMenu()  {
    
    std::cout << "MENU\n"
              << "1. Fahrenheit to Celsius\n"
              << "2. Celsius to Fahrenheit\n\n";

}


double convert_fahrenheit_to_celsius(double temperature) {
    
    double celsius{(temperature - 32.0) * 5.0 / 9.0};

    return std::round(celsius * 100) / 100;


}


double convert_celsius_to_fahrenheit(double temperature) {
    
    double fahrenheit{(temperature * 9.0 / 5.0 + 32.0)};
    return std::round(fahrenheit * 100) / 100;
}

