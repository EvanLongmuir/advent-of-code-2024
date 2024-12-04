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
bool Day2::Report::Level::spreadBool(bool removed){
    if(last == nullptr){
        safe = true;
        return safe;
    }
    if(abs(value - next->value) > 3 ||      //large difference
            abs(value - last->value) > 3||
            value - next->value == 0 ||     //no difference
            value - last->value == 0 ||
            (last->value - value) * (value - next->value) < 0){ //increasing AND decreasing
        
        if(!removed){
            // try removing next Level
            if(next->next == nullptr){
                safe = last->spreadBool(true);
            }
            else{
                Level* temp = next;

                next = temp->next;
                safe = spreadBool(true);
                next = temp;
            }
            if(safe) return safe;   // removing next Level resulted in safe Report

            // try removing last Level
            Level* temp = last;

            last = temp->last;
            if(last != nullptr) last->next = temp->next;
            safe = spreadBool(true);
            if(last != nullptr) last->next = temp;
            last = temp;

            if(safe) return safe;   // removing last Level resulted in safe Report

            // try removing this Level
            last->next = next;  
            next->last = last;
            if(next->next == nullptr){
                safe = last->spreadBool(true);
            }
            else{
                safe = next->spreadBool(true);
            }
            next->last = this;
            last->next = this;
            
            if(safe) return safe;   // removing this Level resulted in safe Report
        }

        safe = false;
        return safe;
    }
    safe = last->spreadBool(removed);
    return safe;
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

    safe = temp->spreadBool(false);
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
