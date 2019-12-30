#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>


int main()  {
    


    std::ifstream infile{"temp_2.txt"};

    if (infile) {

        std::string line{}; 
        std::stringstream ss;
        double low{};
        double high{};

        std::cout << std::fixed << std::setprecision(1);

        while(std::getline(infile,line)) {
            ss.str(line);
            ss.clear();
            if(ss >> low >> high)
                std::cout << std::setw(8) << low << std::setw(8) << high << std::endl;
        }
        

    } else {
        std::cout << "Could not open file" << std::endl;
    }


}
