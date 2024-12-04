#include "functions.h"

// for file reading
#include <iostream>
#include <fstream>

int main(){
    Day1 day = Day1();

    std::ifstream ReadFile("input.txt");

    int fileOutput1;
    int fileOutput2;
    while(ReadFile >> fileOutput1 >> fileOutput2){
        day.addNodePair(fileOutput1, fileOutput2);
    }

    ReadFile.close();

    std::cout << day.getTotalDiff() << std::endl;

    std::cout << day.getTotalSimularityScore() << std::endl;
}
