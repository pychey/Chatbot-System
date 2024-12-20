#include "../../Header-Files/Chatbot.hpp"

void Chatbot::writeToFile(string question, string answer){
    ofstream file(filePath, ios::app);
    if (file.is_open()){
        file << endl << question << endl;
        file << answer;
        file.close();
        cout << "QA added successfully" << endl;
    } else {
        cout << "File opened unsucessfully" << endl;
        return;
    }
}