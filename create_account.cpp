#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <cctype>
#include <sstream>
#include "validation.hpp"
#include "console.hpp"

struct Account {
    std::string first_name{};
    std::string last_name{};
    std::string email{};
    std::string password{};
    bool operator==(const Account& account) {
        
        return this->email == account.email;

    }

};


std::vector<Account> read_from_file(std::string file_name);
void write_to_file(std::string file_name,const std::vector<Account>& accounts);

void display_accounts(const std::vector<Account>& accounts);
int main() {
    
    const unsigned int width{12};
    std::cout << "Create Account\n\n";
    




    //std::string full_name{}; 
    std::string first_name{};
    std::string last_name{};
    
    std::string file_name{"accounts.txt"};

    std::vector<Account> accounts = read_from_file(file_name);

    display_accounts(accounts);


    /*
    while(true) {
        
        std::cout << "Enter Full Name: ";


        std::getline(std::cin,full_name);


        auto index = full_name.find_first_not_of(" \n\t");
        
        
        if(index == -1) {
            std::cout << "Please enter your first and last name!" << std::endl;
            continue;

        } else {
        
            full_name = full_name.substr(index);
        }

        auto whitespace_index = full_name.find_first_of(" \n\t");

        if(whitespace_index == -1) {
            std::cout << "Please Enter a First and Last Name!\n";
        } else {
            first_name = full_name.substr(0,whitespace_index);
            break;
        }

            






    }

    */
    char choice{'y'}; 
    while(choice != 'n') {


        std::cout << std::left << std::setw(width) <<  "First Name:";
        std::getline(std::cin,first_name);

        std::cout <<  std::setw(width) << "Last Name:";
        std::getline(std::cin,last_name);

        std::string email_address{};
        bool valid_email{false};
        while(!valid_email) {
            
            std::cout << std::setw(width) <<  "Email:";

            std::getline(std::cin,email_address);
            
            valid_email = validation::is_valid_email(email_address);


        } 


        

        std::string password{};
        const unsigned int min_size{8};
        bool is_valid_password{false};
        while(!is_valid_password) {
            std::cout << std::setw(width) << "Password:";


            std::getline(std::cin,password);

            is_valid_password = validation::is_valid_password(password);


        }
    
        
        Account account{first_name,last_name,email_address,password};
        

        bool exists{false};
        for(auto& a: accounts) {
            if(a == account) {
                std::cout << email_address << " already exists - account not added." << std::endl; 
                exists = true;
                break;
            }
        }


        if(!exists) {
            accounts.push_back(account);
            
            write_to_file(file_name,accounts);
        }

        choice = console::get_char("Continue(y/n): ");

        choice = std::tolower(choice);

    }

}



std::vector<Account> read_from_file(std::string file_name) {
    
    std::ifstream input_file{file_name};
    
    std::vector<Account> accounts{};
    std::stringstream ss{};
    if(input_file) {
        
        std::string line{};
        std::string first_name{},last_name{},email{},password{};
        std::vector<std::string*> temp{&first_name,&last_name,&email,&password};
        while(std::getline(input_file,line)) {
            ss.str(line);
            ss.clear();
            
            for(auto a:temp)
                std::getline(ss,*a,'\t');
        

            accounts.push_back(Account{first_name,last_name,email,password});


        }

        input_file.close();
    



    } else {

        std::cout << "File Not Found!\n";
    }

    return accounts;


}


void display_accounts(const std::vector<Account>& accounts) {
    
    std::cout << std::left;
    
    const unsigned int width{20};

    std::cout << std::setw(width) << "Name" << "Email" << std::endl;


    for(auto& account: accounts) {
        std::cout << std::setw(width) << account.first_name + ' ' + account.last_name << account.email; 

    }

    std::cout << std::endl << std::endl;




}
void write_to_file(std::string file_name,const std::vector<Account>& accounts) {
    
    std::ofstream output_file{file_name};
    
    if (output_file) {
        for(auto const& account: accounts) {
            output_file << account.first_name << '\t' << account.last_name << '\t' << account.email << '\t' << account.password << std::endl;
        }


        output_file.close();
    }


}

