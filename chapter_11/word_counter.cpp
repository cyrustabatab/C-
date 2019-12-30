#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>



std::vector<std::string> load_words_from_file(const std::string file_name);
std::map<std::string,int> get_word_counts(const std::vector<std::string>& words);

void display(std::pair<std::string,int> p);
bool over_1(std::pair<std::string,int> p);

int main() {
    
    const std::string file_name{"dickens.txt"};


    std::vector<std::string> words{load_words_from_file(file_name)};
    
    std::cout << words.size() << " WORDS: ";
    std::for_each(words.begin(),words.end(),[](auto value) {std::cout << value << ' ';});
    

    std::map<std::string,int> word_counts{get_word_counts(words)};
    std::cout << "\n\n" << word_counts.size() << " UNIQUE WORDS: ";
    std::for_each(word_counts.begin(),word_counts.end(),[](auto p) {std::cout << p.first << ' ';});


    
    std::cout << "\n\nCOUNT PER WORD: ";
    std::for_each(word_counts.begin(),word_counts.end(),display);
    
    std::cout << std::endl << std::endl;

    std::cout << std::count_if(word_counts.begin(),word_counts.end(),over_1) << " DUPLICATE WORDS";


    

}


std::vector<std::string> load_words_from_file(const std::string file_name) {
    
    std::vector<std::string> words{};
    std::ifstream input_file{file_name};
    std::stringstream ss; 

    if(input_file) {
        
        std::string line{};

        while(std::getline(input_file,line)) {
            
            ss.str(line);
            ss.clear();
            std::string word{};
            while(ss >> word) {
                std::string new_word{};
                int i{};
                for(char c: word) {
                    if(std::ispunct(c)) {
                        if(c == '\'' && i > 0 && i < word.size() - 1) {
                            new_word += c;
                        }
                    }
                    else  {
                        new_word += std::tolower(c);
                    }
                    ++i;
                }


                words.push_back(new_word);
                

            }

        }


        input_file.close();
    }

    return words;

}


std::map<std::string,int> get_word_counts(const std::vector<std::string>& words) {
    
    std::map<std::string,int> word_counts{};
    
    for(std::string word: words) {
        auto iter = word_counts.find(word);

        if(iter == word_counts.end()) {
           word_counts[word] = 1; 
        } else {
            word_counts[word] += 1;
        }

    }

    return word_counts;
}
    

void display(std::pair<std::string,int> p) {
    
    std::cout << p.first << '=' << p.second << ' ';
}
bool over_1(std::pair<std::string,int> p) {
    
    return p.second > 1;
}



