#include <list>
#include <iostream>
#include <limits>
#include <cctype>
#include <string>


void display_rankings(const std::list<std::string>& movies);
void change_ranking(std::list<std::string>& movies);
char get_choice();
int get_int(std::string prompt,int min=std::numeric_limits<int>::min(),int max=std::numeric_limits<int>::max());



int main() {


    std::cout << "The Movie Rankings Program\n\n";
    
    std::list<std::string> movies{"Casablanca","Wonder Woman","The Godfather","E.T.","The Bridge on the River Kwai"};
    
    char choice{'y'};
    while(choice != 'n') {
        display_rankings(movies);

        choice = get_choice();
        switch (choice) {
            case 'y':
                change_ranking(movies);
                break;
            case 'n':
                break;
            default:
                std::cout << "Invalid Choice!. Type 'y' or 'n'.\n";
                break;

        }
        

    }

}


char get_choice() {
    
    char choice{};
    std::cout << "Do you want to change any rankings? (y/n): ";
    
    std::cin  >> choice;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');


    return std::tolower(choice);

}


void change_ranking(std::list<std::string>& movies) {
    
    int current_ranking{},new_ranking{};

    current_ranking = get_int("Enter current ranking of a movie: ",1,movies.size());
    new_ranking = get_int("Enter new ranking of the movie: ",1,movies.size());
    
    
    auto iter = movies.begin();
    for(int i = 1;i <current_ranking;++i) {
           ++iter;
    }
    std::string movie{*iter};
    movies.erase(iter);

    
     iter = movies.begin();
    for(int i = 1;i < new_ranking;++i) {
        ++iter;
    }
    movies.insert(iter,movie);








}

void display_rankings(const std::list<std::string>& movies) {
    

    std::string title{"Movie Rankings"};
    std::cout << title << std::endl;

    std::string underline(title.size(),'-');

    std::cout << underline << std::endl;
    
    unsigned int count{1};
    for(auto iter =movies.begin();iter != movies.end();++iter) {
        std::cout << count << " - " << *iter << std::endl;
        ++count;
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
