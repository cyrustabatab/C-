#include <iostream>
#include <string>
#include <limits>
#include <iomanip>




namespace console {
    

    void discard_remaining_chars();
    void handle_invalid_number();

    bool check_range(double num,double min,double max);


    double get_double(std::string prompt,double min,double max,const int width) {
        double num{};

        bool is_valid{false};


        while(!is_valid) {
            if(width != 0)
                std::cout << std::setw(width) << prompt;
            else
                std::cout << prompt;

            if(!(std::cin >> num)) {
                handle_invalid_number();
            } else {
                discard_remaining_chars();
                is_valid = check_range(num,min,max);

            }


        }

        return num;




    }

    int get_int(std::string prompt,int min,int max,const int width) {
            
        int num{};

        bool is_valid{false};


        while(!is_valid) {
            if(width != 0)
                std::cout << std::setw(width) << prompt;
            else
                std::cout << prompt;

            if(!(std::cin >> num)) {
                handle_invalid_number();
            } else {
                discard_remaining_chars();
                is_valid = check_range(num,min,max);

            }


        }


        return num;



    }
    
    char get_char(std::string prompt,bool add_blank_line) {
        std::cout << prompt;
        
        char c{};
        if(add_blank_line)
            std::cout << std::endl;
        

        std::cin >> c;

        discard_remaining_chars();

        return c;



    }

    bool check_range(double num,double min,double max) {
            
        if(num < min) {
            std::cout << "Error! Number must be greater than or equal to " << min << std::endl;
            return false;
        } else if(num > max) {
            std::cout << "Error! Number must be less than or equal to " << max << std::endl;
            return false;
        } 

        return true;


    }


    void handle_invalid_number() {
        std::cout << "Please Enter a NUMBER!\n";

        std::cin.clear();
        discard_remaining_chars();
        
    }


    void discard_remaining_chars() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    }


}




