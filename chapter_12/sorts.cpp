#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>





void test() {
    
    std::vector<int> nums{1,2,3,4};
    
    std::vector<int> nums2(nums.begin() +1,nums.end());


}









template <typename T>
int partition(std::vector<T>& a,int low,int high) {
    
    int pivot_index{low + std::rand() % (high -low + 1)};
    
    T temp{a.at(low)};
    a.at(low) = a.at(pivot_index);
    a.at(pivot_index)=temp;
    
    T pivot{a.at(low)};
    int i{low + 1};
    int j{i};

    while(j <= high) {
        if(a[j] < pivot) {
            temp = a.at(i);
            a.at(i) = a.at(j);
            a.at(j) = temp;
            ++i;
        }
        ++j;
    }
    
    
    temp= a.at(low);
    a.at(low) = a.at(i -1);
    a.at(i -1) = temp;

    return i -1;






}

template <typename T>
void _quicksort_helper(std::vector<T>& a ,int low,int high) {
    
    if(low >= high)
        return;

    int p{partition(a,low,high)};
    
    
    _quicksort_helper(a,low,p -1);
    _quicksort_helper(a,p + 1,high);


}
template <typename T>
void quicksort(std::vector<T>& a) {
    
    _quicksort_helper(a,0,a.size() - 1);
}

template <typename T>
std::vector<T> merge(const std::vector<T>& a,const std::vector<T>& b) {
    
    int i{},j{};
    
    std::vector<T> merged{};
    while (i < a.size() || j < b.size()) {
        if(j == b.size() || (i < a.size() && a.at(i) <= b.at(j))) {
            merged.push_back(a.at(i)); 
            ++i;
        } else {
            merged.push_back(b.at(j));
            ++j;
        }

    }


    return merged;

}


template <typename T>
std::vector<T> mergesort_helper(std::vector<T>& a,int low,int high) {
    
    if(low == high)
        return std::vector<T>{a.at(low)};



    int mid{static_cast<int>((low + high) /2)};

    return merge(mergesort_helper(a,low,mid),mergesort_helper(a,mid + 1,high));



}



template <typename T>
std::vector<T> mergesort(std::vector<T> a) {
    
    
    return mergesort_helper(a,0,a.size() -1);




}


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
    
    bool stabilized{true};
    do {
        for(int i=0;i < end - 1;++i) {
             if(a[i] > a[i +1]) {
                stabilized = false;
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] =temp;

             }

        }

    } while(!stabilized);


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
    std::vector<int> nums; 
    for(int i =0;i < size;++i) {
        a[i] = generate_random_number(end);
        nums.push_back(generate_random_number(end));
    }

    //auto begin = a;

    //std::cout << "Original Array" << std::endl;
    //std::for_each(a,a + size,[](auto value) {std::cout << value << ' ';});
    //std::cout << std::endl;
   
    std::for_each(nums.begin(),nums.end(),[](auto v) {std::cout << v << ' ';});
    std::cout << std::endl;
    quicksort(nums);
        
    std::cout << "Sorted Array\n";
    std::for_each(nums.begin(),nums.end(),[](auto v) {std::cout << v << ' ';});
    std::cout << std::endl;
    //std::cout << "Sorted Array" << std::endl;
    //std::for_each(a,a + size,[](auto value) {std::cout << value << ' ';});

    //std::cout << std::endl; 
    
    /*
    std::vector<int> nums{1,2,3,4,5};

    int count = std::count_if(nums.begin(),nums.end() - 1,Under<int>(6));

    std::cout << count << std::endl;
    */
    




}




