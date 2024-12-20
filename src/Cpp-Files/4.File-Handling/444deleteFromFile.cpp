#include "../../Header-Files/Chatbot.hpp"

void Chatbot::deleteFromFile(string questionForDeleted) {
    string question;
    string answer;
    ifstream file(filePath);
    ofstream tempFile(fileTemp, ios::app);
    if(file.is_open()){
        while(getline(file,question)){
            if(question.size()==0){
                continue;
            }
            getline(file,answer);
            if(answer.size()==0){
                continue;
            }
            if(question==questionForDeleted) {
                 continue;
            } else {
                tempFile << endl << question;
                tempFile << endl << answer;
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