#include <string>
#include <cassert>
#include <cmath>
#include <iostream> 



int rabin_karp(std::string s1,std::string s2) {
    

    assert(s1.size() >= s2.size());


    int x{53};
    long current_hash{};
    long target_hash{};
    bool same{true};
    
    for(size_t i = 0;i < s2.size();i++) {

        if (same && s1[i] != s2[i]) 
            same = false;

        current_hash = current_hash * x + static_cast<int>(s1[i]);
        target_hash = target_hash * x + static_cast<int>(s2[i]);


    }
    
    
    std::cout << current_hash << std::endl;
    std::cout << target_hash << std::endl;
    if (same)
        return 0;



    long power{static_cast<long>(std::pow(x,s2.size() - 1))};


    for(size_t i = s2.size();i < s1.size();i++) {
        
        char letter_to_remove = s1[i - s2.size()];
        char letter_to_add = s1[i];

        current_hash = (current_hash - power * static_cast<int>(letter_to_remove)) * x + static_cast<int>(letter_to_add);
        std::cout << current_hash << std::endl;
        if (current_hash == target_hash && s1.substr(i - s2.size() + 1,s2.size()).compare(s2) == 0)
            return i - s2.size() + 1;

    }


    return -1;






}







int main() {

    
    std::string s1{"hello"};
    std::string s2{"ell"};

    std::cout << rabin_karp(s1,s2) << std::endl;

}
