#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>


int main() {
    
    std::vector<int> nums{89,93,79,92,86};

    std::for_each(nums.begin(),nums.end(),[](int val) {std::cout << val << ' ';});
    
    std::map<std::string,double> products { {"guitar",199.99},{"piano",799.99},
                                                     {"drums",249.99},{"violin",489.99}};


    int limit{500};

    auto under = [&] (std::pair<std::string,double> p) -> bool { return p.second < limit;};

    auto num_low = std::count_if(products.begin(),products.end(),under);

    std::cout << num_low;



}





