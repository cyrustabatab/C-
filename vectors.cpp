#include <iostream>
#include <vector>



int main() {
    

    std::vector<int> vec{10,20,30,40,50};

    vec.at(0) = 100;
    vec.at(vec.size() - 1) = 1000;


    for(size_t i = 0;i < vec.size();i++) {
        std::cout << vec.at(i) << std::endl;

    }


}

