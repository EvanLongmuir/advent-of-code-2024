#include "functions.h"
//Constructors
MemoryReader::Mul::Mul(int num1, int num2){
    this->num1 = num1;
    this->num2 = num2;

    product = num1 * num2;

    next = nullptr;
}

MemoryReader::MemoryReader(){
    head = nullptr;
    sum = 0;
    enable = true;
}

//Destructors
MemoryReader::Mul::~Mul(){}

MemoryReader::~MemoryReader(){
    Mul* temp;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}

//Member Functions
void MemoryReader::addMul(int num1, int num2){
    Mul* newMul = new Mul(num1, num2);
    newMul->next = head;
    head = newMul;

    sum += newMul->product;
}

unsigned int MemoryReader::onCharM(std::string line, unsigned int pos){
    if(line[pos] != 'm') return pos - 1;
    if(line[pos+1] != 'u') return pos;
    if(line[pos+2] != 'l') return pos + 1;
    if(line[pos+3] != '(') return pos + 2;

    int counter = 4;
    if(!isdigit(line[pos+counter])) return pos + counter - 1;

    int first = 0;
    for(int i = 0; i < 3; i++){
        if(!isdigit(line[pos+counter])){
            break;
        }
        first = first * 10;
        first += line[pos+counter] - '0';
        counter++;
    }

    if(line[pos+counter] != ',') return pos + counter - 1;
    counter++;

    if(!isdigit(line[pos+counter])) return pos + counter - 1;

    int second = 0;
    for(int i = 0; i < 3; i++){
        if(!isdigit(line[pos+counter])){
            break;
        }
        second = second * 10;
        second += line[pos+counter] - '0';
        counter++;
    }

    if(line[pos+counter] != ')') return pos + counter - 1;

    addMul(first, second);
    return pos + counter;
}

unsigned int MemoryReader::onCharD(std::string line, unsigned int pos){
    if(line[pos] != 'd') return pos - 1;
    if(line[pos+1] != 'o') return pos;

    if(line[pos+2] == '('){
        if(line[pos+3] != ')') return pos + 2;

        enable = true;
        return pos + 3;
    }

    if(line[pos+2] != 'n') return pos + 1;
    if(line[pos+3] != '\'') return pos + 2;
    if(line[pos+4] != 't') return pos + 3;
    if(line[pos+5] != '(') return pos + 4;
    if(line[pos+6] != ')') return pos + 5;

    enable = false;
    return pos + 6;

}

void MemoryReader::readLine(std::string line){
    int i = 0;

    while(line[i] != '\0'){
        if(enable && line[i] == 'm') i = onCharM(line, i);
        if(line[i] == 'd') i = onCharD(line, i);
        if(line[i] == '\0') return;

        i++;
    }
}

int MemoryReader::getSum(){
    return sum;
}
