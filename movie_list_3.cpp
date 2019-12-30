#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <list> 
#include <limits>
#include <sstream>
#include <cctype>


enum class Command: char {view='v',add='a',del='d',mod='m',exit='x'};

struct Movie {
    std::string title{};
    unsigned int year{};
    unsigned int stars{};
    bool operator==(const Movie& movie) {
        return year == movie.year && title == movie.title;
    }

};


void display_menu();
std::list<Movie> load_movies_from_file(std::string file_name);
void write_movies_to_file(std::string file_name);
void add_movie(std::list<Movie>& movies);
void view_movies(const std::list<Movie>& movies);
void modify_movie(std::list<Movie>& movies);
void delete_movie(std::list<Movie>& movies);
unsigned int get_int(std::string prompt,unsigned int min=0,unsigned int max=std::numeric_limits<unsigned int>::max());
Command get_command();

int main() {
    
    std::cout << "The Movie List Program\n\n";
    
    const std::string file_name{"movies.txt"};
    std::list<Movie> movies{load_movies_from_file(file_name)};

    Command command{Command::view};
    
    while(command != Command::exit) {
        display_menu();
        

        command = get_command();

        switch (command) {
            case Command::view:
                view_movies(movies);
                break;
            case Command::add:
                break;
            case Command::del:
                break;
            case Command::exit:
                break;
            case Command::mod:
                break;
            default:
                std::cout << "Invalid command " << static_cast<char>(command) << std::endl;
                break;

        }


    }



}

std::list<Movie> load_movies_from_file(std::string file_name) {
    
    std::list<Movie> movies{};

    std::ifstream input_file{file_name};
    
    std::stringstream ss;

    if(input_file) {
        
        std::string title{};
        unsigned int year{},stars{};
        std::string line{};
        while(std::getline(input_file,line)) {
            ss.str(line);
            ss.clear();
            
            std::getline(ss,title,'\t');

            ss >> year >> stars;
            
            Movie movie{title,year,stars};

            movies.push_front(movie);
        }

        input_file.close();

    }

    return movies;

}


void view_movies(const std::list<Movie>& movies){
    
    const unsigned int number_width{4},title_width{20},year_width{8};
    unsigned int count{1};
    std::cout << std::left;
    std::cout << std::setw(number_width) << "" << std::setw(title_width) << "TITLE" << std::setw(year_width) << "YEAR" << "STARS" << std::endl;
    auto iter = --movies.end();


    for(size_t i=1;i <= movies.size();++i) {
        std::cout << std::setw(number_width) << i << std::setw(title_width) << iter->title << std::setw(year_width) << iter->year << iter->stars << std::endl;

        --iter;
    }

    std::cout << std::endl;

}
Command get_command() {
    
    char command{};

    std::cout << "Command: ";

    std::cin >> command;
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    return static_cast<Command>(std::tolower(command));

}

unsigned int get_int(std::string prompt,unsigned int min,unsigned int max) {
    
     unsigned int number{};

    while(true) {
        std::cout << prompt;
        
        if(!(std::cin >> number)) {
            std::cout << "Please enter a NUMBER\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        } else {
            if(!(number >= min && number <= max)) {
                std::cout << "Please enter a number between " << min << " and " << max << std::endl;
                continue;
            }

            break;

        }
    }
    return number;


}

void add_movie(std::list<Movie>& movies) {
    
    std::string title{};
    unsigned int year{},stars{};
    std::cout << "Enter Title: ";
    std::getline(std::cin,title);

    year = get_int("Enter Year: ",1900,2020);
    stars = get_int("Enter Stars: ",1,5);

    Movie m{title,year,stars};

    movies.push_front(m);





}

void write_movies_to_file(std::string file_name,const std::list<Movie>& movies) {
    
    std::ofstream output_file{file_name,std::ios::app};
    
    if(output_file) {
        
        auto iter = --movies.end();
        for(size_t i= 1;i <= movies.size();++i)  {
            output_file << iter->title << '\t' << iter->year<< '\t' << iter->stars << std::endl;
            --iter;
        }

        output_file.close();
    }



}
void modify_movie(std::list<Movie>& movies) {

    unsigned int movie_number{get_int("Number: ",1,movies.size()) - 1};


    auto iter = movies.begin();

    for(size_t i=0;i < movie_number;++i) {
        ++movies;

    }

    unsigned int new_stars{get_int("Enter new number of stars (1-5) for " + iter->title+ ":",1,5)};

    iter->stars = new_stars;
    

    std::cout << iter->title << " was updated." << std::endl << std::endl;




}
void delete_movie(std::list<Movie>& movies) {

    unsigned int movie_number{get_int("Number: ",1,movies.size()) - 1};


    auto iter = movies.begin();

    for(size_t i=0;i < movie_number;++i) {
        ++iter;

    }

    movies.erase(iter);
}
void display_menu() {
    
    std::cout << "COMMANDS" << std::endl
              << "v - View Movie List" << std::endl
              << "a - Add a movie" << std::endl
              << "d - Delete a movie" << std::endl
              << "m - Modify a movie" << std::endl
              << "x - Exit" << std::endl << std::endl;
    

}







