#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <vector>

enum class Command: char {view='v',add='a',del='d',exit='x'};

struct Movie {
    std::string title{};
    unsigned int year{};
    unsigned int stars{};

    bool operator==(const Movie& movie);

};

bool Movie::operator==(const Movie& movie) {

    
    return (title == movie.title) && (year == movie.year);


}

void display_commands() {
    std::cout << "COMMANDS" << std::endl
              << static_cast<char>(Command::view) << " - View movie list" << std::endl
              << "a - Add a movie" << std::endl
              << "d - Delete a movie" << std::endl
              << "x - Exit" << std::endl << std::endl;

}

void discard_remaining_chars() {
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

}

char get_command() {
    
    char command{};
    std::cout << "Command: ";

    std::cin >> command;

    Command command = static_cast<Command>(command);
    discard_remaining_chars();
    return command;

}


std::vector<Movie> get_movies_from_file(std::string file_name) {
    

    std::vector<Movie> movies;
    std::ifstream input_file{file_name};

    if(input_file) {
    
        std::stringstream ss;
        std::string line{};
        std::string title{};
        unsigned int year{},stars{};
        while(std::getline(input_file,line)) {
            ss.str(line);
            ss.clear();
            
            std::getline(ss,title,'\t');

            ss >> year >> stars;


            Movie movie{title,year,stars};

            movies.push_back(movie);

        }

        input_file.close();



    }

    return movies;
    


}


void view_movies(const std::vector<Movie>& movies) {
    
    unsigned int number_width{4},title_width{20},year_width{8},star_width{5};
    
    std::cout << std::left << std::setw(number_width) <<' ' << std::setw(title_width) << "TITLE" << std::setw(year_width) << "YEAR" << std::setw(star_width) << "STARS" << std::endl;
    
    for(size_t i=0;i < movies.size();++i) {
        auto movie = movies.at(i);
        std::cout << std::setw(number_width) << i + 1 << std::setw(title_width) << movie.title << std::setw(year_width) << movie.year << std::setw(star_width) << movie.stars << std::endl;;

    }

    std::cout << std::endl;


}


bool valid_range(unsigned int start,unsigned int end,unsigned int number) {
    
    return number >= start && number <= end;
}

void write_movies_to_file(const std::vector<Movie>& movies,const std::string& file_name) {
    

    std::ofstream output_file{file_name};

    if(output_file) {
        
        for(Movie movie: movies) {
            output_file << movie.title << '\t' << movie.year << '\t' << movie.stars << std::endl;

        }


        output_file.close();


    }





}

unsigned int get_between(std::string prompt,unsigned int start,unsigned int end) {
    

    unsigned int number{};
    bool valid{false};
    while(!valid){
        
        std::cout << prompt;

        if(!(std::cin >> number)) {
            std::cout << "Please enter a YEAR!\n";
            std::cin.clear();
            discard_remaining_chars();
            continue;
        }

        valid= valid_range(start,end,number);

        if(!valid)  {
            std::cout << "Please enter year between " << start << " and " << end << std::endl;
            discard_remaining_chars();
        }
        
        



    }
    

    return number;

}
Movie get_movie() {
    
    std::string title{};
    unsigned int year{},stars{};
    std::cout << "Title: ";

    std::getline(std::cin,title);
    
        
    year = get_between("Year: ",1900,2020);
    stars = get_between("Stars: ",1,5);



    
    return Movie{title,year,stars};



}


void add_movie(std::vector<Movie>& movies,const std::string& file_name) {

    Movie movie{get_movie()};
    

    bool exists{false};

    for(Movie& m: movies) {
        if(movie == m) {
            exists = true;
            m.stars = movie.stars;
            break;
        }

    }



    if(exists) {
        write_movies_to_file(movies,file_name);
        std::cout << movie.title << " already exists and was updated!.\n";

    } else {
        movies.push_back(movie);
        write_movies_to_file(movies,file_name);
        std::cout << movie.title << " was added!\n";


    }

    
}


void delete_movie(std::vector<Movie>& movies) {
    
    if(movies.size() == 0) {
        std::cout << "No movies to delete!\n";
        return;
    }

    int number{};
    while(true) {
        std::cout << "Number: ";
        if(!(std::cin >> number)) {
            std::cout << "Please enter a NUMBER!\n";
            std::cin.clear();
            discard_remaining_chars();
            continue;
        } else {
            if (number <= 0 || number > movies.size()) {
                if(movies.size() > 1)
                    std::cout << "Please enter a number between " << 1 << " and " << movies.size() - 1 << std::endl;
                else
                    std::cout << "Can only delete Movie 1!" << std::endl;
                discard_remaining_chars();
                continue;
            }
            break;


        }


    }

    movies.erase(movies.begin() + number - 1);



}




 
int main() {
    
    std::cout << "The Movie List Program\n\n";
    
    const std::string file_name{"movies.txt"};

    std::vector<Movie> movies{get_movies_from_file(file_name)};
    
    bool exit{false};
    while(true) {
        display_commands();

        Command command{get_command()};

        switch (command) {
            case Command::view:
                if(movies.size() ==0) {
                    std::cout << "No movies to display!\n";
                    continue;
                }
                view_movies(movies);
                break;
            case Command::add:
                add_movie(movies,file_name);
                break;
            case Command::del:
                delete_movie(movies);
                break;
            case Command::exit:
                exit = true;
                break;
            default:
                std::cout << "Unrecognized Command! Please try again!\n";
                break;

        }


        if(exit)
            break;

    }

    std::cout << "\n\nBye!";

    return 0;
}

