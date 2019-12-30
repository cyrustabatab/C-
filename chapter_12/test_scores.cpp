#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

int get_score_total(int scores[],int size) {
    
    int total{};

    for(int i =0;i < size;++i) {
        total += scores[i];

    }
    return total;

}

int main() {
    

    std::cout << "The Test Scores Program\n\n";

    const unsigned int capacity{50};
    int scores[capacity]{};


    std::cout << "Enter test scores (" << capacity << " max).\n"
         << "Make sure each score is between 0 and 100.\n"
         << "To end the program, enter -1.\n\n";
    

    int score_count{};

    int score{};
    while(true) {
        
        std::cout << "Enter score: ";

        if(!(std::cin >> score)) {
            std::cout << "Please enter a NUMBER\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        } else {
            
            if(score < -1 || score > 100) {
                std::cout << "Please enter a score from 0 to 100 or -1 to quit.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            } else if (score != -1) {
                scores[score_count++] = score;

            } else 
                break;


        }

    }
    
    std::cout << std::endl;
    if(score_count == 0) {
        std::cout << "No scores to display!\n" << std::endl;
    } else {

        const int width{15};

        std::cout << std::left << std::setw(width) << "Score Count:" << score_count << std::endl;

        int score_total{get_score_total(scores,score_count)};
        std::cout << std::setw(width) << "Score Total:" << score_total << std::endl;

        double score_average{static_cast<double>(score_total)/score_count};
        score_average = std::round( score_average * 100) / 100;
        std::cout << std::setw(width) << "Score Average:" << score_average << std::endl;
    }




}
