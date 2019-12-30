#include <iostream>
#include <vector>


int main() {
    

    std::vector<double> prices;
    prices.push_back(9.99);
    prices.push_back(149.99);

    auto size = prices.size();

    double first{prices.front()};

    double last{prices.back()};

    double second = prices.at(1);

    prices.pop_back();
    size = prices.size();

    bool is_empty = prices.is_empty();
    last = prices.back();








}

