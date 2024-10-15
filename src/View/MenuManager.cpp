#include "MenuManager.h"

map<string, Menu*> MenuManager::menuMap;
Menu * MenuManager::selectedMenu;

void MenuManager::addMenu(const string & key, Menu *menu) {
    menuMap[key] = menu->clone();
}

Menu *MenuManager::getMenu(const string & key) {
    return menuMap[key];
}

void MenuManager::setSelectedMenu(const string & key) {
    selectedMenu = menuMap[key];
}

Menu *MenuManager::getSelectedMenu() {
    return selectedMenu;
}

void MenuManager::replaceMenu(const string &key, Menu *menu) {
    if (menuMap[key] != nullptr){
        delete menuMap[key];
        menuMap[key] = menu->clone();
        return;
    }

    addMenu(key, menu);
}

