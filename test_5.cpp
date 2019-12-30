#include <iostream>
#include <vector>


int main() {
    
    std::vector<int> nums1;

    for(int i = 0;i < 10;++i) {
        nums1.push_back(i);
        std::cout << "Element " << i << '\t'
                  << "Capacity " << nums1.capacity() << '\t'
                  << "Size " << nums1.size() << std::endl;


    }


}
