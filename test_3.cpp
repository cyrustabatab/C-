#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>


struct Movie {
    public: 
        Movie(std::string title,unsigned int year,unsigned int stars);
        friend std::ostream& operator<<(std::ostream& out,const Movie& m);
        bool operator==(const Movie& m1);


    private:
        std::string title{};
        unsigned int year{};
        unsigned int stars{};
};


Movie::Movie(std::string title,unsigned int year,unsigned int stars): title{title},year{year},stars{stars}{};

std::ostream& operator<<(std::ostream& out,const Movie& m) {
    out << "Movie" << "(" << m.title << ',' << m.year << ',' << m.stars << ')';

    return out;
}

bool Movie::operator==(const Movie& m1) {
   
    return this->title == m1.title && this->year == m1.year; 

}
/*
void display(const std::vector<Movie>& movies) {
    
    for(int i = 0;i < movies.size();++i) {
        Movie movie = movies.at(i);
        std::cout << movie.title << ' ' << movie.year << ' ' << movie.stars << std::endl;
    }
}
*/

int main() {
    
    unsigned int year{};



    Movie m1{"Avengers",year,5};
    Movie m2{"Lord of the Rings",2004,5};
    



    








}
