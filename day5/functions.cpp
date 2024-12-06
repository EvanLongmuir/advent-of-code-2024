#include "functions.h"

//Constructors
Manual::Rule::Rule(int rules[2]){
    next = nullptr;

    this->rules[0] = rules[0];
    this->rules[1] = rules[1];
}

Manual::Update::Page::Page(int value){
    next = nullptr;
    last = nullptr;

    this->value = value;
}

Manual::Update::Update(){
    next = nullptr;
    pages = nullptr;

    valid = true;
    numPages = 0;
    middleValue = 0;
}

Manual::Manual(){
    rules = nullptr;
    updates = nullptr;
}

//Destructors
Manual::Update::~Update(){
    Page* temp;
    while(pages != nullptr){
        temp = pages->next;
        delete pages;
        pages = temp;
    }
}

Manual::~Manual(){
    Update* tempUpdate;
    while(updates != nullptr){
        tempUpdate = updates->next;
        delete updates;
        updates = tempUpdate;
    }
    Rule* tempRule;
    while(rules != nullptr){
        tempRule = rules->next;
        delete rules;
        rules = tempRule;
    }
}

//Member Functions
void Manual::Update::addPage(int value){
    numPages++;

    Page* newPage = new Page(value);

    if(pages == nullptr){
        pages = newPage;
        return;
    }

    Page* temp = pages;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newPage;
    newPage->last = temp;
    
    return;
}

void Manual::addRule(std::string line){
    int inputs[2];

    // Read String
    int inputsRead = 0;
    int i = 0;
    while(line[i] != '\0'){
        if(!isdigit(line[i])){
            i++;
        }
        else{
            int temp = 0;
            while(isdigit(line[i])){
                temp = temp * 10;
                temp += line[i] - '0';
                i++;
            }
            inputs[inputsRead] = temp;
            inputsRead++;
        }
    }

    // add new rule to linked list
    Rule* newRule = new Rule(inputs);
    
    if(rules == nullptr){
        rules = newRule;
        return;
    }

    Rule* tempRule = rules;
    while(tempRule->next != nullptr) tempRule = tempRule->next;
    tempRule->next = newRule;

    return;
}

void Manual::Update::updateMiddleValue(){
    Update::Page* tempPage = pages;
    for(int i = numPages/2; i > 0; i--){
        tempPage = tempPage->next;
    }
    middleValue = tempPage->value;
}

void Manual::addUpdate(std::string line){
    Update* newUpdate = new Update();

    // populate update with pages
    int i = 0;
    while(line[i] != '\0'){
        if(!isdigit(line[i])){
            i++;
        }
        else{
            int temp = 0;
            while(isdigit(line[i])){
                temp = temp * 10;
                temp += line[i] - '0';
                i++;
            }
            newUpdate->addPage(temp);
        }
    }

    newUpdate->updateMiddleValue();

    // add new update to linked list
    if(updates == nullptr) updates = newUpdate;
    else{
        Update* tempUpdate = updates;
        while(tempUpdate->next != nullptr) tempUpdate = tempUpdate->next;
        tempUpdate->next = newUpdate;
    }

    return;
}

void Manual::readLine(std::string line){
    int i = 0;
    while(line[i] != '\0'){
        if(line[i] == '|'){
            addRule(line);
            return;
        }
        if(line[i] == ','){
            addUpdate(line);
            return;
        }
        i++;
    }
}

void Manual::checkRules(){
    Update* update = updates;
    while(update != nullptr){
        if(!update->valid) return;

        //go throgh all pages
        Update::Page* page = update->pages;
        while(page != nullptr){

            // go through all rules
            Rule* rule = rules;
            while(rule != nullptr){

                // if rule has same number in first position see if it passes
                bool listChanged = false;
                if(page->value == rule->rules[0]){
                    Update::Page* temp = page->last;
                    // loop through all pages before current page to look for broken rule
                    while(temp != nullptr){
                        if(temp->value == rule->rules[1]){
                            update->valid = false;
                            //remove temp from its position
                            if(temp->last != nullptr) temp->last->next = temp->next;
                            else updates->pages = temp->next;
                            temp->next->last = temp->last;

                            //place temp after current
                            temp->next = page->next;
                            temp->last = page;
                            if(page->next != nullptr) page->next->last = temp;
                            page->next = temp;

                            page = update->pages;
                            rule = rules;

                            listChanged = true;
                            break;
                        }
                        temp = temp->last;
                    }
                }
                // if rule has same number in second position see if it passes
                else if(page->value == rule->rules[1]){
                    Update::Page* temp = page->next;
                    // loop through all pages after current page to look for broken rule
                    while(temp != nullptr){
                        if(temp->value == rule->rules[0]){
                            update->valid = false;
                            //remove temp from its position
                            temp->last->next = temp->next;
                            if(temp->next != nullptr) temp->next->last = temp->last;

                            //place temp before current
                            temp->last = page->last;
                            temp->next = page;
                            if(page->last != nullptr) page->last->next = temp;
                            else update->pages = temp;
                            page->last= temp;

                            page = update->pages;
                            rule = rules;

                            listChanged = true;
                            break;
                        }
                        temp = temp->next;
                    }
                }

                if(!listChanged) rule = rule->next;
            }

            page = page->next;
        }

        if(!update->valid) update->updateMiddleValue();

        update = update->next;
    }
}

int Manual::addMiddleValues(bool valid){
    if(valid) checkRules();

    int sum = 0;

    Update* update = updates;
    while(update != nullptr){
        if(update->valid == valid) sum += update->middleValue;
        update = update->next;
    }

    return sum;
}
