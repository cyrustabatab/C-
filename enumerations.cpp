#include <iostream>

enum class Operation {add,subtract,multiply,divide};


double calculate(Operation op,double num1,double num2) {
    
    switch (op) {
        case Operation::add:
            return num1 + num2;
        case Operation::subtract:
            return num1 - num2;
        case Operation::multiply:
            return num1 * num2;
        case Operation::divide:
            return num1/num2;

    }

}

int main() {

    


}
