#include "VideoOptionMenu.h"
#include "RessourceManager.h"
#include "MenuManager.h"

VideoOptionMenu::VideoOptionMenu(sf::RenderWindow * window) : Menu(window){
    // Initialisation des membres et des options
    currentResolutionIndex = 1;
    currentFullscreenOption = 0;
    availableModes = sf::VideoMode::getFullscreenModes();
    maxResolutionIndex = availableModes.size() - 1;
    vsyncEnabled = true;

    titleText.setFont(*RessourceManager::getFont("MainFont"));
    titleText.setCharacterSize(75);
    titleText.setString("Video Options");
    titleText.setPosition(window->getSize().x / 2, 50);
    titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);

    resolutionText.setFont(*RessourceManager::getFont("MainFont"));
    resolutionText.setCharacterSize(35);
    resolutionText.setFillColor(sf::Color::Blue);
    resolutionText.setString("Resolution: " + std::to_string(availableModes[currentResolutionIndex].width) + "x" + std::to_string(availableModes[currentResolutionIndex].height));
    resolutionText.setPosition(window->getSize().x / 2, 200);
    resolutionText.setOrigin(resolutionText.getLocalBounds().width / 2, resolutionText.getLocalBounds().height / 2);

    fullscreenText.setFont(*RessourceManager::getFont("MainFont"));
    fullscreenText.setCharacterSize(35);
    fullscreenText.setString("Fullscreen: " + std::string(currentFullscreenOption == 0 ? "Windowed" : "Fullscreen"));
    fullscreenText.setPosition(window->getSize().x / 2, 300);
    fullscreenText.setOrigin(fullscreenText.getLocalBounds().width / 2, fullscreenText.getLocalBounds().height / 2);

    vsyncText.setFont(*RessourceManager::getFont("MainFont"));
    vsyncText.setCharacterSize(35);
    vsyncText.setString("VSync: " + std::string(vsyncEnabled ? "On" : "Off"));
    vsyncText.setPosition(window->getSize().x / 2, 400);
    vsyncText.setOrigin(vsyncText.getLocalBounds().width / 2, vsyncText.getLocalBounds().height / 2);

    selectedOption = 0;
    maxOption = 3;

    // Obtenez les modes vidéo disponibles
}

void VideoOptionMenu::moveUp() {
    // Mettez en blanc la sélection actuelle
    if (selectedOption == 0) {
        resolutionText.setFillColor(sf::Color::White);
    } else if (selectedOption == 1) {
        fullscreenText.setFillColor(sf::Color::White);
    } else if (selectedOption == 2) {
        vsyncText.setFillColor(sf::Color::White);
    }

    // Décrémentation de la sélection et vérification pour ne pas dépasser la plage
    selectedOption--;
    if (selectedOption < 0) {
        selectedOption = 2;
    }

    // Définissez la nouvelle sélection en bleu
    if (selectedOption == 0) {
        resolutionText.setFillColor(sf::Color::Blue);
    } else if (selectedOption == 1) {
        fullscreenText.setFillColor(sf::Color::Blue);
    } else if (selectedOption == 2) {
        vsyncText.setFillColor(sf::Color::Blue);
    }
}

void VideoOptionMenu::moveDown() {
    // Mettez en blanc la sélection actuelle
    if (selectedOption == 0) {
        resolutionText.setFillColor(sf::Color::White);
    } else if (selectedOption == 1) {
        fullscreenText.setFillColor(sf::Color::White);
    } else if (selectedOption == 2) {
        vsyncText.setFillColor(sf::Color::White);
    }

    // Incrémentation de la sélection et vérification pour ne pas dépasser la plage
    selectedOption++;
    if (selectedOption > 2) {
        selectedOption = 0;
    }

    // Définissez la nouvelle sélection en bleu
    if (selectedOption == 0) {
        resolutionText.setFillColor(sf::Color::Blue);
    } else if (selectedOption == 1) {
        fullscreenText.setFillColor(sf::Color::Blue);
    } else if (selectedOption == 2) {
        vsyncText.setFillColor(sf::Color::Blue);
    }
}

