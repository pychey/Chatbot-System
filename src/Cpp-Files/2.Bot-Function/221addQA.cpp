#include "../../Header-Files/Chatbot.hpp"

void Chatbot::addQA(){
    string question;
    string answer;

    cout << "Question: ";
    getline(cin, question);
    cout << "Answer: ";
    getline(cin, answer);

    linkQA(question,answer);
    writeToFile(question,answer);
}    

