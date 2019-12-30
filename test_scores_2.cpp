#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <cmath>


int main() {
    
    std::cout << "The Test Scores Program\n\n";

    std::cout << "Enter test scores from 0 to 100.\n";
    std::cout << "To end the program enter -1\n\n";

    
    std::vector<int> scores;
    int score{};
    while(true) {
        std::cout << "Enter score: ";

        std::cin >> score;

        if(std::cin.fail()) {
            std::cout << "Invalid Score!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        } else if(score == -1) {
            break;
        } else if(score < 0 || score > 100) {
            std::cout << "Please enter a score from 0 to 100\n";
        } else {
            scores.push_back(score);
        }



    }
    
    int total{};
    for(int score: scores) {
        total += score;
    }

    double average_score = static_cast<double>(total) /scores.size() ;
    average_score = std::round(average_score * 100) / 100;
    const unsigned int width{15};
    
    std::cout << std::endl;
    std::cout << std::left << std::setw(width) << "Score Count:" << scores.size() << std::endl;
    std::cout << std::setw(width) << "Score Total:" << total << std::endl;
    std::cout << std::setw(width) << "Score Average:" << average_score << std::endl;


}

