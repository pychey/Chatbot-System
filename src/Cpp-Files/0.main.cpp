#include "../Header-Files/Chatbot.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

string toLower(string str){
    transform(str.begin(), str.end(), str.begin(),::tolower);
    return str;
}

int main() {
    bool running = true;
    string question,previous_question;
    string answer;
    Chatbot bot;
    bot.loadFromFile();
    cout << "Hello, how can i help you?" << endl;
    while(running){
        getline(cin,question);
        question = toLower(question);
        if(question == "i want to add a question" || question == "add"){
            cout << "Sure, fill the QA you want to add :" << endl;
            bot.addQA();
            cout << "How can i help you any futher?" << endl;
        } else if (question == "i want to display the questions" || question == "display") {
            bot.displayQ();
            cout << "How can i help you any futher?" << endl;
        } else if (question == "i want to display the questions and answers") {
            bot.displayQA();
            cout << "How can i help you any futher?" << endl;
        } else if (question == "i want to improve the previous question") {
            if(previous_question.size()==0){
                cout<< "There's no previous question to improve yet, please ask first" << endl;
            } else if (previous_question == "i want to improve the previous question") {
                cout << "The previous question were the request you asked to improve, please ask a first" << endl;
            } else {
                bot.improveQA(previous_question);
                cout << "How can i help you any futher?" << endl;
            }
        } else if (question == "i want to improve a question" || question == "improve"){
            cout << "Type the question you would like to improve:" << endl;
            getline(cin,answer);
            answer = toLower(answer);
            bot.improveQA(answer);
        } else if (question == "i want to delete the previous question") {
            if(previous_question.size()==0){
                cout<< "There's no previous question to delete yet, please ask first" << endl;
            } else if (previous_question == "i want to delete the previous question") {
                cout << "The previous question were the request you asked to delete, please ask a first" << endl;
            } else {
                bot.deleteQA(previous_question);
                cout << "How can i help you any futher?" << endl;
            }
        } else if (question == "i want to delete a question" || question == "delete"){
            cout << "Type the question you would like to delete:" << endl;
            getline(cin,answer);
            answer = toLower(answer);
            bot.deleteQA(answer);
        } else if (question == "i want to clear the screen" || question == "clear"){
            system("clear");
            cout << "Done clearing, how can i help you any futher?" << endl;
        } else if (question == "i want to play a game"){
            cout << "lets play a guessing number, pick a number from 1 to 5" << endl;
            getline(cin, answer);
            cout << "nice try, its not the answer tho" << endl; 
        } else if (question == "bye") {
            cout << "Thanks for chatting, byebye" << endl;
            running = false;
        } else {
            if(bot.findQ_returnQA(question)) {
                cout << bot.giveA(question) << endl;
            } else {
                cout << "Apology, I am not familiar with the question, what would you like me to answer so i can save it for later when asked again :" << endl;
                getline(cin,answer);
                answer = toLower(answer);
                bot.linkQA(question,answer);
                bot.writeToFile(question,answer);
                cout << "Thank you, how can i help you any futher?" << endl;
            }
        }
        previous_question = question;
    }
    
    return 0;
}

