#include "functions.h"

// for file reading
#include <iostream>
#include <fstream>

int main(){
    Crossword puzzle = Crossword();

    std::ifstream ReadFile("input.txt");

    std::string line;
    while(getline(ReadFile, line)){
        puzzle.addLine(line);
    }

    std::cout << puzzle.getWords() << std::endl;
}
