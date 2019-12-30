#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

namespace lower {

void tolower(std::string& s) {
    
    for(char& c: s)
        c = std::tolower(c);


}

}


bool equalsIgnoreCase(const std::string& s1,const std::string& s2) {
    
    if(s1.size() != s2.size())
        return false;

    for(size_t i=0;i < s1.size();++i) {
        if(std::tolower(s1[i]) != std::tolower(s2[i]))
            return false;
    }

    return true;




}

void swap(int& a,int &b){
    
    int temp = a;
    a = b;
    b = temp;




}


int fibonacci(int n) {
  if(n == 0) 
      return 0;
    
  if(n == 1)
      return 1;

    
  return fibonacci(n -1) + fibonacci(n -2);

}

int main() {
    
    std::string s1{"HELLO"};
    
    std::string s2{"HeLlo"};


    std::cout << std::boolalpha << equalsIgnoreCase(s1,s2) << std::endl;

    return 0;
}