void VideoOptionMenu::moveRight() {
    if (selectedOption == 0) {
        // Augmentez la résolution ici
        currentResolutionIndex = (currentResolutionIndex - 1 + maxResolutionIndex + 1) % (maxResolutionIndex + 1);
        resolutionText.setString("Resolution: " + std::to_string(availableModes[currentResolutionIndex].width) + "x" + std::to_string(availableModes[currentResolutionIndex].height));
    } else if (selectedOption == 1) {
        // Changez le mode plein écran ici
        currentFullscreenOption = (currentFullscreenOption == 0) ? 1 : 0;
        fullscreenText.setString("Fullscreen: " + std::string(currentFullscreenOption == 0 ? "Windowed" : "Fullscreen"));
    } else if (selectedOption == 2) {
        // Changez l'état de la synchronisation verticale ici
        vsyncEnabled = !vsyncEnabled;
        vsyncText.setString("VSync: " + std::string(vsyncEnabled ? "On" : "Off"));
    }
}

void VideoOptionMenu::moveLeft() {
    if (selectedOption == 0) {
        // Diminuez la résolution ici
        currentResolutionIndex = (currentResolutionIndex + 1) % (maxResolutionIndex + 1);
        resolutionText.setString("Resolution: " + std::to_string(availableModes[currentResolutionIndex].width) + "x" + std::to_string(availableModes[currentResolutionIndex].height));
    } else if (selectedOption == 1) {
        // Changez le mode plein écran ici
        currentFullscreenOption = (currentFullscreenOption == 0) ? 1 : 0;
        fullscreenText.setString("Fullscreen: " + std::string(currentFullscreenOption == 0 ? "Windowed" : "Fullscreen"));
    } else if (selectedOption == 2) {
        // Changez l'état de la synchronisation verticale ici
        vsyncEnabled = !vsyncEnabled;
        vsyncText.setString("VSync: " + std::string(vsyncEnabled ? "On" : "Off"));
    }
}

void VideoOptionMenu::applyOptions() {

    // Obtenir la résolution sélectionnée
    sf::VideoMode selectedResolution = availableModes[currentResolutionIndex];

    // Créer un objet sf::ContextSettings avec les paramètres par défaut
    sf::ContextSettings settings;


    if (vsyncEnabled) {
        window->setVerticalSyncEnabled(true);
    } else {
        window->setVerticalSyncEnabled(false);
    }

    window->create(selectedResolution, "Helha Fighter", (currentFullscreenOption == 1 ? sf::Style::Fullscreen : sf::Style::Default), settings);
}

void VideoOptionMenu::draw() {

    if (window->getSize().x / 2 != resolutionText.getPosition().x / 2){
        titleText.setPosition(window->getSize().x / 2, 50);
        resolutionText.setPosition(window->getSize().x / 2, 200);
        fullscreenText.setPosition(window->getSize().x / 2, 300);
        vsyncText.setPosition(window->getSize().x / 2, 400);
    }

    // Affichage du menu des options vidéo
    window->draw(titleText);

    // Afficher la résolution actuelle
    resolutionText.setString("Resolution: " + std::to_string(availableModes[currentResolutionIndex].width) + "x" + std::to_string(availableModes[currentResolutionIndex].height));
    window->draw(resolutionText);

    fullscreenText.setString("Fullscreen: " + std::string(currentFullscreenOption == 0 ? "Windowed" : "Fullscreen"));
    window->draw(fullscreenText);

    vsyncText.setString("VSync: " + std::string(vsyncEnabled ? "On" : "Off"));
    window->draw(vsyncText);
}

void VideoOptionMenu::handleEvent(sf::Event event) {
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
            applyOptions();
            MenuManager::setSelectedMenu("OptionMenu");
        }
    }
}

Menu *VideoOptionMenu::clone() {
    return new VideoOptionMenu(window);
}

void VideoOptionMenu::updateValues() {

}
