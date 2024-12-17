#include "../../Header-Files/Chatbot.hpp"

void Chatbot::improveInLink(string question,string newAnswer) {
    QA* temp = firstQA;
    while(temp->getQ() != question && temp != nullptr){
        temp = temp->getNext();
    }
    if (temp) {
        temp->setA(newAnswer);
    } else {
        cout << "Improve Answer in Link failed" << endl;
    }
}