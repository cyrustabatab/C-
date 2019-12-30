#include <iostream>


void display_array(int nums[],int size) {
    
    std::cout << "The array AFTER passing to function:\t" << sizeof(nums) << " bytes.\n";
    
    std::cout << "The elements: ";

    for(int i{0};i < size;++i) {
        std::cout <<nums[i] << ' ';
    }

    std::cout << std::endl;
}

int main() {
    
    
    const int size{5};

    int nums[size] {1,2,3,4,5};


    std::cout << "The array BEFORE passing to function:\t" << sizeof(nums) << " bytes.\n";


    display_array(nums,size);

    
    const int size{5};

    char grades1[size] {'A','B','B'};
    char grades2[size] {'A','C','B'};

    bool equal{true};

    for(int i =0;i < size;++i) {
        if(grades1[i] != grades2[i]) {
            equal = false;
            break;
        }

    }

    if(equal)
        std::cout << "The arrays are equal.\n";
    else
        std::cout << "The array are NOT equal.\n";


    int scores1[size] {89,92,78,68,87};
    int scores2[size]{};

    for(int i=0;i < size;++i) {
        scores2[i] = scores1[i];
    }



}
