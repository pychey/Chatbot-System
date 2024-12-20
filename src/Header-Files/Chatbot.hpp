#ifndef CHATBOT_H
#define CHATBOT_H

#include "QA.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string toLower(string str); //convert string to lowercase

class Chatbot{
private:
    string name;
    QA* firstQA;
    const string filePath = "QA.txt";
    const string fileTemp = "temp.txt";
public: 
    //1.constructor
    Chatbot();
    Chatbot(string name);

    //setter
    void setName(string name);
    void setFirst(QA* firstQA);

    //getter
    string getName();
    QA* getFirst();

    //2.function members
    void addQA();
    void displayQA();
    void displayQ();
    QA* findQ_returnQA(string question);
    string giveA(string question);
    void improveQA(string question);
    void deleteQA(string question);

    //3.linked-list
    void linkQA(string question, string answer);
    void improveInLink(string question,string newAnswer);
    void deleteFromLink(QA* target_QA);

    //4.file-handling
    void writeToFile(string question, string answer);
    void loadFromFile();
    void improveInFile(string question,string newAnswer);
    void deleteFromFile(string question);
};

#endif