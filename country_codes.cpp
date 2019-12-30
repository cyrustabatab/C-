#include <iostream>
#include <map>
#include <cctype>
#include <limits>




void make_uppercase(std::string& s) {
    
    for(char& c:s) {
        c = std::toupper(c);

    }

}


int main() {

    const std::map<std::string,std::string> country_codes {{"CA","California"},{"MX","Mexico"},{"US","United States"}};

    std::cout << "The Country Codes Program\n\n";

    
    std::cout << "Country Codes: ";
    for(std::pair<std::string,std::string> country_code:country_codes) {
        std::cout << country_code.first << ' ';

    }

    std::cout << std::endl << std::endl;

    
    char choice{'y'};
    
    std::string code{};
    while(choice != 'n') {
        
        std::cout << "Enter a Country Code: ";
        
        std::getline(std::cin,code);

        make_uppercase(code);

        auto iter = country_codes.find(code);

        if(iter==country_codes.end()) {
            std::cout << "Country code not found.\n\n";
        } else {
            std::cout << "You selected " << country_codes.at(code) << std::endl;
        
        }

        
        std::cout << "Continue (y/n)? ";
        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    }



}
