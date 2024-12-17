#ifndef QA_H
#define QA_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class QA {
private:
    string question;
    string answer;
    QA* next; 
public:
    //1.constructor
    QA();
    QA(string question, string answer);

    //set data members
    void setQ(string question);
    void setA(string answer);
    void setNext(QA* next);

    //get data members
    string getQ();
    string getA();
    QA* getNext();
};

#endif