//
// Created by Zoldi Tamas Botond on 2022-10-05.
//

#include "List.h"
#include <iostream>
#include <stdexcept>
List::List() {
    this->first= nullptr;
}

List::~List() {
    Node *temp = this->first;
    while (temp) {
        temp=temp->next;
        delete this->first;
        this->first = temp;
    }
}

void List::insertFirst(int d){
    Node *newNode = new Node(d, this->first);
    this->first=newNode;
    nodeCounter++;
}

void List::print() const {
    Node *temp= this->first;
    while (temp){
        std::cout<<temp->value<<' ';
        temp=temp->next;
    }
    std::cout<<std::endl;
}

bool List::exists(int d) const {
    Node *temp= this->first;
    while (temp){
        if (temp->value==d){
            return true;
        }
        temp= temp->next;
    }
    return false;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    return (0 == this->nodeCounter);
}

int List::removeFirst() {
    if(empty()){
        throw new std::invalid_argument("Empty list");
    }
    else{
        if(size()==1) {
            int tempValue = this->first->value;
            this->~List();
            nodeCounter--;
            return tempValue;
        }
        Node *tempNode= this->first->next;
        int tempValue= this->first->value;
        delete this->first;
        this->first=tempNode;
        nodeCounter--;
        return tempValue;
    }
}