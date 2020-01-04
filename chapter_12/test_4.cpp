#include <vector>
#include <iostream> 
#include <algorithm>
#include <numeric>
#include <iomanip>



int main() {

    
    std::vector<int> nums{1,2,3,4,5};

    std::for_each(nums.begin(),nums.end(),[](auto v) {std::cout << v << ' ';});
    
    std::cout << std::endl;
    
    
    std::vector<std::vector<int> > matrix(5,std::vector<int>(5));
    
    int start{1};
    for(int i =0;i < 5;++i) {


       std::iota(matrix.at(i).begin(),matrix.at(i).end(),start);
       start += 5;

    }

    
    std::cout << std::left;
    std::for_each(matrix.begin(),matrix.end(),[](auto v) { std::for_each(v.begin(),v.end(),[](auto value) {std::cout << std::setw(2) <<  value << ' ';}); std::cout << std::endl;});




}
