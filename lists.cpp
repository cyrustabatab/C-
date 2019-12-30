#include <list>
#include <forward_list>
#include <iostream>



int main()  {
    
    std::list<int> numbers{1,2,3,4,5};

    std::forward_list<int> numbers2{6,7,8,9};

    std::vector<int> nums{1,2,3,4,5,6};

    std::list<int> numbers3(nums.begin(),nums.end());

    numbers3.assign(++nums.begin(),nums.end());

    std::cout << numbers3 << std::endl;


}
