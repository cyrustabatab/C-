#include "ttt.hpp"
#include <iostream>



Board::Board(int rows,int cols): rows{rows},cols{cols} {

    board = new char*[rows];
    
    for(int i =0;i < rows;++i) {
        board[i] = new char[cols];
        for(int col=0;col < cols;++col) {
            board[i][col] = ' ';
        }
    }


}


void Board::display() {
    
    
    std::cout << "  ";

    for(int i =1;i <= cols;++i) {
        std::cout << i << ' ';

    }
    std::cout << std::endl;
    std::string boundary(2 * cols + 2,'-');

    for(int row=0;row < rows;++row) {
        std::cout << row + 1 << '|';
        for(int col=0;col < cols;++col) {
            std::cout << board[row][col] << '|';
        }

        std::cout << std::endl;
        std::cout <<' ' <<  boundary << std::endl;
    }
    int row{}; 



}




int main() {

    
    Board board{};

    board.display();

}

