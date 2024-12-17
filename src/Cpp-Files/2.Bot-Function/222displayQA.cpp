#include "../../Header-Files/Chatbot.hpp"

void Chatbot::displayQA() {
    if(firstQA == nullptr){
        cout << "No QA stored, please add QA first" << endl;
        return;
    }
    else {
        int QA_num = 1;
        QA* temp = firstQA;
        while(temp) {
            cout << to_string(QA_num) << ". " << temp->getQ() << endl;
            cout << "A: " << temp->getA() << endl;
            temp = temp->getNext();
            ++QA_num;
        }
    }
}