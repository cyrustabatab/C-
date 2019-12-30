#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>



void display(int value) {
    
    std::cout << value << ' ';

}

int total_even(int accumulator,int current_val) {
    if(current_val % 2  == 0)
        accumulator += current_val;

    return accumulator;

}

int main() {
   

    std::vector<int> nums{10,15,12,14,16};
    
    std::for_each(nums.begin(),nums.end(),display);
    
    std::cout << std::endl;

    int total{std::accumulate(nums.begin(),nums.end(),0,total_even)};
    std::cout << total << std::endl;
    std::vector<int> a(10);
    
    
    std::iota(a.begin(),a.end(),1);

    std::for_each(a.begin(),a.end(),display);
    return 0;
}

