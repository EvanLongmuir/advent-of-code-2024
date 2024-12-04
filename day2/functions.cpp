#include "functions.h"
//Constructors
Day2::Report::Level::Level(int input){
    value = input;
    next = nullptr;
    last = nullptr;
    safe = true;
}

Day2::Report::Report(){
    head = nullptr;
    next = nullptr;
    safe = true;
}

Day2::Day2(){
    head = nullptr;
    numSafe = 0;
    newReport();
}

//Destructors
Day2::Report::Level::~Level(){
    next = nullptr;
}

Day2::Report::~Report(){
    Level* temp;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}

Day2::~Day2(){
    Report* temp;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}

//Member Function
//MUST BE CALLED FROM END OF LINKED LIST
bool Day2::Report::Level::spreadBool(){
    if(last == nullptr || !safe){
        return safe;
    }
    if(abs(value - next->value) > 3 ||      //large difference
            abs(value - last->value) > 3||
            value - next->value == 0 ||     //no difference
            value - last->value == 0 ||
            (last->value - value) * (value - next->value) < 0){ //increasing AND decreasing
        
        safe = false;
        return safe;
    }
    return last->spreadBool();
}

void Day2::Report::addLevel(int value){
    Level* newLevel = new Level(value);

    if(head == nullptr){
        head = newLevel;
        return;
    }

    Level* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newLevel;
    newLevel->last = temp;

    safe = temp->spreadBool();
}

void Day2::addToReport(int value){
    head->addLevel(value);
}

void Day2::newReport(){
    Report* newReport = new Report();

    if(head == nullptr){
        head = newReport;
        return;
    }

    if(head->safe) numSafe++;

    newReport->next = head;
    head = newReport;
}
