#include "../../Header-Files/Chatbot.hpp"

void Chatbot::deleteFromLink(QA* target_QA){
    if(target_QA==firstQA){
        firstQA = target_QA->getNext();
    } else {
        QA* temp = firstQA;
        while(temp->getNext() != target_QA){
            temp = temp->getNext();
        }
        temp->setNext(target_QA->getNext());
    }
}