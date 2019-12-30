#include <iostream>

#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>


int main() {

    std::cout << "Enter test scores from 0 to 100.\n";
    std::cout << "To end the program, enter -1.\n\n";
    

    std::vector<double> scores;

    
    int score{};
    
    int count{};
    double total{};

    while (true) {
        std::cout << "Enter Score: ";
        std::cin >> score;

        scores.push_back(score);

        if (score > 100 || score <-1) 
            std::cout << "Score must be between 0 and 100. Try again!" << std::endl;
        else if (score == -1)
            break;
        else {
            total += score;
            count++;
        }


    }
    
    
    double avg_score{};
    if (count > 0)
        avg_score = total / count;


    const int width{17};

    std::cout << std::left << std::setw(width) << "Score Count:"  << count << std::endl;
    std::cout << std::left << std::setw(width) << "Score Total:"  << total << std::endl;
    std::cout << std::left << std::setw(width) << "Average score:"  << avg_score;


    





}

