
struct ConnectK {
    public: 
        
        ConnectK(unsigned int k=4,unsigned int width=7,unsigned int height=8): k{k},width{width},height{height} {};
        
        void display();
        unsigned int getK() {return k};
        unsigned int getWidth() {return width};
        unsigned int getHeight() {return height};

    private:
        unsigned int k;
        unsigned int width;
        unsigned int height;



};


ConnectK::display() {

}

int main() {

    ConnectK game{};


    print(game.



}
