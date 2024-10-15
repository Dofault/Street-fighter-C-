#ifndef MENUMANAGER_H
#define MENUMANAGER_H

#include "iostream"
#include "Menu.h"

using namespace std;

class MenuManager{

private:
    static map<string, Menu*> menuMap;
    static Menu * selectedMenu;

public:
    static void addMenu(const string & key, Menu * menu);
    static void replaceMenu(const string & key, Menu * menu);
    static Menu * getMenu(const string & key);
    static void setSelectedMenu(const string & key);
    static Menu * getSelectedMenu();
};

#endif // MENUMANAGER_H
