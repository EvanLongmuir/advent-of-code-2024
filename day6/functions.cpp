#include "functions.h"
#include <iostream>

// Enum
// postfix because returntype is Direction, prefix would have return type as Direction&
Direction operator++(Direction& dir, int) {
    if(dir == 3) dir = UP; // Loop back to first value
    else dir = static_cast<Direction>(dir + 1);  // Advance to next value
    return dir;
}
Direction operator--(Direction& dir, int) {
    if(dir == 0) dir = LEFT;
    else dir = static_cast<Direction>(dir - 1);
    return dir;
}

// Constructors
Grid::Node::Node(int x, int y, bool obstacle){
    next[UP] = nullptr;
    next[RIGHT] = nullptr;
    next[DOWN] = nullptr;
    next[LEFT] = nullptr;
    this->obstacle = obstacle;
    this->visted = false;
    this->x = x;
    this->y = y;
}

Grid::Guard::Path::Path(int x, int y, Direction facing){
    this->x = x;
    this->y = y;
    this->facing = facing;
    next = nullptr;
}

Grid::Guard::Guard(Node* pos){
    this->startingNode = pos;
    this->currentNode = pos;

    dir = UP;

    nodesVisted = 0;

    head = nullptr;
}

Grid::Grid() : guard(nullptr){
    head = nullptr;
    loopNodes = 0;
    xDim = 0;
    yDim = 0;
}

// Destructors
Grid::~Grid(){
    Node* temp;
    while(head != nullptr){
        temp = head->next[DOWN];
        if(temp != nullptr){ // if grid has only 1 vertical line
            while(temp->next[DOWN] != nullptr){
                temp = temp->next[DOWN];
                delete temp->next[UP];
            }
            delete temp;
        }
        temp = head;
        head = head->next[RIGHT];
        delete temp; 
    }
}

Grid::Guard::~Guard(){
    while(head != nullptr){
        Path* temp = head;
        head = head->next;
        delete temp;
    }
}

// Member functions
void Grid::addNode(bool obstacle, bool newLine){
    Node* newNode;

    if(head == nullptr){
        newNode = new Node(0, 0, obstacle);
        head = newNode; 
        return;
    }

    Node* temp = head;
    // move temp to the bottom of the grid
    while(temp->next[DOWN] != nullptr) temp = temp->next[DOWN];

    if(newLine){
        newNode = new Node(0, temp->y + 1, obstacle);
        temp->next[DOWN] = newNode;
        newNode->next[UP] = temp;
        return;
    }

    //move temp to the bottom right of the grid
    while(temp->next[RIGHT] != nullptr) temp = temp->next[RIGHT];

    newNode = new Node(temp->x + 1, temp->y, obstacle);
    xDim = newNode->x;
    yDim = newNode->y;

    temp->next[RIGHT] = newNode;
    newNode->next[LEFT] = temp;
    if(temp->next[UP] == nullptr || temp->next[UP]->next[RIGHT] == nullptr) return;
    temp->next[UP]->next[RIGHT]->next[DOWN] = newNode;
    newNode->next[UP] = temp->next[UP]->next[RIGHT];
    return;
}

bool Grid::Guard::addPath(){
    Path* newPath = new Path(currentNode->x, currentNode->y, dir);

    if(head == nullptr){
        head = newPath;
        nodesVisted++;
        return true;
    }

    bool visted = false;

    Path* temp = head;
    while(temp->next != nullptr){
        if(newPath->x == temp->x &&
                newPath->y == temp->y){
            visted = true;
            if(newPath->facing == temp->facing) return false;
        }
        temp = temp->next;
    }
    if(newPath->x == temp->x &&
            newPath->y == temp->y){
        visted = true;
        if( newPath->facing == dir) return false;
    }

    if(!visted) nodesVisted++;
    temp->next = newPath;
    return true;
}

bool Grid::Guard::move(){
    if(currentNode->next[dir] != nullptr &&
            currentNode->next[dir]->obstacle){
        // only turn if next node is obstical
        dir++;
        return true;
    }

    bool visted = addPath();

    currentNode = currentNode->next[dir];

    if(currentNode == nullptr) return false;
    return visted;
}

bool Grid::addObstacle(int x, int y){
    Node* temp = head;
    while(temp->x < x) temp = temp->next[RIGHT];
    while(temp->y < y) temp = temp->next[DOWN];
    if(temp->obstacle) return false;
    temp->obstacle = true;
    return true;
}

bool Grid::removeObstacle(int x, int y){
    Node* temp = head;
    while(temp->x < x) temp = temp->next[RIGHT];
    while(temp->y < y) temp = temp->next[DOWN];
    if(!temp->obstacle) return false;
    temp->obstacle = false;
    return true;
}

bool Grid::simulatePath(){
    Guard newGuard = Guard(guard.startingNode);
    guard = newGuard;
    while(guard.move());
    if(guard.currentNode == nullptr) return true;
    return false;
}

unsigned int Grid::getNodesVisted(){
    simulatePath();
    return guard.nodesVisted;
}

unsigned int Grid::getLoopNodes(){
    loopNodes = 0;
    for(int x = 0; x <= xDim; x++){
        for(int y = 0; y <= yDim; y++){
            if(guard.startingNode->x == x &&
                    guard.startingNode->y == y) continue;
            if(!addObstacle(x, y)) continue;
            if(!simulatePath()) loopNodes++;
            removeObstacle(x, y);
        }
    }
    return loopNodes;
}

void Grid::setGuardPos(){
    Node* temp = head;
    while(temp->next[DOWN] != nullptr) temp = temp->next[DOWN];
    while(temp->next[RIGHT] != nullptr) temp = temp->next[RIGHT];
    guard = Guard(temp);
}

void Grid::readLine(std::string line){
    bool firstNode = true;
    for(int i = 0; line[i] != '\0'; i++){
        if(line[i] == '#') addNode(true, firstNode);
        else addNode(false, firstNode);
        if(line[i] == '^') setGuardPos(); 
        firstNode = false;
    }
}
