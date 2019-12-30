#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <fstream>




int main() {

    std::cout << "Create Account\n\n"; 

    std::string full_name{};
    const std::string file_name{"accounts.txt"};
    std::string first_name{},last_name{};
    std::ofstream output_file{file_name,std::ios::app};
    while(true) {
        
        std::cout << "Enter Full Name: ";

        std::getline(std::cin,full_name);

        
        auto index =full_name.find_first_not_of(" \t\n");
        if(index != -1) {
            
            full_name = full_name.substr(index);

            auto white_space = full_name.find(' ');
            if(white_space == -1) {
                std::cout << "Please enter your Full Name(First Name and Last Name)\n";
                continue;
            } else {
                first_name = full_name.substr(0,white_space);
                break;

            }

        } else {

            std::cout << "Please enter your Full Name(First Name and Last Name)\n";
        }


    }
    
    std::string password{};
    const unsigned int min_size{8};
    bool valid_size{false},has_number{false},has_special{false},has_upper{false};
    bool is_valid{true};
    while(true) {
        std::cout << "Enter Password: ";


        std::getline(std::cin,password);

        if(password.size() >= 8) {
            valid_size = true;
        } else {
            is_valid = false;
        }

        bool found{false};
        for(auto c: password) {
            if(!has_number && std::isdigit(c))
                has_number = true;
            else if(!has_special && std::ispunct(c))
                has_special = true;
            else if(!has_upper && std::isupper(c))
                has_upper = true;

            if(has_number && has_special && has_upper) {
                found = true;
                break;
            }

        }

        if(is_valid && !found) {
            is_valid = false;
        }
        
        if(is_valid)
            break;
        

        if(!valid_size) {
            std::cout << "Password must have at least 8 characters.\n";
        }

        if(!has_number) 
            std::cout << "Password must have at least one number.\n";

        if(!has_special)
            std::cout << "Password must have at least one special character.\n";

        if(!has_upper)
            std::cout << "Password must have at least one uppercase letter.\n";


        std::cout << "Please try again.\n";



    }

    std::cout << "\nHi " << first_name << ".\nThanks for creating an account!";

    output_file << first_name << '\t' << password << std::endl;

    

}
