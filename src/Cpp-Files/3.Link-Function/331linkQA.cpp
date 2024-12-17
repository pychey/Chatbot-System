#include "../../Header-Files/Chatbot.hpp"

void Chatbot::linkQA(string question, string answer) {
    QA* newQA = new QA(question,answer);

    if(firstQA == nullptr){
        firstQA = newQA;
    } 
    else {
        QA* temp = firstQA;
        while(temp->getNext()){
            temp = temp->getNext();
        }
        temp->setNext(newQA);
    }
}