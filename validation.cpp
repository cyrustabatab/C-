#include <iostream>
#include <string>
#include <iomanip>


namespace validation {
    

    bool is_valid_email(const std::string& email_address) {

        
        auto dot_symbol_index = email_address.find('.');
        auto at_symbol_index = email_address.find('@');

        bool has_dot_symbol{dot_symbol_index != -1};
        bool has_at_symbol{at_symbol_index != -1};

        if(!has_dot_symbol || !has_at_symbol) {
            if(!has_dot_symbol)
                std::cout << "The email must include a dot character(.)\n";

            if(!has_at_symbol)
                std::cout << "The email must include a an at symbol(@)\n";
            
            std::cout << "Please Try Again!\n";
            return false;


        }
        for(char c : email_address) {
            if(!std::isalnum(c) && c != '-' && c != '_' && c != '.' && c != '@') {
                std::cout << "Email includes invalid character " << c << ". Email may only consist of alphanumeric characters,dashes,underscores,@ signs, and dots\n";
                return false;

            }

        
        return true;

        }
    }



    bool is_valid_password(const std::string& password) {
        
        bool is_valid{true};
        bool valid_size{false};
        if(password.size() >= 8) {
            valid_size = true;
        } else {
            is_valid = false;
        }

        bool has_number{false},has_special{false},has_upper{false};
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
            return true;
        

        if(!valid_size) {
            std::cout << "Password must have at least 8 characters.\n";
        }

        if(!has_number)  {
            std::cout << "Password must have at least one number.\n";
        }

        if(!has_special)
            std::cout << "Password must have at least one special character.\n";

        if(!has_upper)
            std::cout << "Password must have at least one uppercase letter.\n";
        
        return false;

    }

}
