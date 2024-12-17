#include "../../Header-Files/Chatbot.hpp"

void Chatbot::improveQA(string questionToImprove) {
    string newAnswer;
    QA* temp = findQ_returnQA(questionToImprove);
    if (temp) {
        cout << "New Answer: ";
        getline(cin,newAnswer);
        improveInLink(questionToImprove,newAnswer);
        improveInFile(questionToImprove,newAnswer);
        cout << "Improve Done" << endl;
    } else {
        cout << "Improve failed" << endl;
        return;
    }
}