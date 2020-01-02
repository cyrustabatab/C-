#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>


template<typename T>
struct Under {
    
    T limit;

    Under(T limit) {
        this->limit = limit;
    }

    
    bool operator()(T value) {
        return value < limit; 
    }

};

void bubble_sort(int a[],int size) {

    int end{size};
    

    while(true) {
        bool stabilized{true};
        for(int i=0;i < end - 1;++i) {
             if(a[i] > a[i +1]) {
                stabilized = false;
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] =temp;

             }

        }

        if(stabilized) {
            break;
        }
    }


}


void selection_sort(int a[],int size) {

    for(int i{0};i < size - 1;++i) {
        int minimum{a[i]};
        int min_index{i};
        for(int j{i};j < size;++j) {
            if(a[j] < minimum) {
                minimum = a[j];
                min_index = j;
            }


        }
        int temp{a[i]};
        a[i] = a[min_index];
        a[min_index] = temp;
    }

}


void insertion_sort(int a[],int size) {
    

    for(int i=1;i < size;++i) {
        int j{i}; 
        while(j > 0 && a[j] < a[j -1]) {
            int temp{a[j]};
            a[j] = a[j -1];
            a[j -1] = temp;
            --j;
        }
    }

}

int generate_random_number(int end) {

    return std::rand() % end + 1;

}

int main() {
    
    std::srand(std::time(nullptr)); 
    
    
    const int end{500};
    const int size{100};
    
    int a[size]{};
    
    for(int i =0;i < size;++i) {
        a[i] = generate_random_number(end);
    }

    auto begin = a;

    std::cout << "Original Array" << std::endl;
    std::for_each(a,a + size,[](auto value) {std::cout << value << ' ';});
    std::cout << std::endl;

    insertion_sort(a,size);

    std::cout << "Sorted Array" << std::endl;
    std::for_each(a,a + size,[](auto value) {std::cout << value << ' ';});

    std::cout << std::endl; 
    

    std::vector<int> nums{1,2,3,4,5};

    int count = std::count_if(nums.begin(),nums.end() - 1,Under<int>(6));

    std::cout << count << std::endl;
    




}




