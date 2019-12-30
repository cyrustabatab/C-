#include <fstream>
#include <iostream>
#include <limits>




int main() {
    

    std::string file_name{"info.txt"};
    
    std::ifstream input_file;
    input_file.open(file_name);

    if(input_file) {
        int num{};
        while(true) {
            if(input_file >> num)
                std::cout << num << '|';
            else if(input_file.eof()) {
                break;
            } else if(input_file.fail()) {
                input_file.clear();
                input_file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }


        }


        input_file.close();


    }

}
