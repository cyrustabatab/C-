#include "board.hpp"




Board::Board(int rows,int cols): rows{rows},cols{cols} {
    
    board = new int*[rows];

    for(int row=0;row < rows;++row)
        board[row] = new int[cols];

    

}



