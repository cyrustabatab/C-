#include <iostream>
#include <climits>
#include <cstdio>
#include <cwchar>



int main() {

    //L for long double,l for double    
    //
    //
    //w car
    //L: wchar_t, u: char_16_t, U: char_32_tjj
    

    enum class Color {
       RED,
       BLACK
    };


    Color color = Color::RED;

    printf("%zd",sizeof(color));
    

    switch(color) {
        case Color::RED: 
            std::cout << "RED";
            break;
        case Color::BLACK:
            std::cout << "BLACK";
        default:
            std::cout << "Invalid";

    }



    struct Book {
        char name[256]{};
        int year;
        int pages{};
        bool hardcover{};

    };


    Book book;

    std::cout << book.year << " " << book.pages << " " << book.hardcover;


    union Variant {
        char string[10];
        int integer;
        double floating_point;

    };


    Variant v;

    for(size_t i =0;i < 10;i++){
        v.string[i] = 'h';
    }

    
    struct Year {
        void add_year(){
            year++;
        }
        int year{};

    };

    unsigned int x{4};    
    std::cout << x;
    x -= 10;
    std::cout << x;

}
    
