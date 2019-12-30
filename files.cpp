#include <fstream>
#include <iostream>


int main() {
    
    std::ofstream output_file;
    output_file.open("names.txt");

    output_file << "Cyrus\n";
    output_file << "Dara\n";
    output_file << "Neelou\n";
    output_file.close();


    std::ifstream input_file{"names.txt"};

    if(input_file) {
        std::string line{};

        while(std::getline(input_file,line))
            std::cout << line << '\n';

        input_file.close();

    }



    output_file.open("names.txt",std::ios::app);

    output_file << "James\n";
    output_file.close();


    std::fstream file{"names.txt",std::ios::out | std::ios::app};

    file << "Lebron James\n"; 

    file.close();


    file.open("names.txt",std::ios::in);
    
    if(file) {
        std::string line{};
        while(std::getline(file,line))
            std::cout << line << '\n';
        
        file.close();
    }




}
