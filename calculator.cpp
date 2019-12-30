#include <iostream>
#include <string>
#include <cctype>


enum class Operation {
    ADD,
    SUBTRACT,
    DIVIDE,
    MULTIPLY
};

double multiply(double x,double y);
double add(double x,double y);
double subtract(double x,double y);
double divide(double x,double y);

Operation get_operation(std::string expression) {
    
    auto index = expression.find_first_not_of(" \n\t");

    
    unsigned int i{index};
    char c{};
    while(i < expression.size()) {
        c = expression[i];
        if(c == ' ') {
            i++;
            continue;
        } else if(c.isd
        

    }



}

int main() {
    
    std::string expression{};
    char choice{'y'};
    while(choice != 'n') {
        std::cout << "Calculation: ";

        std::getline(std::cin,expression);
        
        operation = get_operation(operation);



    }




}


double multiply(double x,double y) {
    return x * y;

}


double add(double x,double y ) {
    return x + y;
}

double subtract(double x,double y) {
    return x -y;

}


double divide(double x,double y) {
    return x/y;

}




