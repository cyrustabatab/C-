#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <limits>


struct Date {
    int month{};
    int year{};
    int day{};

}

struct Movie {
    std::string title{};
    int year{};
    Date date{};

};


bool valid_range(int year,int start,int end) {
    
    
    return year >= start && year <= end; 
    
    


}

int main() {
    
    std::cout << std::left << "The Movie List Program\n\n";

    
    std::string file_name{"movies.txt"};

    std::ofstream output_file{file_name,std::ios::app};
    const unsigned int width{7};
    char choice{'y'};

    std::vector<Movie> movies;
    
    std::string movie_name{};

    int start{1900},end{2020};
    Movie movie;
    int year{};
    while(choice != 'n') {
        std::cout << std::setw(width) << "Title:";

        std::getline(std::cin,movie_name);

    
        while(true) {
            
            std::cout << std::setw(width) << "Year:";

            if(!(std::cin >> year)) {
                std::cout << "Please enter a YEAR!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }

            if(!valid_range(year,start,end)) {
                std::cout << "Movie Year must be between " << start << " and " << end << std::endl; 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            break;

        }

        
        movie.title = movie_name;
        movie.year = year;

        movies.push_back(movie);

        
        std::cout << "\nContinue(y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        choice = std::tolower(choice);



    }


    std::cout << "\n\nMovies Added\n";

    for(Movie m: movies) {
        std::cout << m.title << ' ' << m.year << std::endl;
        output_file << m.title << ' ' << m.year << std::endl;

    }


}





