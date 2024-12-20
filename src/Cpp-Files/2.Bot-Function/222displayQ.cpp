#include "../../Header-Files/Chatbot.hpp"

void Chatbot::displayQ() {
    if(firstQA == nullptr){
        cout << "No QA stored, please add QA first" << endl;
        return;
    }
    else {
        int QA_num = 1;
        QA* temp = firstQA;
        while(temp) {
            cout << to_string(QA_num) << ". " << temp->getQ() << endl;
            temp = temp->getNext();
            ++QA_num;
        }
    }
}