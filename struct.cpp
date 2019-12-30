#include <iostream>
#include <string>
#include <iomanip>



struct Movie {
    std::string title{};
    int year{};
    
    bool operator==(const Movie& movie) {
        return (title == movie.title) && (year == movie.year);
    }
};


void updateMovie(Movie& movie) {
    std::cout << "New Title: ";
    std::string new_title{};
    std::getline(std::cin,new_title);
    movie.title = new_title;

}

int main() {
    
    Movie movie{"Avengers",2018};
    Movie movie_2{"Avengers",2018};

    updateMovie(movie);

    std::cout << movie.title << std::endl;
}
