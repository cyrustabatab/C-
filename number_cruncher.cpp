#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <algorithm>
#include <iostream>



void display(int num) {
    
    std::cout << num << ' ';

}

int generate_random_number_in_range(int start,int end) {
    
    return start + (std::rand() % (end   - start + 1));

}


int main() {
    
    const int number_of_random_numbers{11};
    const int start{1},end{1000};
    std::cout << "The Number Cruncher Program\n\n";

    std::srand(std::time(nullptr));


    std::vector<int> numbers{};
    numbers.reserve(number_of_random_numbers);

    for(int i =1;i <= number_of_random_numbers;++i) {
        numbers.push_back(generate_random_number_in_range(start,end));

    }

        
    std::cout << number_of_random_numbers << " RANDOM NUMBERS: ";
    std::for_each(numbers.begin(),numbers.end(),display);
    std::cout  << std::endl;
    
    std::sort(numbers.begin(),numbers.end());

    std::cout << number_of_random_numbers << " SORTD NUMBER: ";
    std::for_each(numbers.begin(),numbers.end(),display);
    std::cout << std::endl;
    

    int sum{std::accumulate(numbers.begin(),numbers.end(),0)};
    
    double average{static_cast<double>(sum) /numbers.size()};

    int max{*std::max_element(numbers.begin(),numbers.end())};
    int min{*std::min_element(numbers.begin(),numbers.end())};
    
    std::cout << "Sum = " << sum << " Average = " << average << " Max = " << max << " Min = " << min << std::endl << std::endl;
    unsigned int ten_count{static_cast<unsigned int>(std::count(numbers.begin(),numbers.end(),10))}; 

    std::cout << "The number " << 10 << "occurs " << ten_count << "times";
    

    





}
