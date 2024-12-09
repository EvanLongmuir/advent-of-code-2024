#include "functions.h"

// for file reading
#include <iostream>
#include <fstream>

int main(){
    Grid grid = Grid();

    std::ifstream ReadFile("input.txt");
    std::string line;
    while(getline(ReadFile, line)) grid.readLine(line);
    ReadFile.close();

    std::cout << grid.getNodesVisted() << std::endl;
    std::cout << grid.getLoopNodes() << std::endl;
}
