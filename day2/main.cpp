#include "functions.h"

// for file reading
#include <iostream>
#include <fstream>

int main(){
    std::ifstream ReadFile("input.txt"); 

    Day2 day2 = Day2();

    int output;
    while(ReadFile >> output){
        day2.addToReport(output);
        if(ReadFile.peek() == '\n'){
            day2.newReport();
        }
    }

    std::cout << day2.numSafe << std::endl;
}
