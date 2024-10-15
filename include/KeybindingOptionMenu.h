#ifndef KEYBINDINGOPTIONMENU_H
#define KEYBINDINGOPTIONMENU_H


#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Menu.h"
#include "RessourceManager.h"
#include "MenuManager.h"

class KeybindingOptionMenu : public Menu{
public:

    KeybindingOptionMenu(sf::RenderWindow * window);
    void MoveUp();
    void MoveDown();
    void applyOptions();
    void handleMovement(int direction);
    void changeKey();
    void loadDefaultKeybindings();  // Ajout de la déclaration
    sf::Keyboard::Key stringToKey(const std::string& str);  // Ajout de la déclaration
    std::string keyToString(sf::Keyboard::Key key);  // Ajout de la déclaration

    void draw() override;
    void updateValues() override;
    void handleEvent(sf::Event event) override;
    Menu * clone() override;

private:
    sf::Font font;
    sf::Text titleText;
    sf::Text titleText1;
    sf::Text titleText2;
    sf::Text keybindingOption1Text;
    sf::Text keybindingOption2Text;
    sf::Text keybindingOption3Text;
    sf::Text keybindingOption4Text;
    //perso2
    sf::Text keybindingOption5Text;
    sf::Text keybindingOption6Text;
    sf::Text keybindingOption7Text;
    sf::Text keybindingOption8Text;


    int currentKeybindingIndex;
    int maxKeybindingIndex;
    int selectedOption;

    std::unordered_map<std::string, sf::Keyboard::Key> keybindings;  // Ajout de la déclaration
};

#endif // KEYBINDINGOPTIONMENU_H
