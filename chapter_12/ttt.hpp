#ifndef board_hpp
#define board_hpp


class Board {
    public:
        Board(int rows=3,int cols=3);
        
        void display();

    private:
        int rows,cols;
        char** board;






};


#endif
