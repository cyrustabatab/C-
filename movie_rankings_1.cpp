#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>
#include <cctype>

void display_rankings(const std::vector<std::string>& movies);
char get_choice();
void change_ranking(std::vector<std::string>& movies);
int get_int(std::string prompt,int min=std::numeric_limits<int>::min(),int max=std::numeric_limits<int>::max());



int main() {
    

    std::cout << "The Movie Rankings Program\n\n"; 
    
    std::vector<std::string> movies {"Harry Potter","Lord of the Rings","Game of Thrones","Hobbit","Witcher"};

    
    char choice{'y'};

    while (choice != 'n') {
        display_rankings(movies);

        choice = get_choice();
        
        switch(choice) {
            case 'y':
                change_ranking(movies);
                break;
            case 'n': 
                break;
            default:
                std::cout << "Invalid Choice. Please type 'y' or 'n'!" << std::endl;
                break;

        }






    }




}

char get_choice() {
    char choice{}; 
    std::cout << "Do you want to change any rankings(y/n): ";

    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    return std::tolower(choice);
}

void display_rankings(const std::vector<std::string>& movies) {
    

    std::string title{"Movie Rankings"};
    std::cout << title << std::endl;
    std::string underline(title.size(),'-');
    std::cout << underline << std::endl;
    unsigned int i{1};
    for(const std::string& movie: movies) {
        std::cout << i << " - " << movie << std::endl;;
        ++i;
            
    }

    std::cout << std::endl;

}

int get_int(std::string prompt,int min,int max) {
    
    int number{};

    while(true) {
        std::cout << prompt;

        if(!(std::cin >> number)) {
            std::cout << "Please enter a number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        } else {
            if(!(number >= min && number <= max)) {
                std::cout << "Please enter number between " << min << " and " << max << std::endl;
            } else {
                break;
            }

        }
    }

    return number;


}

void change_ranking(std::vector<std::string>& movies) {
    
    
    int movie_to_change{get_int("Enter current ranking of a movie: ",1,movies.size()) -1};

    int new_ranking{get_int("Enter new ranking of movie: ",1,movies.size()) - 1};

    
    std::string movie{movies.at(movie_to_change)};
    movies.erase(movies.begin() + movie_to_change);
    movies.insert(movies.begin() + new_ranking,movie);


    


}



