#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>

int get_random_number(int start,int end) {
    
    return std::rand() % end + start;

}


int main() {
    
    
    std::srand(std::time(nullptr));

    const int low{1},high{100};

    


    int guess{};
    int number{}
    unsigned int guesses{};
    

    char choice{};
    do {
        
        guess = 0;

        number = get_random_number(low,high);
        guesses = 8;

    while(guess != number && guesses > 0) {
        
        std::cout << "Guesses Left: " << guesses << std::endl;
        std::cout << "Guess the number between " << low << " and " << high << ": ";
        std::cin >> guess;

        if (guess == number){
            std::cout << "Congratulations! You correctly guessed the number " << number << '!' << std::endl;
        } else if(guess < number) {
            std::cout << "Your guess is too low. Try again!\n";
            guesses -= 1;
        }
        else  {
            std::cout << "Your guess is too high. Try again!\n";
            guesses -= 1;
        }


    } 
        
        if(guesses == 0)
            std::cout << "You could not guess the number. The number is " << number << std::endl;

        std::cout << "Play Again?(y/n): ";
    

        std::cin >> choice;


    } while(std::tolower(choice) == 'y');









}
