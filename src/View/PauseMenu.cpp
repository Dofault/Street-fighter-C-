#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RenderWindow *window) : Menu(window) {

    // Resume
    pauseMenu[0].setFont(*RessourceManager::getFont("MainFont"));
    pauseMenu[0].setFillColor(sf::Color::White);
    pauseMenu[0].setString("Resume");
    pauseMenu[0].setCharacterSize(70);
    pauseMenu[0].setPosition(window->getSize().x / 2, 200);
    pauseMenu[0].setOrigin(pauseMenu[0].getLocalBounds().width / 2, pauseMenu[0].getLocalBounds().height / 2);

    // Exit
    pauseMenu[1].setFont(*RessourceManager::getFont("MainFont"));
    pauseMenu[1].setFillColor(sf::Color::White);
    pauseMenu[1].setString("Exit");
    pauseMenu[1].setCharacterSize(70);
    pauseMenu[1].setPosition(window->getSize().x / 2, 300);
    pauseMenu[1].setOrigin(pauseMenu[1].getLocalBounds().width / 2, pauseMenu[1].getLocalBounds().height / 2);

    selectedOption = 0;
}

void PauseMenu::moveUp() {
    // we send the old selection in white
    pauseMenu[selectedOption].setFillColor(sf::Color::White);

    // selection decrement and check if not out of range
    selectedOption--;
    if (selectedOption < 0) {
        selectedOption = 2;
    }

    // set the new color selection
    pauseMenu[selectedOption].setFillColor(sf::Color::Blue);
}

void PauseMenu::moveDown() {
    // we send the old selection in white
    pauseMenu[selectedOption].setFillColor(sf::Color::White);

    selectedOption++;
    if (selectedOption > MAX_OPTIONS - 1) {
        selectedOption = 0;
    }

    // set the new color selection
    pauseMenu[selectedOption].setFillColor(sf::Color::Blue);
}

void PauseMenu::draw() {
    MenuManager::getMenu("GameArena")->draw();

    titleText.setPosition(window->getSize().x / 2, 50);
    pauseMenu[0].setPosition(window->getSize().x / 2, 200);
    pauseMenu[1].setPosition(window->getSize().x / 2, 300);


    window->draw(titleText);
    for (const auto &item: pauseMenu) {
        window->draw(item);
    }
}

void PauseMenu::updateValues() {

}

void PauseMenu::handleEvent(sf::Event event) {

    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();
        } else if (event.key.code == sf::Keyboard::Down) {
            moveDown();
        } else if (event.key.code == sf::Keyboard::Enter) {
            switch (selectedOption) {
                case 0:
                    MenuManager::setSelectedMenu("GameArena");
                    break;
                case 1:
                    MenuManager::setSelectedMenu("MainMenu");
                    break;
            }
        }
    }

}

Menu *PauseMenu::clone() {
    return new PauseMenu(window);
}
