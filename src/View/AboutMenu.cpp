#include "AboutMenu.h"

// about menu
AboutMenu::AboutMenu(sf::RenderWindow *window) : Menu(window) {


    titleText.setFont(*RessourceManager::getFont("MainFont"));
    titleText.setCharacterSize(60);
    titleText.setString("About");
    titleText.setPosition(window->getSize().x / 2, 50);
    titleText.setOrigin(titleText.getLocalBounds().width / 2, titleText.getLocalBounds().height / 2);
    titleText.setFillColor(sf::Color::Black);
    aboutText.setFillColor(sf::Color::Black);
    aboutText.setFont(*RessourceManager::getFont("MainFont"));
    aboutText.setCharacterSize(20);
    aboutText.setString("This game is inspired by the famous Street Fighter video game franchise.\n\n"
                        "Immerse yourself in intense battles between two characters\n\n"
                        "where the goal is to knock out your opponent in a single round.\n\n"
                        "The first character to defeat their opponent wins the victory.\n\n\n\n"
                        "Developed by:\n\n\n"
                        "Hadrien Strady\n\n"
                        "Aurelien Desplanque\n\n"
                        "Albert Voiturier\n\n"
                        "Tim Plasschaert\n\n\n\n"
                        "Music by:\n\n\n"
                        "Albert Voiturier");
   // Création de l'image de fond de la fenetre
    backgroundSprite.setTexture(*RessourceManager::getTexture("AboutBackground"));
    backgroundSprite.setScale(
            static_cast<float>(window->getSize().x) / backgroundSprite.getLocalBounds().width * 1,
            static_cast<float>(window->getSize().y) / backgroundSprite.getLocalBounds().height
    );
}

void AboutMenu::draw() {
    window->draw(backgroundSprite);
    window->draw(titleText);
    window->draw(aboutText);
}

void AboutMenu::updateValues() {
    titleText.setPosition(window->getSize().x / 2, 50);
    aboutText.setPosition(400, 320);

}

void AboutMenu::handleEvent(sf::Event event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
        MenuManager::setSelectedMenu("MainMenu");
    }
}

Menu *AboutMenu::clone() {
    return new AboutMenu(window);
}
