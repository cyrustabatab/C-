#include <iostream>
#include <iomanip>



int main() {
    
    const double PRICE_PER_SMALL_ROOM{25.0};
    const double PRICE_PER_LARGE_ROOM{35.0};
    const double TAX_RATE{0.06};
    const int EXPIRATION_ESTIMATE{30};
    const int justification{23};
    std::cout << std::left << "Hello, welcome to Cyrus' carpet cleaning service.\n";

    std::cout << "How many small rooms would you like cleaned? " ;
    
    int small_rooms{};
    std::cin >> small_rooms;

    std::cout << "How many small rooms would you like cleaned? " ;
    int large_rooms{};
    std::cin >> large_rooms;
    
    
    std::cout << std::endl;
    std::cout << std::setw(justification) << "Number of Small Rooms: " << small_rooms << std::endl;
    std::cout << std::setw(justification) << "Number of Large Rooms: " << large_rooms << std::endl;
    std::cout << std::setw(justification) << "Price per Small Room: " << PRICE_PER_SMALL_ROOM << std::endl;
    std::cout << std::setw(justification) << "Price per Large Room: " << PRICE_PER_LARGE_ROOM << std::endl;


    double cost{PRICE_PER_SMALL_ROOM * small_rooms + PRICE_PER_LARGE_ROOM * large_rooms}; 
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(justification) << "Total Cost: " << cost << std::endl;
    

    double tax{cost * TAX_RATE};

    std::cout << std::setw(justification) << "Tax: " << tax << std::endl;

    double total_estimate{cost + tax};

    std::cout << std::setw(justification) << "Total Estimate: " << total_estimate << std::endl;


    std::cout << "This estimate is valid for " << EXPIRATION_ESTIMATE << " days!" << std::endl;









}
