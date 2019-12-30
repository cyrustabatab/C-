#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>





int main() {
    

    std::vector<int> nums{1,2,3,4,5};


    std::for_each(nums.begin(),nums.end(),[](auto value) {std::cout << value << ' ';});

    std::cout << std::endl;
    

    std::vector<std::vector<int> > nums_2 { {1,2,3,4,5},
                                           {6,7,8,9,10},
                                           {11,12,13,14,15}};



    int total = std::accumulate(nums_2.begin(),nums_2.end(),0.0,[](int accumulator,auto v) -> int {return accumulator +  std::accumulate(v.begin(),v.end(),0);});

    std::cout << total << std::endl;
}







