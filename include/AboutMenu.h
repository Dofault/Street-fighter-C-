#ifndef ABOUTMENU_H
#define ABOUTMENU_H

#include "Menu.h"
#include "MenuManager.h"

class AboutMenu : public Menu{
private:
    sf::Text titleText;
    sf::Text aboutText;
    sf::Text devText;
    sf::String aboutString;
    sf::Sprite backgroundSprite;

public:

    AboutMenu(sf::RenderWindow * window);

    void draw() override;
    void updateValues() override;
    void handleEvent(sf::Event event) override;
    Menu * clone() override;

};
#endif // ABOUTMENU_H
