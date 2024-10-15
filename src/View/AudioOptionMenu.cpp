#include "AudioOptionMenu.h"

AudioOptionMenu::AudioOptionMenu(sf::RenderWindow *window, sf::Sound *sound)
        : Menu(window), sound(sound)
{
    // Initialisation des membres et des options
    currentVolumeOption = 50;

    titleText.setFont(*RessourceManager::getFont("MainFont"));
    titleText.setCharacterSize(60);
    titleText.setString("Audio Options");
    titleText.setPosition(window->getSize().x / 2, 50);
    titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);

    volumeText.setFont(*RessourceManager::getFont("MainFont"));
    volumeText.setCharacterSize(30);
    volumeText.setString("Main Volume: " + std::to_string(currentVolumeOption));
    volumeText.setPosition(window->getSize().x / 2, 200);
    volumeText.setOrigin(volumeText.getLocalBounds().width / 2, volumeText.getLocalBounds().height / 2);

    selectedOption = 0;
    maxOption = 1;

}

void AudioOptionMenu::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            moveUp();
        } else if (event.key.code == sf::Keyboard::Down) {
            moveDown();
        } else if (event.key.code == sf::Keyboard::Right) {
            moveRight();
        } else if (event.key.code == sf::Keyboard::Left) {
            moveLeft();
        } else if (event.key.code == sf::Keyboard::Escape){
            MenuManager::setSelectedMenu("OptionMenu");
        }
    }
}

void AudioOptionMenu::draw() {

    window->draw(titleText);
    window->draw(volumeText);
}

Menu *AudioOptionMenu::clone() {
    return new AudioOptionMenu(window, sound);
}

void AudioOptionMenu::updateValues() {
    // ON MET A JOUR LES POSITIONS EN FONCTION DE LA TAILLE DE LA FENETRE
    titleText.setPosition(window->getSize().x / 2, 50);
    volumeText.setPosition(window->getSize().x / 2, 200);
}

void AudioOptionMenu::moveUp() {

    if (selectedOption == 0) {
        volumeText.setFillColor(sf::Color::White);
    }

    // Décrémentation de la sélection et vérification pour ne pas dépasser la plage
    selectedOption--;
    if (selectedOption < 0) {
        selectedOption = maxOption;
    }


    if (selectedOption == 0) {
        volumeText.setFillColor(sf::Color::Blue);
    }
}

void AudioOptionMenu::moveDown() {

    if (selectedOption == 0) {
        volumeText.setFillColor(sf::Color::White);
    }

    // Incrémentation de la sélection et vérification pour ne pas dépasser la plage
    selectedOption++;
    if (selectedOption > maxOption) {
        selectedOption = 0;
    }


    if (selectedOption == 0) {
        volumeText.setFillColor(sf::Color::Blue);
    }
}

void AudioOptionMenu::moveRight() {
    if (selectedOption == 0) {

        currentVolumeOption += 10;
        if (currentVolumeOption > 100) {
            currentVolumeOption = 100;
        }
        volumeText.setString("Main Volume: " + std::to_string(currentVolumeOption));
        sound->setVolume(currentVolumeOption);
    }
}

void AudioOptionMenu::moveLeft() {
    if (selectedOption == 0) {

        currentVolumeOption -= 10;
        if (currentVolumeOption < 0) {
            currentVolumeOption = 0;
        }
        volumeText.setString("Main Volume: " + std::to_string(currentVolumeOption));
        sound->setVolume(currentVolumeOption);
    }
}
