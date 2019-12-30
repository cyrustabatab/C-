#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>
#include <cmath>
#include <iomanip>

struct MinScore {
    
    double min_score;

    MinScore(double min_score) {
        this->min_score = min_score;
    }

    bool operator()(double score) const {
        return score >= min_score;
    }
};

int main() {

    std::cout << "The Test Scores Program\n\n";

    std::cout << "Enter test scores from 0 to 100.\n"
              << "To end the program, enter -1\n\n";


    std::vector<double> scores{};
    double score{};
    while(true) {

        std::cout << "Enter score: ";
        if(!(std::cin >> score)) {
            std::cout << "Please enter a number!";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        } else {
            if(score < -1 || score > 100) {
                std::cout << "Enter a score between -1(to quit) and 100(max possible score)\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }

            if(score == -1) {
                break;
            }

            scores.push_back(score);

        }


    }
    
    std::cout << std::endl << std::endl;

    std::sort(scores.begin(),scores.end(),[](double x,double y) {return x >y;});


    std::for_each(scores.begin(),scores.end(),[](auto value){std::cout << value << ' ';});
    std::cout << "\nHighest score: " << *std::max_element(scores.begin(),scores.end());
    std::cout << "\nLowest score score: " << *std::min_element(scores.begin(),scores.end()) << std::endl;
    int perfect_scores{std::count_if(scores.begin(),scores.end(),[](double value)-> bool {return value ==100.0;})};

    std::cout << "This student has " << perfect_scores << " perfect score" << (perfect_scores ==1 ? "": "s") << std::endl << std::endl;
    

    const unsigned int width{15};
    std::cout << std::left << std::setw(width) << "Score count:" << scores.size() << std::endl;

    double total{std::accumulate(scores.begin(),scores.end(),0.0)};
    double average_score{total / scores.size()};
    
    average_score = std::round(average_score * 100) / 100;

    std::cout << std::setw(width) << "Score Total:" << total << std::endl;
    std::cout << std::setw(width) << "Average Score:" << average_score << std::endl;



}
