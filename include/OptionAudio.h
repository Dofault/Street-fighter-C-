#ifndef OPTIONAUDIO_H
#define OPTIONAUDIO_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class OptionAudio {
public:
    OptionAudio(sf::RenderWindow& window, sf::Sound& sound);
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    void displayOptionsMenu(sf::RenderWindow& window);
    void handleInput(sf::RenderWindow& window);
    void applyOptions(sf::Sound& sound);


private:
    int currentVolumeOption;
    sf::Font font;
    sf::Text titleText;
    sf::Text VolumeText;
    int selectedOption;
    int maxOption;
    sf::Sound& sound; // Référence à l'objet sf::Sound pour ajuster le volume
};

#endif // OPTIONAUDIO_H
