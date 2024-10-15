#ifndef AUDIOOPTIONMENU_H
#define AUDIOOPTIONMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include "MenuManager.h"

class AudioOptionMenu : public Menu {
public:
    AudioOptionMenu(sf::RenderWindow * window, sf::Sound * sound);

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();

    void handleEvent(sf::Event event) override;
    void draw() override;
    Menu * clone() override;
    void updateValues() override;

    void displayOptionsMenu(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window);
    void applyOptions(sf::Sound& sound);


private:
    int currentVolumeOption;
    sf::Font font;
    sf::Text titleText;
    sf::Text volumeText;
    int selectedOption;
    int maxOption;
    sf::Sound * sound; // Référence à l'objet sf::Sound pour ajuster le volume
};

#endif // AUDIOOPTIONMENU_H
