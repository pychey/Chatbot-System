#include "../../Header-Files/Chatbot.hpp"

string Chatbot::giveA(string question) {
    QA* temp = findQ_returnQA(question);
    return temp->getA();
}