#include <set>
#include <iostream>
#include <string>

int main() {
    

    std::set<std::string> states {"CA","OR","AK"};

    states.insert("FL");
    states.insert("AK");
    states.insert("MN");
    states.insert("IA");


    for(std::string state: states) {
        std::cout << state << ' ';

    }
    

    auto iter = states.find("FL");

    if(iter == states.end()) {
        std::cout << "Not Found\n";

    } else {
        states.erase(iter);
    }

}
