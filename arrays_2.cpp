#include <array>
#include <iostream>
#include <iomanip>
#include <limits>


const int size{10};

double get_score() {
    
    double score{};
    while(true) {
        std::cout << "Enter score: ";

        if(!(std::cin >> score)) {
            std::cout << "Please enter a NUMBER!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        } else if(score < -1 || score > 100) {
            std::cout << "Please enter a number from -1(to exit) to 100(max score)\n";
        } else {
            return score;
        }
    }

}


double total_score(std::array<double,size>& scores) {
    
    double total{};

    for(double score:scores) 
        total += score;


    return total;
}

int main() {
    

    std::array<double,size> scores{};
    std::cout << "The Test Scores Program\n\n";

    std::cout << "Enter 10 scores or -1 to exit" << std::endl << std::endl;
    
    double score{};
    int score_count{};
    for(int i=0;i < 10;++i) {
        
        score = get_score();
        
        if(score == -1) {
            break;
        }
        ++score_count;
        scores[i] = score;




    }


    double score_total{total_score(scores)};

    std::cout << "\nScore Count: " << score_count << std::endl;
    std::cout << "Score Total: " << score_total << std::endl;


    return 0;



}
