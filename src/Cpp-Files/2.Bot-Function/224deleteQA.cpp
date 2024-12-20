#include "../../Header-Files/Chatbot.hpp"

void Chatbot::deleteQA(string question) {
    QA* temp = findQ_returnQA(question);
    if (temp) {
        deleteFromLink(temp);
        deleteFromFile(question);
        cout << "Delete Done" << endl;
    } else {
        cout << "The question doesn't exist, sorry" << endl;
        return;
    }
}