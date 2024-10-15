#ifndef OPTIONKEYBINDING_H
#define OPTIONKEYBINDING_H

#include <SFML/Graphics.hpp>
#include <unordered_map>

class OptionKeybinding {
public:
    OptionKeybinding(sf::RenderWindow& window);

    void displayOptionsMenu(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    void handleInput(sf::RenderWindow& window);
    void applyOptions(sf::RenderWindow& window);
    void handleMovement(int direction);
    void changeKey(sf::RenderWindow& window);
    void loadDefaultKeybindings();  // Ajout de la déclaration
    sf::Keyboard::Key stringToKey(const std::string& str);  // Ajout de la déclaration
    std::string keyToString(sf::Keyboard::Key key);  // Ajout de la déclaration

private:
    sf::Font font;
    sf::Text titleText;
    sf::Text titleText1;
    sf::Text titleText2;
    sf::Text keybindingOption1Text;
    sf::Text keybindingOption2Text;
    sf::Text keybindingOption3Text;
    sf::Text keybindingOption4Text;
    sf::Text keybindingOption5Text;
    sf::Text keybindingOption6Text;
    //perso2
    sf::Text keybindingOption7Text;
    sf::Text keybindingOption8Text;
    sf::Text keybindingOption9Text;
    sf::Text keybindingOption10Text;
    sf::Text keybindingOption11Text;
    sf::Text keybindingOption12Text;


    int currentKeybindingIndex;
    int maxKeybindingIndex;
    int selectedOption;

    std::unordered_map<std::string, sf::Keyboard::Key> keybindings;  // Ajout de la déclaration
};

#endif // OPTIONKEYBINDING_H
