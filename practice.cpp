#include <vector>
#include <iostream>
#include <numeric>



int main() {
    

    std::vector<std::vector<int>> nums{ {1,2,3,4,5},
                           {6,7,8,9,10},
                           {11,12,13,14},
                           {15,16,17,18}};



    int total = std::accumulate(nums.begin(),nums.end(),0.0,[](int accumulator,auto v) -> int {return std::accumulate(v.begin(),v.end(),0);});

    std::cout << total << std::endl;


    std::vector<int> nums2 {{1,2,3,4,5}};

    std::for_each(nums2.begin(),nums2.end(),[](auto value) {std::cout << value << ' ';});


}

