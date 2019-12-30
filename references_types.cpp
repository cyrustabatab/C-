#include <iostream>
#include <cstdio>


struct Date {
    unsigned int year{},month{},day{};
    
    void setYear(unsigned int year);
    
    unsigned int getYear() {return year;};
};

void Date::setYear(unsigned int year) {
    this->year = year;

}

int main() {
    

    Date* date = new Date{2020,5,29};
    
    printf("Address of date: %p\n",date);
    printf("Date's Year: %d\n",date->getYear());
    
    date->setYear(2021);
    printf("Address of date: %p\n",date);
    printf("Date's Year: %d\n",date->getYear());

}
