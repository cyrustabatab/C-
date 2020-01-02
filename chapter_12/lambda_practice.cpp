#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <iomanip>





int main(int argc,char** argv) {
   
    
    std::vector<std::vector<int> > nums { {1,2,3,4,5},
                                          {6,7,8,9,10},
                                          {11,12,13,14},
                                          {15,16,17,18}};




    int total = std::accumulate(nums.begin(),nums.end(),0,[](int accumulator,auto v) -> int { return accumulator +  std::accumulate(v.begin(),v.end(),0);});

    
    int start{1};
    std::vector<std::vector<int> > matrix(5,std::vector<int>(5));

    for(int i=0;i < 5;++i) {
        auto& v = matrix.at(i);
        std::iota(v.begin(),v.end(),start);
        
        
        start += 5;

    }


    std::cout << std::right;
    for(int i = 0;i < matrix.size();++i) {
        for(auto v:matrix.at(i))
            std::cout << std::setw(2) << v << ' ';

        std::cout << std::endl;

    }




}








