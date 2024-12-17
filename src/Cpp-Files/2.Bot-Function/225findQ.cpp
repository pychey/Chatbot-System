#include "../../Header-Files/Chatbot.hpp"

QA* Chatbot::findQ_returnQA(string question){
    
    if(firstQA == nullptr){
        cout << "No QA stored, please add QA first" << endl;
    }
    else {
        QA* temp = firstQA;
        while(temp) {
            if(temp->getQ() == question) { 
                return temp;
                }
            else {
                temp = temp->getNext();
            }
        }
    }
    return nullptr;
}