#include <vector>
#include <map>
#include <algorithm>
#include <iostream>


template <typename T>
void display(T nums) {
    
    std::for_each(nums.begin(),nums.end(),[](auto p) { std::cout << '(' << p.first << ',' << p.second << ')' << std::endl;});
}

int main() {

    
    std::vector<std::pair<int,int>> nums{ {1,2},{0,4},{1,4}};
    
    display(nums);

    std::sort(nums.begin(),nums.end(),[](auto p1,auto p2) {return p1.first <= p2.first;});

    display(nums);

}






