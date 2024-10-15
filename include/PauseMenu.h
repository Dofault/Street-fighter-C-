#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "SFML/Graphics.hpp"
#include "Menu.h"
#include "MenuManager.h"

const int MAX_OPTIONS = 2;

class PauseMenu : public Menu{

private:
    sf::Text pauseMenu[MAX_OPTIONS];
    sf::Text titleText;
    int selectedOption;

public:

    PauseMenu(sf::RenderWindow * window);

    void moveUp();
    void moveDown();

    void draw() override;
    void updateValues() override;
    void handleEvent(sf::Event event) override;
    Menu * clone() override;

};

#endif // PAUSEMENU_H
