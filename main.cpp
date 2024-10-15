#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.h"
#include "RessourceManager.h"
#include "MenuManager.h"
#include "GameArena.h"
#include "Character.h"
#include "OptionMenu.h"
#include <iostream>
#include "AudioOptionMenu.h"
#include "PauseMenu.h"
#include "VideoOptionMenu.h"
#include "AboutMenu.h"
#include "CharacterSelectionMenu.h"

using namespace sf;

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1920, 1080), "Helha Fighter", sf::Style::Close | sf::Style::Titlebar);

    RessourceManager::loadAllRessources();

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("HelhaFighter_MainTheme.wav")) {

        return -1;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    sound.setLoop(true);

    Character c1;
    Character c2;

    MainMenu mainMenu(&app);
    OptionMenu optionMenu(&app);
    GameArena gameArena(&app, &c1, &c2);
    AudioOptionMenu audioOptionMenu(&app, &sound);
    KeybindingOptionMenu keybindingOptionMenu(&app);
    PauseMenu pauseMenu(&app);
    VideoOptionMenu videoOptionMenu(&app);
    AboutMenu aboutMenu(&app);


    MenuManager::addMenu("MainMenu", &mainMenu);
    MenuManager::addMenu("OptionMenu", &optionMenu);
    MenuManager::addMenu("AudioOptionMenu", &audioOptionMenu);
    MenuManager::addMenu("KeybindingOptionMenu", &keybindingOptionMenu);
    MenuManager::addMenu("PauseMenu", &pauseMenu);
    MenuManager::addMenu("GameArena", &gameArena);
    MenuManager::addMenu("VideoOptionMenu", &videoOptionMenu);
    MenuManager::addMenu("AboutMenu", &aboutMenu);
    MenuManager::setSelectedMenu("MainMenu");

    while (app.isOpen())
    {
        Event event;

        while (app.pollEvent(event)){
            if (event.type == Event::Closed)
                app.close();

            MenuManager::getSelectedMenu()->handleEvent(event);
        }

        MenuManager::getSelectedMenu()->updateValues();
        app.clear();
        MenuManager::getSelectedMenu()->draw();

        app.display();
    }

    return EXIT_SUCCESS;
}
