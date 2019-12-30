#include <vector>
#include <string>
#include <iostream>


void display(const std::vector<std::string>& words) {
    
    for(std::string word: words) {
        word[0] = 'H';
        std::cout << word << std::endl;
    }

}

int main() {

    std::vector<std::string> words{"Hello","there","cyrus"};
    display(words);

}
