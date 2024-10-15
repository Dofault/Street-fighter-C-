#ifndef CHARACTERSELECTIONMENU_H
#define CHARACTERSELECTIONMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "CharacterType.h"
#include "Menu.h"

class CharacterSelectionMenu : public Menu
{
public:
    CharacterSelectionMenu(sf::RenderWindow * window);
    virtual ~CharacterSelectionMenu();
    CharacterSelectionMenu(CharacterSelectionMenu & menu);
    CharacterSelectionMenu & operator=(CharacterSelectionMenu & menu);

    void setupMenu();
    void right();
    void left();
    void updateCharacter();

    void draw() override;
    void updateValues() override;
    void handleEvent(sf::Event event) override;
    Menu * clone() override;

protected:

private:

    sf::Sprite sprite;
    std::string player1Character;

    std::string playerName;
    CharacterType currentType;
    Character character1;
    Character character2;

    int characterChoice=0;

    int numPlayerSelect=0;

    sf::Text instruction;
    sf::Text playerText;
    sf::Text nameText;

};

#endif // CHARACTERSELECTIONMENU_H
