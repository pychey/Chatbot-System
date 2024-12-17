#include "../../Header-Files/Chatbot.hpp"

void Chatbot::deleteFromFile(string questionForDeleted) {
    string question;
    string answer;
    ifstream file(filePath);
    ofstream tempFile(fileTemp, ios::app);
    if(file.is_open()){
        while(getline(file,question)){
            getline(file,answer);
            if(question==questionForDeleted) {
                 //skip the question to be deleted
            } else {
                tempFile << question << endl;
                tempFile << answer << endl;
            }
        }
        file.close();
        tempFile.close();

        //for some reason, it doesnt accept string filePath and fileTemp
        remove("QA.txt");
        rename("temp.txt","QA.txt");
    } else {
        cout << "File opened unsuccessfully" << endl;
        return;
    }
}