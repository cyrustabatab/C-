#include <fstream>
#include <iostream>
#include <iomanip>


int main() {
    
    std::string filename{"temps.txt"};

    std::ofstream output_file{filename};

    output_file << std::fixed << std::setprecision(1);
    output_file << 48.4 << '\t' << 57.2 << '\n';
    
    output_file << 46.0 << '\t' << 50.0 << '\n';

    output_file << 78.3 << '\t' << 101.4 << '\n';

    output_file.close();


    std::ifstream input_file{filename};
    
    const int width{8};
    
    double low{},high{};
    

    std::cout << "TEMPERATURES\n";
    if (input_file) {
        std::cout <<  std::fixed << std::setprecision(1); 
        std::cout << std::setw(width) << "Low" << std::setw(width) << "High" << std::endl;
        while(input_file >> low >> high) {
            std::cout << std::setw(width) << low << std::setw(width) << high << std::endl;

        }



    }



}
