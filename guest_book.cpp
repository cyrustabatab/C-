#include <iostream>
#include <string>
#include <iomanip>


int main() {
    
    const int width{16};
    std::cout << "Guest Book\n" << std::endl;
    

    std::string first_name{};
    std::string middle_initial{};
    std::string last_name{};
    std::string city{};
    std::string country{};

    std::cout << std::left << std::setw(width) << "First Name:";

    std::cin >> first_name;
    std::cin.ignore(100,'\n');

    std::cout << std::setw(width) << "Middle Initial:";

    middle_initial = std::cin.get();
    std::cin.ignore(100,'\n');

    std::cout << std::setw(width) << "Last Name:";
    std::getline(std::cin,last_name);

    std::cout << std::setw(width) << "City:";

    std::getline(std::cin,city);
    std::cout << std::setw(width) << "Country:";
    std::getline(std::cin,country);


    std::cout << "ENTRY" << std::endl;

    std::cout << first_name << ' ' << middle_initial << ". " << last_name << std::endl;
    std::cout << city << ", " << country << std::endl;


    return 0;



}





