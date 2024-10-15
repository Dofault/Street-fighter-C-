#ifndef VIDEOOPTIONMENU_H
#define VIDEOOPTIONMENU_H

#include <SFML/Graphics.hpp>
#include "Menu.h"

class VideoOptionMenu : public Menu{
public:
    VideoOptionMenu(sf::RenderWindow * window);

    void moveUp();
    void moveDown();
    void moveRight();
    void moveLeft();
    void applyOptions();

    void draw() override;
    void handleEvent(sf::Event event) override;
    Menu * clone() override;
    void updateValues() override;

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

#endif // VIDEOOPTIONMENU_H
