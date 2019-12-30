#include <vector>
#include <algorithm>
#include <iostream>



int main() {
    
    std::vector<int> nums{1,2,6,7,9,10};

    int count = std::count_if(nums.begin(),nums.end(),[] (int num) -> bool {return num % 2 == 0;});
    
    std::cout << count << std::endl;


}
