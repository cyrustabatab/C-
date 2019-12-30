#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <sstream>


std::multiset<std::string> display_and_load_words_from_file(std::string file_name);
std::set<std::string> get_unique_words(std::multiset<std::string> words);

int main() {
    
    std::cout << "The Word Counter program\n\n";

    std::string file_name{"dickens.txt"};
    std::multiset<std::string> words{display_and_load_words_from_file(file_name)};
    
    std::cout << "WORD COUNT: " << words.size() << std::endl << std::endl;


    std::set<std::string> unique_words{get_unique_words(words)};
    
    std::cout << unique_words.size() << " UNIQUE WORDS: ";
    for(auto word:unique_words) {
        std::cout << word << ' ';
    }
    std::cout << std::endl<< std::endl;
    
    std::cout << "COUNT PER WORD: ";

    for(auto word:unique_words) {
        std::cout << word << '=' << words.count(word) << ' ';

    }
}


std::set<std::string> get_unique_words(std::multiset<std::string> words) {
    
    std::set<std::string> unique_words{};
    
    for(auto word: words) {
        unique_words.insert(word);
    }


    return unique_words;

}

std::multiset<std::string> display_and_load_words_from_file(std::string file_name) {
    
    
    std::multiset<std::string> words{};

    std::ifstream input_file{file_name};

    if(input_file) {
        
        std::cout << "FILE TEXT\n";
        std::string line{};
        std::string word{};
        std::stringstream ss;
        while(std::getline(input_file,line)) {

            std::cout << line << std::endl;
            ss.str(line); 
            ss.clear();
            

            while(ss >> word) {
                std::string new_word{};
                
                char c{};
                for(int i =0;i < word.size();++i) {
                     c = word[i];
                    if (std::ispunct(c)) {
                        if(c == '\'') {
                            if(i > 0 && i < word.size() - 1) {
                                new_word += c; 
                            }
                        }
                    } else {
                        new_word += std::tolower(c);
                    }

                }

                words.insert(new_word);


            }

        }
        
        input_file.close();

        std::cout << std::endl;
    }

    return words;



}

