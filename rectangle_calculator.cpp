#include <iostream>
#include <iomanip>
#include <cmath>



int main() {
    

    const int w{24};
    std::cout << "Rectangle Calculator\n\n";
    

    double height{};
    double width{};

    std::cout << std::left << std::setw(w) << "Enter height and width:";

    std::cin >> height >> width;
    

    if (height <= 0.0 || width <= 0.0)
        std::cout << "Height and width must be greater than zero";
    else{
        double area{height * width};

        std::cout << std::setw(w) << "Area:" << area << std::endl;



        std::cin.ignore(1000,'\n');
        std::cout << "Press [ENTER] to exit program...";

        std::cin.ignore();
    };









}





