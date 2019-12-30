#include <iostream>
#include <iomanip>
#include <string>



int main() {
    
    const short width{16};

    std::cout << "Guest Book\n\n";

    std::cout << std::left << std::setw(width) << "First Name:";
    std::string first_name{};
    std::cin >> first_name;
    std::cin.ignore(1000,'\n');

    std::cout << std::setw(width) << "Middle Initial:";

    char middle_initial{std::cin.get()};
    std::cin.ignore(100,'\n');

    std::cout << std::setw(width) << "Last Name:";
    
    std::string last_name{};
    std::getline(std::cin,last_name);

    std::cout << std::setw(width) << "Address:";

    std::string address{};
    std::getline(std::cin,address);

    std::cout << std::setw(width) << "City:";
    std::string city{};

    std::getline(std::cin,city);


    std::cout << std::setw(width) << "State:";
    std::string state{};

    std::getline(std::cin,state);

    std::cout << std::setw(width) << "Postal Code:";
    
    std::string postal_code{};
    std::getline(std::cin,postal_code);


    std::cout << std::setw(width) << "Country:";

    std::string country{};

    std::getline(std::cin,country);
    

    std::cout << "\n\nENTRY\n";

    std::cout << first_name << ' ' << middle_initial << ". " << last_name << std::endl;
    std::cout << address << std::endl;

    std::cout << city << ", " << state << ' ' << country << std::endl;
    std::cout << country;

    

















}


