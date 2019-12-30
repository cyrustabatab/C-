#include <iostream>
#include <iomanip>
#include <string>


int main() {
    
    const int width{22};

    std::cout << std::left << std::setw(width) << "Enter account number:";

    int account_num{};
    std::cin >> account_num;
    

    std::cin.ignore();

    std::cout << std::setw(width) << "Enter Full Name:";
    
    std::string full_name{};
    std::getline(std::cin,full_name);

    std::cout << "Name: " << full_name << " | " << account_num;







}
