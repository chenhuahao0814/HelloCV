#include "../includes/FileHandler.h"
#include <iostream>
#include<fstream>
using namespace std;
string FileHandler::readFile(const string& filename){
    ifstream file(filename);
    if(!file){
        cout<<"File open failed"<<endl;
        return "";
    }
    string line,content;
    while(getline(file,line)){
        content+=line+"\n";
    }
    file.close();
    return content;
}
void FileHandler::fileSave(const string& filename,string& content){
    ofstream file(filename);
    file<<content;
    file.close();
}
