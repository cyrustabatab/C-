#include <set>
#include <iostream>
#include <vector>



std::vector<int> two_number_sum(const std::vector<int>& numbers,int target) {

    std::set<int> seen;
        
    int diff{};
    for(int number:numbers) {
        diff = target -number;
        
        auto iter = seen.find(diff);
        if(iter != seen.end()) {
            return std::vector<int>{diff,number};

        }

        seen.insert(number);

        
    }

    return std::vector<int>{};
}


int main() {
    

    std::vector<int> numbers{3,5,-4,8,11,1,-1,6};
    int target{10};

    std::vector<int> two_numbers = two_number_sum(numbers,target);
    
    if(!(two_numbers.empty()))
        std::cout << two_numbers.at(0) << two_numbers.at(1) << std::endl;





}
