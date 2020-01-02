#include <cstring>
#include <iostream>
#include <limits>
#include <cctype>



void get_name(char first_name[],char full_name[],int size);
void get_password(char password[],int size);
void trim_leading_whitespace(char cstring[]);
int find_space(char cstring[]);
void capitalize_initial_letter(char cstring[]);
void reset_stream();

int main() {
    
    const int size{51}; // need to include extra space for null terminator
    std::cout << "Create Account\n\n";

    char full_name[size]{""},first_name[size]{""},password[size]{""};

    
    get_name(first_name,full_name,size);
    
    get_password(password,size);
    capitalize_initial_letter(first_name);


    std::cout << "Hi " << first_name << '!';
    std::cout << "\nThanks for creating an account!";






}


void reset_stream() {

    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }

}

void get_name(char first_name[],char full_name[],int size) {
    
    
    while(true) {
        std::cout << "Enter Full Name (" << size - 1 << " characters max): ";
        
        std::cin.getline(full_name,size);
        reset_stream();

        trim_leading_whitespace(full_name);

        int index{find_space(full_name)};

        if(index == -1) {
            std::cout << "Please enter your FULL name!\n";
        } else {

            std::strncpy(first_name,full_name,index);
            break;

        }




    }

    
    



}


void get_password(char password[],int size) {
    

    while(true) {
        
        std::cout << "Enter Password (" << size - 1 << " characters max): ";
        std::cin.getline(password,size);
        reset_stream();
        
        
        unsigned int len = std::strlen(password); 
        bool has_8{len >= 8 ? true: false};
        
        bool has_number{false};
        

        for(int i = 0;i < len;++i) {
            if(std::isdigit(password[i]))  {
                has_number = true;
                break;
            }

        }

        bool has_special{false};
        int i{};
        while(password[i] != '\0') {
            if(std::ispunct(password[i])) {
                has_special = true;
                break;
            }
            ++i;
        }

        
        if(has_8 && has_number && has_special) {
            break;
        } else {
            std::cout << "Password must meet the following criteria:\n";
            if(!has_8) {
                std::cout << " - at least 8 characters long\n";
            }
            if(!has_number) {
                std::cout << " - at least one number\n";
            }

            if(!has_special) 
                std::cout << " - at least one special character\n";


            std::cout << "Try again.\n\n";

        }
    }
    

}


void trim_leading_whitespace(char s[]) {
    
    if(std::isspace(s[0])) {
       int i{}; 
       while(std::isspace(s[i])) {
           ++i; 
       }
            
       int j{};

       while(s[i] != '\0') {
           s[j] = s[i]; 
           ++j;
           ++i;
       }

       s[j] = '\0';

    }


}


int find_space(char s[]) {
   

    int i{};

    while(s[i] != '\0') {
        if(std::isspace(s[i])) {
            return i;
        }
        ++i;
    }

    return -1;


}

void capitalize_initial_letter(char s[]) {
    
    
    s[0] =std::toupper(s[0]);

    int i{1};
    while(s[i] != '\0') {
        s[i] = std::tolower(s[i]);
        ++i;
    }

}



