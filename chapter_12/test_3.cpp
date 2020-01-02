#include <iostream>



template<typename T> 
T add(T x,T y) {
    return x + y;

}



int main() {
    
    add(4.5,4.2);
    add(4,2);

    std::string s1{"hello"};
    std::string s2{"there"};
    add(s1,s2);


}
