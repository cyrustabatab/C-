#include <map>
#include <iostream>
#include <algorithm>



int main() {
    
    
    std::string hello{"hello"};
    std::string s{"ell"};

    auto iter = std::search(hello.begin(),hello.end(),s.begin(),s.end());

    std::cout << iter - hello.begin() << std::endl;
    
    


}







