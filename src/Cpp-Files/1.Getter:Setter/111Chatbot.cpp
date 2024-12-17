#include "../../Header-Files/Chatbot.hpp"

Chatbot::Chatbot() {
    firstQA = nullptr;
}
Chatbot::Chatbot(string name){
    this->name = name;
    firstQA = nullptr;
}

void Chatbot::setName(string name){
    this->name = name;
}

void Chatbot::setFirst(QA* firstQA){
    this->firstQA = firstQA;
}

string Chatbot::getName() {
    return name;
}

QA* Chatbot::getFirst() {
    return firstQA;
}