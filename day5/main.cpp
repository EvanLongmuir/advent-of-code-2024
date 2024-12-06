#include "functions.h"

// for file reading
#include <iostream>
#include <fstream>

int main(){
    Manual manual = Manual();

    std::ifstream ReadFile("input.txt");
    std::string line;
    while(getline(ReadFile, line)) manual.readLine(line);
    ReadFile.close();

    std::cout << manual.addMiddleValues(true) << std::endl;
    std::cout << manual.addMiddleValues(false) << std::endl;
}
