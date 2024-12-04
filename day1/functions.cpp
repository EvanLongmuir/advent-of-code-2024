#include "functions.h"

// Constructors
Day1::Day1(){
    list1 = List();
    list2 = List();
}

Day1::List::List(){
    head = nullptr;
}

Day1::List::Node::Node(unsigned int input){
    value = input;
    next = nullptr;
    simularityScore = 0;
    simularityScoreCalculated = false;
}

// Destructors
Day1::~Day1(){}

Day1::List::~List(){
    Node* temp;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}

Day1::List::Node::~Node(){
    next = nullptr;
}

//member functions
void Day1::List::addSortedNode(unsigned int value){
    Node* newNode = new Node(value);

    if(head == nullptr || value <= head->value){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    // stepthrough the list until value <= temp->next->value or reach end of list
    while(temp->next != nullptr && value > temp->next->value){
        temp = temp->next;
    }
    //insert the new node in between temp and temp->next
    newNode->next = temp->next;
    temp->next = newNode;

    return;
}

void Day1::addNodePair(unsigned int value1, unsigned int value2){
    list1.addSortedNode(value1);
    list2.addSortedNode(value2);

    return;
}

unsigned int Day1::getDiff(List::Node* node1, List::Node* node2){
    if(node1->value > node2->value){
        return node1->value - node2->value;
    }
    return node2->value - node1->value;
}

unsigned int Day1::getTotalDiff(){
    List::Node* node1 = list1.head;
    List::Node* node2 = list2.head;

    unsigned int diff = 0;
    while(node1 != nullptr){
        diff += getDiff(node1, node2);
        node1 = node1->next;
        node2 = node2->next;
    }
    return diff;
}
void Day1::calculateSimularityScore(){
    List::Node* node1 = list1.head; //left list

    while(node1 != nullptr){
        List::Node* node2 = list2.head; //right list

        // dont repeat work
        if(!node1->simularityScoreCalculated){
            while(node2 != nullptr){
                if(node1->value == node2->value){
                    node1->simularityScore++;
                }
                node2 = node2->next;
            }
            node1->simularityScoreCalculated = true;
        }
        
        if(node1->next !=nullptr && node1->value == node1->next->value){
            node1->next->simularityScore = node1->simularityScore;
            node1->next->simularityScoreCalculated = true;
        }
        node1 = node1->next;
    }
}

unsigned int Day1::getTotalSimularityScore(){
    List::Node* node1 = list1.head; //left list

    if(!node1->simularityScoreCalculated){
        calculateSimularityScore();
    }

    unsigned int score = 0;
    while(node1 != nullptr){
        score += node1->value * node1->simularityScore;
        node1 = node1->next;
    }
    return score;
}
