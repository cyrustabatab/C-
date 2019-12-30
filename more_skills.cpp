#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>



template <typename T>
void display(T value) {
    std::cout << value << ' ';
}

template <typename K,typename V>
void display(std::pair<K,V> p) {
    
    std::cout << p.first << '=' << p.second << ' ';
}


double sum_products(double total,std::pair<std::string, double> p) {
    return total += p.second;
}


bool under_500(std::pair<std::string,double> p) {
    return p.second < 500;
}


class Under {
    double limit{};
    

    public:
        Under(double max) {
            limit = max;
        }
        
        bool operator()(std::pair<std::string,double> p) const {
            return p.second < limit;
        }

};

int main() {
   
    std::map<std::string,double> products { {"guitar",199.99},
                                            {"piano",799.99},
                                            {"drums",249.99},
                                            {"violin",489.99}};


    std::for_each(products.begin(),products.end(),display<std::string,double>);
    std::cout << std::endl;
    double sum = std::accumulate(products.begin(),products.end(),0.0,sum_products);

    std::cout << sum << std::endl;


    int num_low{std::count_if(products.begin(),products.end(),Under{500.0})};

    std::cout << num_low << std::endl;



}

