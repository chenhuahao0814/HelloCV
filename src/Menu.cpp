#include "../includes/Crypto.h"
#include "../includes/FileHandler.h"
#include "../includes/Menu.h"
#include <iostream>
using namespace std;
void Menu::showMenu(){
    cout << "\n=== 加密解密工具 ===" << endl;
    cout << "1. 文本加密" << endl;
    cout << "2. 文本解密" << endl;
    cout << "3. 文件加密并保存" << endl;
    cout << "4. 文件解密并保存" << endl;
    cout << "5. 退出" << endl;
    cout << "请选择: ";
}
void Menu::run(){
    showMenu();
    int a;
    cin>>a;
    cin.ignore();
    switch(a){
        case 1:{
            cout<<"请输入要加密的文本:";
            string text;
            getline(cin,text);
            cout<<"请输入密钥:";
            int key;
            cin>>key;
            string result=Crypto::encrypt(text,key);
            cout<<"加密结果:"<<result<<endl;
        break;
        }
        case 2:{
            cout<<"请输入要解密的文本:";;
            string text;
            getline(cin,text);
            cout<<"请输入密钥:";
            int key;
            cin>>key;
            string result=Crypto::decrypt(text,key);
            cout<<"解密结果:"<<result<<endl;
        break;
        }
        case 3:{
            cout<<"请输入要加密的文件路径:";
            string filename;
            getline(cin,filename);
            cout<<"请输入密钥:";
            int key;
            cin>>key;
            string content=FileHandler::readFile(filename);
            string encrypted=Crypto::encrypt(content,key);
            FileHandler::fileSave("encrypted.txt",encrypted);
        break;
        }
        case 4:{
            cout<<"请输入要解密的文件路径:";
            string filename;
            getline(cin,filename);
            cout<<"请输入密钥:";
            int key;
            cin>>key;
            string content=FileHandler::readFile(filename);
            string decrypted=Crypto::decrypt(content,key);
            FileHandler::fileSave("decrypted.txt",decrypted);
        break;
        }
        case 5:{
            cout<<"已退出"<<endl;
        break;
        }
        default:
            cout<<"无效选择，请重新输入"<<endl;
        break;      
    }
}
