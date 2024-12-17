#include "../../Header-Files/QA.hpp"

QA::QA() {};

QA::QA(string question, string answer){
    this->question = question;
    this->answer = answer;
    next = nullptr;
}

void QA::setQ(string question){
    this->question = question;
}

void QA::setA(string answer){
    this->answer = answer;
}

void QA::setNext(QA* next) {
    this->next = next;
}

string QA::getQ(){
    return question;
}

string QA::getA(){
    return answer;
}

QA* QA::getNext(){
    return next;
}