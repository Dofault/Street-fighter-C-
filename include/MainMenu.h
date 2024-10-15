#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Menu.h"
#include "MenuManager.h"

using namespace std;
using namespace sf;

class MainMenu : public Menu {
public:
    MainMenu(RenderWindow * window);
    ~MainMenu() override;

    void draw() override;
    void handleEvent(sf::Event event) override;
    void updateValues() override;
    Menu * clone() override;

    void moveUp();
    void moveDown();

private:
    static const int MENUS_NUMBER = 4;
    int selectedMenu;
    Text mainMenu[MENUS_NUMBER];
    sf::Sprite backgroundSprite;

};

#endif // MAINMENU_H
