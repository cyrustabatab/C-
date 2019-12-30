#include <iostream>


int main() {
    
    

    enum class Operation {
        Add,
        Subtract,
        Multiply,
        Divide

    };


    struct Calculator {
        
        /*
        Calculator() {
            this->operation = Operation::Add;
        }
        */
        /*
        Calculator(Operation operation) {
            this->operation = operation;
        }
        */


        int calculate(int a,int b) {
            
            switch(operation) {
                
                case Operation::Add:
                    return a + b;
                case Operation::Subtract:
                    return a- b;
                case Operation::Multiply:
                    return a * b;
                case Operation::Divide:
                    return a / b;

            }

        }

        private:
            Operation operation{Operation::Add};
            char key_location[12]{"Hello there"};



    };



    Calculator calculator;
    std::cout << calculator.calculate(4,5) << std::endl;





}



