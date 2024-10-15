#include "CharacterSelectionMenu.h"
#include "RessourceManager.h"
#include "GameArena.h"
#include "unistd.h"

CharacterSelectionMenu::CharacterSelectionMenu(sf::RenderWindow * window) : Menu(window) {
    player1Character = "";
    playerName = "";
    setupMenu();
}

CharacterSelectionMenu::~CharacterSelectionMenu()
{
}

void CharacterSelectionMenu::setupMenu() {
    float windowX = static_cast<float>(window->getSize().x) / 2.0f;
    float windowY = static_cast<float>(window->getSize().y) / 2.0f;


    sprite.setTextureRect(sf::IntRect(0, 0, 96, 63));
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height);
    sprite.setScale(6, 6);
    sprite.setPosition(windowX, windowY);

    currentType= CharacterType::PALERMO;
    sprite.setTexture(*RessourceManager::getTexture(toString(currentType) + "Idle"));

    instruction.setFont(*RessourceManager::getFont("MainFont"));
    instruction.setCharacterSize(19);

    instruction.setString("(1/2)\n1) Enter your character name\n2) Choose your figther with left or right\n3) Press ENTER");
    instruction.setOrigin(instruction.getLocalBounds().width / 2, instruction.getLocalBounds().height);
    instruction.setPosition(windowX, windowY*2 - 50);

    // Configuration du texte pour le joueur 1
    playerText.setFont(*RessourceManager::getFont("MainFont"));
    playerText.setCharacterSize(24);
    playerText.setOrigin(playerText.getLocalBounds().width / 2, playerText.getLocalBounds().height);
    playerText.setPosition(windowX, windowY+100);

    // Configuration du texte pour le nom du joueur
    nameText.setFont(*RessourceManager::getFont("MainFont"));
    nameText.setCharacterSize(24);
    nameText.setString("Name P1: " + playerName);
    nameText.setOrigin(nameText.getLocalBounds().width / 2, nameText.getLocalBounds().height);
    nameText.setPosition(windowX, windowY+200);
}

void CharacterSelectionMenu::handleEvent(sf::Event event) {

    if (event.type == sf::Event::TextEntered) {

        if (event.text.unicode == 10 ||event.text.unicode == 13){
            return;
        }

        if (event.text.unicode < 128) {
            if (event.text.unicode == 8 && !playerName.empty()) { // 8 : backspace
                playerName.pop_back();

            } else {
                if(playerName.size() < 15) {
                    // Ajout du caractère saisi au nom du joueur
                    playerName += static_cast<char>(event.text.unicode);
                    return;
                }

            }
        }

    } else if (event.type == sf::Event::KeyPressed) {

        if (event.key.code == sf::Keyboard::Enter) { // enter
            if(numPlayerSelect == 0) {
                character1 = Character(playerName, currentType, 100, 5, 200, 17);
                player1Character = "Player 1\nFighter : " + toString(currentType) + "\nName : " + playerName;

                playerName.clear();
                instruction.setString("(2/2)\n1) Enter your character name\n2) Choose your figther with left or right\n3) Press ENTER");
                numPlayerSelect++;
            }
            else
            {
                if(numPlayerSelect == 1) {
                    character2 = Character(playerName, currentType, 100, 5, 200, 17);
                    numPlayerSelect++;
                }
            }

            if(numPlayerSelect == 2) {
                numPlayerSelect=0;

                GameArena game(window, &character1, &character2);
                MenuManager::replaceMenu("GameArena", &game);
                MenuManager::setSelectedMenu("GameArena");
                return;
            }
        }

        if (event.key.code == sf::Keyboard::Left) {
            left();
            updateCharacter();
        }

        if (event.key.code == sf::Keyboard::Right) {
            right();
            updateCharacter();
        }
    }
}

void CharacterSelectionMenu::updateCharacter() {
    currentType= static_cast<CharacterType>(characterChoice);

    sprite.setTexture(*RessourceManager::getTexture(toString(currentType) + "Idle"));
}

void CharacterSelectionMenu::left() {
    if(characterChoice-1 <0) {
        characterChoice = 4;
    }
    else
    {
        characterChoice--;
    }
}

void CharacterSelectionMenu::right() {
    if(characterChoice+1 > 4) {
        characterChoice = 0;
    }
    else
    {
        characterChoice++;
    }
}

void CharacterSelectionMenu::draw() {

    // Dessiner le texte
    window->draw(sprite);
    window->draw(playerText);
    window->draw(nameText);
    window->draw(instruction);
}

void CharacterSelectionMenu::updateValues() {
    // Mettre à jour le texte avec les choix du joueur
    playerText.setString(player1Character);
    playerText.setOrigin(playerText.getLocalBounds().width / 2, playerText.getLocalBounds().height);
    int num = (numPlayerSelect+1);

    nameText.setString("Player " + to_string(num) + "\nFighter : " + toString(currentType) + "\nName: " + playerName);
    nameText.setOrigin(nameText.getLocalBounds().width / 2, nameText.getLocalBounds().height);

    if(currentType == CharacterType::PALERMO) {
        sprite.setScale(5, 5);
    }
    else
    {
        sprite.setScale(6, 6);
    }
}

Menu *CharacterSelectionMenu::clone() {
    return new CharacterSelectionMenu(window);
}

CharacterSelectionMenu::CharacterSelectionMenu(CharacterSelectionMenu &menu):
Menu(menu.window),
sprite(menu.sprite), player1Character(menu.player1Character), playerName(menu.playerName), currentType(menu.currentType),
character1(menu.character1), character2(menu.character2), characterChoice(menu.characterChoice), numPlayerSelect(menu.numPlayerSelect),
instruction(menu.instruction), playerText(menu.playerText), nameText(menu.nameText)
{

}

CharacterSelectionMenu &CharacterSelectionMenu::operator=(CharacterSelectionMenu &menu) {

    if (this != &menu){
        this->window = menu.window;
        this->sprite = menu.sprite;
        this->player1Character = menu.player1Character;
        this->playerName = menu.playerName;
        this->currentType = menu.currentType;
        this->character1 = menu.character1;
        this->character2 = menu.character2;
        this->characterChoice = menu.characterChoice;
        this->numPlayerSelect = menu.numPlayerSelect;
        this->instruction = menu.instruction;
        this->playerText = menu.playerText;
        this->nameText = menu.nameText;
    }

    return *this;
}
