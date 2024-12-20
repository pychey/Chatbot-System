#include "../../Header-Files/Chatbot.hpp"

void Chatbot::addQA(){
    string question;
    string answer;

    cout << "Question: ";
    getline(cin, question);
    cout << "Answer: ";
    getline(cin, answer);
    question = toLower(question);
    answer = toLower(answer);

    linkQA(question,answer);
    writeToFile(question,answer);
}    

