#include <iostream>

class Crossword{
    private: 
        struct Letter{
            Letter* left;
            Letter* diagL;
            Letter* up;
            Letter* diagR;
            // right is special since its only used to build out the graph
            Letter* right;

            char value;

            unsigned int findWords();
            bool findWordsLeft();
            bool findWordsDiagL();
            bool findWordsUp();
            bool findWordsDiagR();

            bool findX();

            Letter(char letter);
            ~Letter();
        };
        Letter* head;

        unsigned int words;
        unsigned int xs;

        unsigned int addLetter(char letter);
    public:
        void addLine(std::string line);
        unsigned int getWords();
        unsigned int getXs();

        Crossword();
        ~Crossword();
};
