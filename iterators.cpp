#include <iostream>
#include <vector>



void display(const std::vector<int>& nums) {
    
    for(auto num: nums) {
        std::cout << num << ' ';
    }

    std::cout << std::endl;

}

int main() {
    

    std::vector<int> nums{1,2,3,4};
    std::vector<int> neg_nums{-2,-1};

    display(nums);

    nums.insert(nums.begin(),0);
    display(nums);
    
    nums.erase(nums.begin());
    display(nums);
    
    nums.insert(nums.begin(),neg_nums.begin(),neg_nums.end());
    display(nums);


    auto iter = nums.begin();

    for(int i = 0;i < neg_nums.size();++i)
        ++iter;
    
    nums.erase(nums.begin(),iter);

    display(nums);

    nums.swap(neg_nums);
    display(nums);
    display(neg_nums);
    nums.insert(nums.end(),++neg_nums.begin(),--neg_nums.end());
    display(nums);

}


