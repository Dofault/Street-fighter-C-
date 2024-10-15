#ifndef OPTIONVIDEO_H
#define OPTIONVIDEO_H

#include <SFML/Graphics.hpp>

class OptionVideo {
public:
    OptionVideo(sf::RenderWindow& window);

    void displayOptionsMenu(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    void handleInput(sf::RenderWindow& window);
    void applyOptions(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text titleText;
    sf::Text resolutionText;
    sf::Text fullscreenText;
    sf::Text vsyncText; 

    int selectedOption;
    int maxOption;

    int currentResolutionIndex;
    int currentFullscreenOption;
    int currentScreenIndex;
    std::vector<sf::VideoMode> availableModes;
    int maxResolutionIndex;

    bool vsyncEnabled; 

    std::vector<sf::Vector2u> resolutions;
};

#endif // OPTIONVIDEO_H
