#include <iostream>
#include <limits>


int main() {
    

    double number{};

    while(true) {
        std::cout << "Enter a number from 1 to 100: ";
        std::cin >>  number;

        if (std::cin.fail()) { //if cin failed
            std::cin.clear(); //clear error bits
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clear buffer
            continue;
        } else if (std::cin.bad()) {
            std::cout << "Unrecoverable error occured!";
            return 1;
        }

        
        if(number >= 1 && number <= 100)
            break;
        else {
            std::cout << "Please enter a number between 1 and 100\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //clear buffer
        }




    }


    std::cout << "Your number is " << number;





}
