#include <vector>
#include <list> 
#include <array>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <numeric>


template <typename T>
void display(T value) {
    
    std::cout << value << ' ';

}


int total_even(int accumulator,int current_val) {
    if(current_val % 2 == 0) {
        accumulator += current_val;

    }
    return accumulator;

}
int main() {
    
    
    std::vector<int> nums{1,2,3,4,5,6};

    
    auto max_iter = std::max_element(nums.begin(),nums.end());
    
    int index = max_iter - nums.begin();
    std::cout << index<< std::endl;
    


}
