#include "../Header-Files/Chatbot.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    bool running = true;
    string question,previous_question;
    string answer;
    Chatbot bot;
    bot.loadFromFile();
    cout << "Hello, how can i help you?" << endl;
    while(running){
        getline(cin,question);
        if(question == "I want to add QA"){
            cout << "Sure, fill the QA you want to add :" << endl;
            bot.addQA();
            cout << "How can i help you any futher?" << endl;
        } else if (question == "I want to display QA") {
            bot.displayQA();
            cout << "How can i help you any futher?" << endl;
        } else if (question == "I want to improve QA") {
            if(previous_question.size()==0 || previous_question == "There's no previous question to improve yet, please ask first"){
                cout<< "There's no previous question to improve yet, please ask first" << endl;
            } else {
                bot.improveQA(previous_question);
                cout << "How can i help you any futher?" << endl;
            }
        } else if (question == "I want to delete QA") {
            if(previous_question.size()==0 || previous_question == "There's no previous question to delete yet, please ask first"){
                cout<< "There's no previous question to delete yet, please ask first" << endl;
            } else {
                bot.deleteQA(previous_question);
                cout << "How can i help you any futher?" << endl;
            }
        } else if (question == "Bye") {
            cout << "Thanks for chatting, byebye" << endl;
            running = false;
        } else {
            if(bot.findQ_returnQA(question)) {
                cout << bot.giveA(question) << endl;
            } else {
                cout << "Apology, I am not familiar with the question, what would you like me to answer so i can save it for later when asked again :" << endl;
                getline(cin,answer);
                bot.linkQA(question,answer);
                bot.writeToFile(question,answer);
                cout << "Thank you, how can i help you any futher?" << endl;
            }
        }
        previous_question = question;
    }
    
    return 0;
}

