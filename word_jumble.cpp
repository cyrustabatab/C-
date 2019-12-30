#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <limits>


int getRandomNumber(int start,int end) {
    
    return start + std::rand() % (end - start + 1);

}

void shuffleWord(std::string& word) {
    


    
    for(size_t i=0;i < word.size();i++) {
        int index{getRandomNumber(i,word.size() - 1)};
        char temp{word[i]};
        word[i] = word[index];
        word[index] = temp;



    }



}


int main() {

    

    std::srand(std::time(nullptr));

    std::cout << "Let's Play Word Jumble!\n\n";

    std::cout << "Enter 'hint' for a hint" << std::endl;
    std::cout << "Enter 'exit' to exit\n" << std::endl;

        
    std::vector<std::string> words{"trumpet","basketball","tennis"};
    
    while(true) {
        std::string word_to_guess{words.at(getRandomNumber(0,words.size() - 1))};

        std::string jumbled_word = word_to_guess;
        

        std::string hint_string(word_to_guess.size(),'_');
        int index{};
        shuffleWord(jumbled_word);
        
        std::cout << "The jumble is...";

        for(char c: jumbled_word) {
            std::cout << static_cast<char>(std::toupper(c));
        }
        
        std::cout << std::endl;
        std::string line{};
        while(true) {
                
            std::cout << "Your Guess: ";
            std::getline(std::cin,line);
            
            bool leave{false};
            if(line ==  "hint"){
                std::cout << "Hint: ";
                hint_string[index] = word_to_guess[index];
                index++;
                for(char c: hint_string) 
                    std::cout << ((c != '_')?static_cast<char>(std::toupper(c)):c)  << ' ';
                
                std::cout << std::endl << std::endl;
            }
            else if(line == "exit") {
                break;
            }
            else {
                if(line == word_to_guess) {
                    std::cout << "Congratulations! You guessed it.\n\n";
                    break;
                } else {
                    std::cout << "Sorry! That is incorrect. Try again.\n\n";
                }
            }



        }

        
        char choice{};
        std::cout << "Play Again(type 'n' to exit, anything else to keep playing): ";


        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
        if(choice == 'n')
            break; 
    
    }












}




