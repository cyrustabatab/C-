#include <iostream>
#include <limits>
#include <cctype>
#include "console.hpp"

enum class Department {marketing=1,it,sales,other}; //group related constants


void show_menu();
Department get_department();
bool check_criteria(Department)

int main() {
    

    std::cout << "The Monthly Bonus Calculator\n\n";

    
    show_menu();


    Department department{get_department()};

    bool bonus{check_criteria(department)};
    
    const double bonus_amount{1000.0};

    if(bonus) {
        std::cout << "Congrats! You earned the $" << bonus_amount << " monthly bonus.\n\n";

    } else {
        std::cout << "Sorry! No bonus for you this month :( Keep trying!\n\n"; 
        
    }

    return 0;


}


bool check_criteria(Department dept) {
    
    switch (dept) {
        
        case Deparment::marketing:
            int viral_campaigns{};
            viral_campaigns = console::get_int("How many of your campaigns went viral this month?: ")
            return viral_campaigns >= 4;
        case Department::it:
            int trouble_tickets{console::get_int("How many trouble tickets did you close this month?: ")};
            return trouble_tickets >= 10;
        case Department::sales:
            double sales{};
            sales = console::get_double("What were your total sales this month? ");
            return sales >= 1000;
        case Department::other:
            char supervisor_grade = console::get_char("What was your grade from your supervisor this month");
            return std::tolower(supervisor_grade) == 'a';

    }

}

void show_menu() {
    
    std::cout << "DEPARTMENTS" << std::endl
              << "1. Marketing" << std::endl
              << "2. IT" << std::endl
              << "3. Sales" << std::endl
              << "4. Other" << std::endl << std::endl;
            

}


Department get_department() {
    
    int department_number{};
    while(true) {
        std::cout << "Enter department number: ";

        if(!(std::cin >> department_number)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        } else {
           Department department = static_cast<Department>(department_number);
           if(department_number < Department::marketing || department_number > Department::sales)
               return Department::other;
           else
               return d;
        }

        

    }


}
