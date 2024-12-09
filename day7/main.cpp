#include "functions.h"

// for file reading
#include <iostream>
#include <fstream>

int main(){
    Calibrations calibration = Calibrations();

    std::ifstream ReadFile("input.txt");

    std::string line;
    while(getline(ReadFile, line)) calibration.readLine(line);

    std::cout << calibration.getSum() << std::endl;
}
