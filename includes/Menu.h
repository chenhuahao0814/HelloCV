#ifndef MENU_H
#define MENU_H
#include "Crypto.h"
#include "FileHandler.h"
#include<string>
class Menu{
private:
    Crypto crypto;
    FileHandler fileHandler;
public:
    void showMenu();
    void run();
};
#endif
