#include "functions.h"

// for file reading
#include <iostream>
#include <fstream>

int main(){
    MemoryReader reader = MemoryReader();

    std::ifstream ReadFile("input.txt");
    std::string line;
    while(getline(ReadFile, line)){
        reader.readLine(line);
    }
    ReadFile.close();

    std::cout << reader.getSum() << std::endl;
}
