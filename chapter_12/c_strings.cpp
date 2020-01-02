#include <iostream>
#include <limits>


int main() {

    

    const int size{15};

    char state_1[size]{""};
    char state_2[size]{""};

    
    
    //char (*states[])[]j
    char* states[size]{state_1,state_2};

    

    for(int i=0;i < 2;++i) {
        char* state = states[i];
        while(true) {
            std::cout << "Enter state " << i + 1 << " name: ";

            if(!(std::cin.getline(state,size))) {
                std::cout << "You entered too many characters!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            } else {
        //        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                break;
            }


        }

    }



    std::cout << "State 1 code is " << state_1 << std::endl;
    std::cout << "State 2 code is " << state_2 << std::endl << std::endl;








}





