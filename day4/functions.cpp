#include "functions.h"
//Constructors
Crossword::Letter::Letter(char letter){
    value = letter;
    left = nullptr;
    diagL = nullptr;
    up = nullptr;
    diagR = nullptr;
    right = nullptr;
}

Crossword::Crossword(){
    words = 0;
    head = nullptr;
}

//Destructors
Crossword::Letter::~Letter(){}

Crossword::~Crossword(){
  Letter* temp1;
  Letter* temp2;
  while(head != nullptr){
      temp1 = head->up;
      while(temp1 != nullptr){
          temp2 = temp1->up;
          delete temp1;
          temp1 = temp2;
      }

      temp1 = head->left;
      delete head;
      head = temp1;
  }
}

//Member Functions
bool Crossword::Letter::findWordsLeft(){
    if(value == 'X'){
        if(left == nullptr || left->value != 'M') return false;
        if(left->left == nullptr || left->left->value != 'A') return false;
        if(left->left->left == nullptr || left->left->left->value != 'S') return false;
        return true;
    }
    if(value == 'S'){
        if(left == nullptr || left->value != 'A') return false;
        if(left->left == nullptr || left->left->value != 'M') return false;
        if(left->left->left == nullptr || left->left->left->value != 'X') return false;
        return true;
    }
    return false;
}

bool Crossword::Letter::findWordsDiagL(){
    if(value == 'X'){
        if(diagL == nullptr || diagL->value != 'M') return false;
        if(diagL->diagL == nullptr || diagL->diagL->value != 'A') return false;
        if(diagL->diagL->diagL == nullptr || diagL->diagL->diagL->value != 'S') return false;
        return true;
    }
    if(value == 'S'){
        if(diagL == nullptr || diagL->value != 'A') return false;
        if(diagL->diagL == nullptr || diagL->diagL->value != 'M') return false;
        if(diagL->diagL->diagL == nullptr || diagL->diagL->diagL->value != 'X') return false;
        return true;
    }
    return false;
}

bool Crossword::Letter::findWordsUp(){
    if(value == 'X'){
        if(up == nullptr || up->value != 'M') return false;
        if(up->up == nullptr || up->up->value != 'A') return false;
        if(up->up->up == nullptr || up->up->up->value != 'S') return false;
        return true;
    }
    if(value == 'S'){
        if(up == nullptr || up->value != 'A') return false;
        if(up->up == nullptr || up->up->value != 'M') return false;
        if(up->up->up == nullptr || up->up->up->value != 'X') return false;
        return true;
    }
    return false;
}

bool Crossword::Letter::findWordsDiagR(){
    if(value == 'X'){
        if(diagR == nullptr || diagR->value != 'M') return false;
        if(diagR->diagR == nullptr || diagR->diagR->value != 'A') return false;
        if(diagR->diagR->diagR == nullptr || diagR->diagR->diagR->value != 'S') return false;
        return true;
    }
    if(value == 'S'){
        if(diagR == nullptr || diagR->value != 'A') return false;
        if(diagR->diagR == nullptr || diagR->diagR->value != 'M') return false;
        if(diagR->diagR->diagR == nullptr || diagR->diagR->diagR->value != 'X') return false;
        return true;
    }
    return false;
}

unsigned int Crossword::Letter::findWords(){
    unsigned int words = 0;
    if(findWordsLeft()) words++;
    if(findWordsDiagL()) words++;
    if(findWordsUp()) words++;
    if(findWordsDiagR()) words++;

    return words;
}

unsigned int Crossword::addLetter(char letter){
    Crossword::Letter* newLetter = new Crossword::Letter(letter);

    if(head == nullptr){
        head = newLetter;
        return 0;
    }

    Crossword::Letter* temp = head;
    while(temp->right != nullptr){
        temp = temp->right;
    }
    temp->right = newLetter;
    
    newLetter->left = temp;
    newLetter->diagL = temp->up;
    newLetter->up = temp->diagR;
    if(temp->diagR != nullptr) newLetter->diagR = temp->diagR->right;

    return newLetter->findWords();
}

void Crossword::addLine(std::string line){
    Crossword::Letter* newLetter = new Crossword::Letter(line[0]);

    if(head == nullptr) head = newLetter;
    else{
        newLetter->up = head;
        newLetter->diagR = head->right;
        head = newLetter;
        words += head->findWords();
    }

    for(int i = 1; line[i] != '\0'; i++){
        words += addLetter(line[i]);
    }
}

unsigned int Crossword::getWords() {
    return words;
}
