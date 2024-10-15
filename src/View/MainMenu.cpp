#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameArena.h"
#include <SFML/Window.hpp>
#include <iostream>
#include "CharacterSelectionMenu.h"
#include "chrono"
#include "thread"

MainMenu::MainMenu(RenderWindow *window) : Menu(window) {

    // Play
    mainMenu[0].setFont(*RessourceManager::getFont("MainFont"));
    mainMenu[0].setFillColor(Color::Blue);
    mainMenu[0].setString("Play");
    mainMenu[0].setCharacterSize(70);
    mainMenu[0].setPosition(window->getSize().x / 2, 200);
    mainMenu[0].setOrigin(mainMenu[0].getLocalBounds().width / 2, mainMenu[0].getLocalBounds().height / 2);

    // OptionMenu
    mainMenu[1].setFont(*RessourceManager::getFont("MainFont"));
    mainMenu[1].setFillColor(Color::White);
    mainMenu[1].setString("Options");
    mainMenu[1].setCharacterSize(70);
    mainMenu[1].setPosition(window->getSize().x / 2, 300);
    mainMenu[1].setOrigin(mainMenu[1].getLocalBounds().width / 2, mainMenu[1].getLocalBounds().height / 2);

    // About
    mainMenu[2].setFont(*RessourceManager::getFont("MainFont"));
    mainMenu[2].setFillColor(Color::White);
    mainMenu[2].setString("About");
    mainMenu[2].setCharacterSize(70);
    mainMenu[2].setPosition(window->getSize().x / 2, 400);
    mainMenu[2].setOrigin(mainMenu[2].getLocalBounds().width / 2, mainMenu[2].getLocalBounds().height / 2);

    // Exit
    mainMenu[3].setFont(*RessourceManager::getFont("MainFont"));
    mainMenu[3].setFillColor(Color::White);
    mainMenu[3].setString("Exit");
    mainMenu[3].setCharacterSize(70);
    mainMenu[3].setPosition(window->getSize().x / 2, 500);
    mainMenu[3].setOrigin(mainMenu[3].getLocalBounds().width / 2, mainMenu[3].getLocalBounds().height / 2);

    selectedMenu = 0;


    // Création de l'image de fond de la fenetre
    backgroundSprite.setTexture(*RessourceManager::getTexture("MainMenuBackground"));
    backgroundSprite.setScale(
            static_cast<float>(window->getSize().x) / backgroundSprite.getLocalBounds().width * 1,
            static_cast<float>(window->getSize().y) / backgroundSprite.getLocalBounds().height
    );


}

void MainMenu::moveUp() {
    // we send the old selection in white
    mainMenu[selectedMenu].setFillColor(Color::White);

    // selection decrement and check if not out of range
    selectedMenu--;
    if (selectedMenu < 0) {
        selectedMenu = 3;
    }

    // set the new color selection
    mainMenu[selectedMenu].setFillColor(Color::Blue);
}


void MainMenu::moveDown() {

    // we send the old selection in white
    mainMenu[selectedMenu].setFillColor(Color::White);

    selectedMenu++;
    if (selectedMenu > MENUS_NUMBER - 1) {
        selectedMenu = 0;
    }

    // set the new color selection
    mainMenu[selectedMenu].setFillColor(Color::Blue);
}

void MainMenu::draw() {

    window->draw(backgroundSprite);
    mainMenu[0].setPosition(window->getSize().x / 2, 200);
    mainMenu[1].setPosition(window->getSize().x / 2, 300);
    mainMenu[2].setPosition(window->getSize().x / 2, 400);
    mainMenu[3].setPosition(window->getSize().x / 2, 500);

    for (const auto &menu: mainMenu) {
        window->draw(menu);
    }
}

void MainMenu::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();
        } else if (event.key.code == sf::Keyboard::Down) {
            moveDown();
        } else if (event.key.code == sf::Keyboard::Enter) {
            if (selectedMenu == 0) {
                this_thread::sleep_for(std::chrono::milliseconds(100));
                CharacterSelectionMenu selectionMenu(window);
                MenuManager::replaceMenu("CharacterSelectionMenu", &selectionMenu);
                MenuManager::setSelectedMenu("CharacterSelectionMenu");
            } else if (selectedMenu == 1) {
                MenuManager::setSelectedMenu("OptionMenu");
            } else if (selectedMenu == 2) {
                MenuManager::setSelectedMenu("AboutMenu");
            } else if (selectedMenu == 3) {
                window->close();
            }
        }
    }
}

void MainMenu::updateValues() {}

Menu *MainMenu::clone() {
    return new MainMenu(window);
}

MainMenu::~MainMenu() {}
