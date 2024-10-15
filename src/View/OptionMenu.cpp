#include <SFML/Graphics.hpp>
#include "OptionMenu.h"
#include <SFML/Window.hpp>
#include <iostream>

OptionMenu::OptionMenu(RenderWindow * window): Menu(window) {

    // Play
    options[0].setFont(*RessourceManager::getFont("MainFont"));
    options[0].setFillColor(Color::Blue);
    options[0].setString("Video");
    options[0].setCharacterSize(70);
    options[0].setPosition(window->getSize().x / 2, 200);
    options[0].setOrigin(options[0].getLocalBounds().width / 2, options[0].getLocalBounds().height / 2);

    // OptionMenu
    options[1].setFont(*RessourceManager::getFont("MainFont"));
    options[1].setFillColor(Color::White);
    options[1].setString("Audio");
    options[1].setCharacterSize(70);
    options[1].setPosition(window->getSize().x / 2, 300);
    options[1].setOrigin(options[1].getLocalBounds().width / 2, options[1].getLocalBounds().height / 2);

    // About
    options[2].setFont(*RessourceManager::getFont("MainFont"));
    options[2].setFillColor(Color::White);
    options[2].setString("Commands");
    options[2].setCharacterSize(70);
    options[2].setPosition(window->getSize().x / 2, 400);
    options[2].setOrigin(options[2].getLocalBounds().width / 2, options[2].getLocalBounds().height / 2);

    // Exit
    options[3].setFont(*RessourceManager::getFont("MainFont"));
    options[3].setFillColor(Color::White);
    options[3].setString("Back");
    options[3].setCharacterSize(70);
    options[3].setPosition(window->getSize().x / 2, 500);
    options[3].setOrigin(options[3].getLocalBounds().width / 2, options[3].getLocalBounds().height / 2);

    selectedOption = 0;
}

void OptionMenu::draw() {

    if (window->getSize().x / 2 != options[0].getPosition().x / 2){
        options[0].setPosition(window->getSize().x / 2, 200);
        options[1].setPosition(window->getSize().x / 2, 300);
        options[2].setPosition(window->getSize().x / 2, 400);
        options[3].setPosition(window->getSize().x / 2, 500);
    }

    for (const auto & option : options){
        window->draw(option);
    }
}

void OptionMenu::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();
        } else if (event.key.code == sf::Keyboard::Down) {
            moveDown();
        } else if (event.key.code == sf::Keyboard::Enter) {
            switch (selectedOption) {
                case 0:
                    MenuManager::setSelectedMenu("VideoOptionMenu");
                    break;
                case 1:
                    MenuManager::setSelectedMenu("AudioOptionMenu");
                    break;
                case 2:
                    MenuManager::setSelectedMenu("KeybindingOptionMenu");
                    break;
                case 3:
                    MenuManager::setSelectedMenu("MainMenu");
                    break;
            }
        }
    }
}

Menu *OptionMenu::clone() {
    return new OptionMenu(window);
}

void OptionMenu::updateValues() {}

void OptionMenu::moveUp() {
    // we send the old selection in white
    options[selectedOption].setFillColor(Color::White);

    // selection decrement and check if not out of range
    selectedOption--;
    if(selectedOption < 0) {
        selectedOption = 3;
    }

    // set the new color selection
    options[selectedOption].setFillColor(Color::Blue);
}


void OptionMenu::moveDown() {
    // we send the old selection in white
    options[selectedOption].setFillColor(Color::White);

    selectedOption++;
    if(selectedOption > OPTIONS_NUMBER - 1) {
        selectedOption = 0;
    }

    // set the new color selection
    options[selectedOption].setFillColor(Color::Blue);
}

OptionMenu::~OptionMenu()
{

}

