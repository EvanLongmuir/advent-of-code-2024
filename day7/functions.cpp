#include "functions.h"

// Constructors
Calibrations::Equation::Number::Number(unsigned long value){
    this->value = value;
    next = nullptr;
}

Calibrations::Equation::Equation(unsigned long value){
    this->value = value;
    head = nullptr;
    next = nullptr;
}

// Destructors
Calibrations::Equation::~Equation(){
    while(head != nullptr){
        Number* temp = head->next;
        delete head;
        head = temp;
    }
}

Calibrations::~Calibrations(){
    while(head != nullptr){
        Equation* temp = head->next;
        delete head;
        head = temp;
    }
}

// Member Functions
void Calibrations::Equation::addNumber(unsigned long number){
    if(head == nullptr){
        head = new Number(number);
        return;
    }

    Number* temp = head;
    while(temp->next != nullptr) temp = temp->next;

    temp->next = new Number(number);
    return;
}

bool Calibrations::Equation::checkValid(Number* number, unsigned long currentResult){
    if(number == nullptr) return currentResult == value;
    if(checkValid(number->next, currentResult + number->value)) return true;
    if(currentResult != 0 && checkValid(number->next, currentResult * number->value)) return true;
    return false;
}

void Calibrations::newEquation(unsigned long value){
    Equation* newEquation = new Equation(value);
    newEquation->next = head;
    head = newEquation;
}

void Calibrations::addToEquation(unsigned long value){
    head->addNumber(value);
}

unsigned long Calibrations::getSum(){
    unsigned long currentSum = 0;
    Equation* temp = head;
    while(temp != nullptr){
        if(temp->checkValid(temp->head)) currentSum += temp->value;
        temp = temp->next;
    }
    return currentSum;
}

void Calibrations::readLine(std::string line){
    unsigned long i = 0;
    unsigned long digit = 0;
    bool first = true;
    bool currentlyDigit = false;
    while(line[i] != '\0'){
        if(isdigit(line[i])){
            digit = digit * 10;
            digit += line[i] - '0';
            currentlyDigit = true;
        }
        else if(currentlyDigit){
            if(first) newEquation(digit);
            else addToEquation(digit);

            first = false;
            currentlyDigit = false;
            digit = 0;
        }
        i++;
    }
    if(currentlyDigit){
        addToEquation(digit);
    }
}
