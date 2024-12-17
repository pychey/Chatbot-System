#include "../../Header-Files/Chatbot.hpp" 

void Chatbot::improveInFile(string questionToImprove,string newAnswer) {
    string question;
    string answer;
    bool found = false;
    ifstream file(filePath);
    ofstream tempFile(fileTemp, ios::app);
    while(getline(file,question)){
        getline(file,answer);
        if(question == questionToImprove){
            tempFile << questionToImprove << endl;
            tempFile << newAnswer << endl;
        } else {
            tempFile << question << endl;
            tempFile << answer << endl;
        }
    }
    file.close();
    tempFile.close();
    remove("QA.txt");
    rename("temp.txt","QA.txt");
}