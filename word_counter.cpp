#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <limits>
#include <algorithm>


std::vector<std::string> load_words_from_file(std::string file_name);
std::map<std::string,int> count_words(const std::vector<std::string>& words);

void display_words(const std::vector<std::string>& words);

void display_unique_words(const std::map<std::string,int>& word_counts);
void display_word_counts(const std::map<std::string,int>& word_counts);

int main() {
    
    std::cout << "The Word Counter Program\n\n";

    std::string file_name{"dickens.txt"};


    std::vector<std::string> words{load_words_from_file(file_name)};

    std::map<std::string,int> word_counts = count_words(words);


    display_words(words);
    display_unique_words(word_counts);
    display_word_counts(word_counts);
    



}


void display_words(const std::vector<std::string>& words) {
   
    unsigned int max_size{0};
    
    std::cout << words.size() << " WORDS" << std::endl;
    unsigned int count{1};
    for(std::string word: words)  {
        max_size = std::max(max_size,word.size());
        std::cout << word <<' ';

        if(count % 10 ==0) {
            std::cout << std::endl;
        }

        ++count;



    }

    std::cout << std::endl << std::endl;
    




}


std::map<std::string,int> count_words(const std::vector<std::string>& words) {
    
    std::map<std::string, int> word_counts{};
    for(const std::string& word: words) {
        auto iter = word_counts.find(word);
        if(iter == word_counts.end()) {
            word_counts[word] = 1;
        } else {
            word_counts[word] += 1;
        }
        

    }

    return word_counts;

}


void display_unique_words(const std::map<std::string,int>& word_counts) {
    
    std::cout << word_counts.size() << " UNIQUE WORDS" << std::endl;
    unsigned int count{1};
    for(std::pair<std::string,int> pair: word_counts) {
        std::cout << pair.first << ' ';

        if(count % 10 ==0) {
            std::cout << std::endl;
        }

        ++count;
    }

    std::cout << std::endl << std::endl;
}

void display_word_counts(const std::map<std::string,int>& word_counts) {
    
    std::cout << "COUNT PER WORD" << std::endl;
    unsigned int count{1};
    for(std::pair<std::string,int> pair: word_counts) {
        std::cout << pair.first << '=' << pair.second << ' ';

        if(count % 10 == 0) {
            std::cout << std::endl;
        }

        ++count;
    }

    std::cout << std::endl << std::endl;

}
std::vector<std::string> load_words_from_file(std::string file_name) {
    

    std::vector<std::string> words{};

    std::ifstream input_file{file_name};

    if(input_file) {
        std::string word{};

        while(input_file >> word) {
            
            std::string new_word{}; //modify original word so that it removes punctuation unless apo
            

            for(int i =0;i < word.size();++i) {
                char c{word[i]};
                if(std::ispunct(c)) {
                    if(c == '\'') {
                        if(i > 0 && i < word.size() - 1) {
                            new_word += c;
                        }
                    }
                } else {
                    new_word += std::tolower(c);
                }

                    

            }

            words.push_back(new_word);

        }
        
        


    }


    return words;

}
