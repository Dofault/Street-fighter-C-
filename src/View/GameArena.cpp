#include "GameArena.h"
#include <SFML/Window.hpp>
#include "CharacterType.h"
#include "Character.h"
#include "CharacterView.h"
#include "iostream"
#include <cmath>
#include <fstream>
#include <sstream>

GameArena::GameArena(sf::RenderWindow * window, Character * character1, Character * character2)
        : Menu(window), character1(new Character(*character1)), character2(new Character(*character2))
{
    readConfigFile("config.txt");

    // Crete view character
    characterView1 = new CharacterView(this->character1);
    characterView2 = new CharacterView(this->character2);

    // Background image of the arena
    backgroundSprite.setTexture(*RessourceManager::getTexture("Arena"));
    backgroundSprite.setScale(
            static_cast<float>(window->getSize().x) / backgroundSprite.getLocalBounds().width * 1.3,
            static_cast<float>(window->getSize().y) / backgroundSprite.getLocalBounds().height
    );

    // The pictures of palermo is very big so we reduce the size if it, if other character we set the default size
    if (character1->getType() == CharacterType::PALERMO){
        characterView1->getSprite()->setPosition(window->getSize().x / 4, window->getSize().y - 190);
    }else{
        characterView1->getSprite()->setPosition(window->getSize().x / 4, window->getSize().y - 220);
    }

    if (character2->getType() == CharacterType::PALERMO){
        characterView2->getSprite()->setPosition(window->getSize().x / 4 * 3, window->getSize().y - 190);
    }else{
        characterView2->getSprite()->setPosition(window->getSize().x / 4 * 3, window->getSize().y - 220);
    }

    setInfoBar();
    setTextPseudo();

    // Versus logo and his position
    versusLogoSprite.setTexture(*RessourceManager::getTexture("VersusLogo"));
    versusLogoSprite.setPosition(window->getSize().x / 2, 63); // Coordonnées X et Y
    versusLogoSprite.setOrigin(versusLogoSprite.getLocalBounds().width / 2, versusLogoSprite.getLocalBounds().height / 2);
    versusLogoSprite.setScale(0.44, 0.44);

    // text when the party is finishing
    congratulationText.setFont(*RessourceManager::getFont("MainFont"));
    congratulationText.setFillColor(sf::Color::Green);
    congratulationText.setCharacterSize(30);
    congratulationText.setOutlineColor(sf::Color::Black);
    congratulationText.setOutlineThickness(3); // Épaisseur du contour
}

GameArena::~GameArena(){
    delete character1;
    delete character2;
    delete characterView1;
    delete characterView2;
}

void GameArena::readConfigFile(const std::string& filename) {
    std::ifstream configFile(filename);
    if (!configFile.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier de configuration." << std::endl;
        return;
    }

     std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream lineStream(line);
        std::string action, keyString;
        if (lineStream >> action >> keyString) {
            sf::Keyboard::Key key = sf::Keyboard::Unknown;
            if (keyString == "A") {
                key = sf::Keyboard::A;
            } else if (keyString == "B") {
                key = sf::Keyboard::B;
            } else if (keyString == "C") {
                key = sf::Keyboard::C;
            } else if (keyString == "D") {
                key = sf::Keyboard::D;
            } else if (keyString == "E") {
                key = sf::Keyboard::E;
            } else if (keyString == "F") {
                key = sf::Keyboard::F;
            } else if (keyString == "G") {
                key = sf::Keyboard::G;
            } else if (keyString == "H") {
                key = sf::Keyboard::H;
            } else if (keyString == "I") {
                key = sf::Keyboard::I;
            } else if (keyString == "J") {
                key = sf::Keyboard::J;
            } else if (keyString == "K") {
                key = sf::Keyboard::K;
            } else if (keyString == "L") {
                key = sf::Keyboard::L;
            } else if (keyString == "M") {
                key = sf::Keyboard::M;
            } else if (keyString == "N") {
                key = sf::Keyboard::N;
            } else if (keyString == "O") {
                key = sf::Keyboard::O;
            } else if (keyString == "P") {
                key = sf::Keyboard::P;
            } else if (keyString == "Q") {
                key = sf::Keyboard::Q;
            } else if (keyString == "R") {
                key = sf::Keyboard::R;
            } else if (keyString == "S") {
                key = sf::Keyboard::S;
            } else if (keyString == "T") {
                key = sf::Keyboard::T;
            } else if (keyString == "U") {
                key = sf::Keyboard::U;
            } else if (keyString == "V") {
                key = sf::Keyboard::V;
            } else if (keyString == "W") {
                key = sf::Keyboard::W;
            } else if (keyString == "X") {
                key = sf::Keyboard::X;
            } else if (keyString == "Y") {
                key = sf::Keyboard::Y;
            } else if (keyString == "Z") {
                key = sf::Keyboard::Z;
            } else if (keyString == "Num0") {
                key = sf::Keyboard::Num0;
            } else if (keyString == "Num1") {
                key = sf::Keyboard::Num1;
            } else if (keyString == "Num2") {
                key = sf::Keyboard::Num2;
            } else if (keyString == "Num3") {
                key = sf::Keyboard::Num3;
            } else if (keyString == "Num4") {
                key = sf::Keyboard::Num4;
            } else if (keyString == "Num5") {
                key = sf::Keyboard::Num5;
            } else if (keyString == "Num6") {
                key = sf::Keyboard::Num6;
            } else if (keyString == "Num7") {
                key = sf::Keyboard::Num7;
            } else if (keyString == "Num8") {
                key = sf::Keyboard::Num8;
            } else if (keyString == "Num9") {
                key = sf::Keyboard::Num9;
            } else if (keyString == "Escape") {
                key = sf::Keyboard::Escape;
            } else if (keyString == "LControl") {
                key = sf::Keyboard::LControl;
            } else if (keyString == "LShift") {
                key = sf::Keyboard::LShift;
            } else if (keyString == "LAlt") {
                key = sf::Keyboard::LAlt;
            } else if (keyString == "LSystem") {
                key = sf::Keyboard::LSystem;
            } else if (keyString == "RControl") {
                key = sf::Keyboard::RControl;
            } else if (keyString == "RShift") {
                key = sf::Keyboard::RShift;
            } else if (keyString == "RAlt") {
                key = sf::Keyboard::RAlt;
            } else if (keyString == "RSystem") {
                key = sf::Keyboard::RSystem;
            } else if (keyString == "Menu") {
                key = sf::Keyboard::Menu;
            } else if (keyString == "LBracket") {
                key = sf::Keyboard::LBracket;
            } else if (keyString == "RBracket") {
                key = sf::Keyboard::RBracket;
            } else if (keyString == "SemiColon") {
                key = sf::Keyboard::SemiColon;
            } else if (keyString == "Comma") {
                key = sf::Keyboard::Comma;
            } else if (keyString == "Period") {
                key = sf::Keyboard::Period;
            } else if (keyString == "Quote") {
                key = sf::Keyboard::Quote;
            } else if (keyString == "Slash") {
                key = sf::Keyboard::Slash;
            } else if (keyString == "BackSlash") {
                key = sf::Keyboard::BackSlash;
            } else if (keyString == "Tilde") {
                key = sf::Keyboard::Tilde;
            } else if (keyString == "Equal") {
                key = sf::Keyboard::Equal;
            } else if (keyString == "Dash") {
                key = sf::Keyboard::Dash;
            } else if (keyString == "Space") {
                key = sf::Keyboard::Space;
            } else if (keyString == "Return") {
                key = sf::Keyboard::Return;
            } else if (keyString == "BackSpace") {
                key = sf::Keyboard::BackSpace;
            } else if (keyString == "Tab") {
                key = sf::Keyboard::Tab;
            } else if (keyString == "PageUp") {
                key = sf::Keyboard::PageUp;
            } else if (keyString == "PageDown") {
                key = sf::Keyboard::PageDown;
            } else if (keyString == "End") {
                key = sf::Keyboard::End;
            } else if (keyString == "Home") {
                key = sf::Keyboard::Home;
            } else if (keyString == "Insert") {
                key = sf::Keyboard::Insert;
            } else if (keyString == "Delete") {
                key = sf::Keyboard::Delete;
            } else if (keyString == "Add") {
                key = sf::Keyboard::Add;
            } else if (keyString == "Subtract") {
                key = sf::Keyboard::Subtract;
            } else if (keyString == "Multiply") {
                key = sf::Keyboard::Multiply;
            } else if (keyString == "Divide") {
                key = sf::Keyboard::Divide;
            } else if (keyString == "Left") {
                key = sf::Keyboard::Left;
            } else if (keyString == "Right") {
                key = sf::Keyboard::Right;
            } else if (keyString == "Up") {
                key = sf::Keyboard::Up;
            } else if (keyString == "Down") {
                key = sf::Keyboard::Down;
            } else if (keyString == "Numpad0") {
                key = sf::Keyboard::Numpad0;
            } else if (keyString == "Numpad1") {
                key = sf::Keyboard::Numpad1;
            } else if (keyString == "Numpad2") {
                key = sf::Keyboard::Numpad2;
            } else if (keyString == "Numpad3") {
                key = sf::Keyboard::Numpad3;
            } else if (keyString == "Numpad4") {
                key = sf::Keyboard::Numpad4;
            } else if (keyString == "Numpad5") {
                key = sf::Keyboard::Numpad5;
            } else if (keyString == "Numpad6") {
                key = sf::Keyboard::Numpad6;
            } else if (keyString == "Numpad7") {
                key = sf::Keyboard::Numpad7;
            } else if (keyString == "Numpad8") {
                key = sf::Keyboard::Numpad8;
            } else if (keyString == "Numpad9") {
                key = sf::Keyboard::Numpad9;
            } else if (keyString == "F1") {
                key = sf::Keyboard::F1;
            } else if (keyString == "F2") {
                key = sf::Keyboard::F2;
            } else if (keyString == "F3") {
                key = sf::Keyboard::F3;
            } else if (keyString == "F4") {
                key = sf::Keyboard::F4;
            } else if (keyString == "F5") {
                key = sf::Keyboard::F5;
            } else if (keyString == "F6") {
                key = sf::Keyboard::F6;
            } else if (keyString == "F7") {
                key = sf::Keyboard::F7;
            } else if (keyString == "F8") {
                key = sf::Keyboard::F8;
            } else if (keyString == "F9") {
                key = sf::Keyboard::F9;
            } else if (keyString == "F10") {
                key = sf::Keyboard::F10;
            } else if (keyString == "F11") {
                key = sf::Keyboard::F11;
            } else if (keyString == "F12") {
                key = sf::Keyboard::F12;
            } else if (keyString == "F13") {
                key = sf::Keyboard::F13;
            } else if (keyString == "F14") {
                key = sf::Keyboard::F14;
            } else if (keyString == "F15") {
                key = sf::Keyboard::F15;
            } else if (keyString == "Pause") {
                key = sf::Keyboard::Pause;
            }

            // Associe chaque touche à son action
            if (key != sf::Keyboard::Unknown) {
                keyMap[action] = key;
            }
        }
    }
}

bool GameArena::checkAttackDistance(CharacterView& attacker, CharacterView& defender) {
    sf::Vector2f positionAttacker = attacker.getSprite()->getPosition();
    sf::Vector2f positionDefender = defender.getSprite()->getPosition();
    float distance = sqrt(pow(positionAttacker.x - positionDefender.x, 2) + pow(positionAttacker.y - positionDefender.y, 2));

    double attackRange = attacker.getRange();

    return (distance <= attackRange);
}

void GameArena::setTextPseudo() {
        // PSEUDO DISPLAY FOR CHARACTER 1
        characterName1.setFont(*RessourceManager::getFont("MainFont"));

        characterName1.setString(character1->getName());
        characterName1.setCharacterSize(16);
        characterName1.setFillColor(sf::Color::Black);
        characterName1.setOutlineColor(sf::Color::Yellow);
        characterName1.setOutlineThickness(1);
        characterName1.setPosition(10 + widhHealthBar, 45);
        characterName1.setOrigin(characterName1.getLocalBounds().width, 0);

        // PSEUDO DISPLAY FOR CHARACTER 2
        characterName2.setFont(*RessourceManager::getFont("MainFont"));
        characterName2.setString(character2->getName());
        characterName1.setOutlineColor(sf::Color::Yellow);
        characterName1.setOutlineThickness(1);
        characterName2.setCharacterSize(16);
        characterName2.setFillColor(sf::Color::Black);
        characterName2.setPosition(window->getSize().x - (healthBar2.getSize().x + 10), 45);
}

void GameArena::setInfoBar() {

        // Health bar generation
        healthBar1 = sf::RectangleShape(sf::Vector2f(widhHealthBar, heightHealthBar)); // dimension bar
        healthBar1.setFillColor(sf::Color(255, 255, 0));
        healthBar1.setPosition(20 + widhHealthBar, paddingTopHealthBar);  // position in the window
        healthBar1.setScale(-1.0f, 1.0f); // miror middle

        healthBarRed1 = sf::RectangleShape(sf::Vector2f(widhHealthBar, heightHealthBar)); // dimension bar
        healthBarRed1.setFillColor(sf::Color(255, 51, 51));  // color
        healthBarRed1.setPosition(20, paddingTopHealthBar);  // position in the window


        healthBar2 = sf::RectangleShape(sf::Vector2f(widhHealthBar, heightHealthBar)); // same but in the second bar
        healthBar2.setFillColor(sf::Color(255, 255, 0));
        healthBar2.setPosition(window->getSize().x - (healthBar2.getSize().x +20), paddingTopHealthBar);

        healthBarRed2 = sf::RectangleShape(sf::Vector2f(widhHealthBar, heightHealthBar)); // dimension bar
        healthBarRed2.setFillColor(sf::Color(255, 51, 51));  // color
        healthBarRed2.setPosition(window->getSize().x - (healthBar2.getSize().x +20), paddingTopHealthBar);

        // Energy bar generation
        energyBar1 = sf::RectangleShape(sf::Vector2f(widhEnergyBar, heightEnergyBar)); // dimension bar
        energyBar1.setFillColor(sf::Color::Cyan);  // color
        energyBar1.setPosition(20 + widhEnergyBar,  heightHealthBar + paddingTopHealthBar);  // position in the window
        energyBar1.setScale(-1.0f, 1.0f); // miror middle

        energyBar2 = sf::RectangleShape(sf::Vector2f(widhEnergyBar, heightEnergyBar));
        energyBar2.setFillColor(sf::Color::Cyan);
        energyBar2.setPosition(window->getSize().x - (healthBar2.getSize().x +20), heightHealthBar+ paddingTopHealthBar );  // position in the window
}

void GameArena::handleEvent(sf::Event event) {

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape){
        if (endGame){
            MenuManager::setSelectedMenu("MainMenu");
        }else{
            MenuManager::setSelectedMenu("PauseMenu");
        }
    }

    if (event.type == sf::Event::KeyReleased && !character1IsDead && character1AttackTimer.getElapsedTime().asMilliseconds() >= speedAttackCharacter1.asMilliseconds()){
        if (event.key.code == keyMap["Droite1"] || event.key.code == keyMap["Gauche1"]){
            characterView1->idle();
        }
        if(event.key.code == keyMap["Defendre1"]) {
            character1->setGuard(false);
        }
    }

    if (event.type == sf::Event::KeyReleased && !character2IsDead && character2AttackTimer.getElapsedTime().asMilliseconds() >= speedAttackCharacter1.asMilliseconds()){
        if (event.key.code == keyMap["Droite2"] || event.key.code == keyMap["Gauche2"]){
            characterView2->idle();
        }
        if(event.key.code == keyMap["Defendre2"]) {
            character2->setGuard(false);
        }
    }

}

void GameArena::draw() {
    window->draw(backgroundSprite);
    window->draw(*characterView1->getSprite());
    window->draw(*characterView2->getSprite());
    window->draw(healthBarRed1);
    window->draw(healthBarRed2);
    window->draw(healthBar1);
    window->draw(healthBar2);
    window->draw(characterName2);
    window->draw(characterName1);
    window->draw(energyBar1);
    window->draw(energyBar2);
    window->draw(spriteBar1);
    window->draw(spriteBar2);
    window->draw(versusLogoSprite);

    if (endGame){
        window->draw(congratulationText);
    }

}

Menu *GameArena::clone() {
    return new GameArena(window, character1, character2);
}

void GameArena::updateValues() {
    // handle move player 1, if C1 not dead and
    if(!character1IsDead && character1AttackTimer.getElapsedTime().asMilliseconds() >= speedAttackCharacter1.asMilliseconds()) {
        if (sf::Keyboard::isKeyPressed(keyMap["Attaquer1"])) { // If ENTER (attaque character 1) was pressed
            character1AttackTimer.restart(); // reload cooldown for the attack
            characterView1->punch();

            // if C2 is in the range of the C1
                if (!character2->getGuard() && checkAttackDistance(*characterView1, *characterView2) && !character2IsDead) {
                // reduce damage, animation, if
                character2->reduceDamage(character1->getAttack());
                if(character2->getHealth() <= 0) { //// if dead
                    characterView2->hitCollapse();
                    character2IsDead = true;
                    clockDeadCharacter2.restart();
                    endGame = true;
                    congratulationText.setString(character2->getName() + " KO.\nWinner : " + character1->getName());
                    congratulationText.setOrigin(congratulationText.getLocalBounds().width / 2, congratulationText.getLocalBounds().height);
                    congratulationText.setPosition(window->getSize().x / 2, window->getSize().y / 2);
                }
                else
                {
                    characterView2->hit();
                    character1->addEnergy(20);
                }
            }


        } else if (sf::Keyboard::isKeyPressed(keyMap["Droite1"])) {
            characterView1->walkRight();
            character1->setGuard(false); // guard false to be sure that he can't walk with the guard in true
        } else if (sf::Keyboard::isKeyPressed(keyMap["Gauche1"])) {
            characterView1->walkLeft();
            character1->setGuard(false); // guard false to be sure that he can't walk with the guard in true
        } else if (sf::Keyboard::isKeyPressed(keyMap["Defendre1"]) && character1->getEnergy() > 0) {
            characterView1->hit();
            character1->reduceEnergy(1); // number of energy use to keep de guard
            character1->setGuard(true); // guard true
        } else if(character1->getEnergy() <= 0) {
            character1->setGuard(false);
        }
    }

    // handle move player 2
    if(!character2IsDead && character2AttackTimer.getElapsedTime().asMilliseconds() >= speedAttackCharacter2.asMilliseconds()) {
        if (sf::Keyboard::isKeyPressed(keyMap["Attaquer2"])) { // If ENTER (attaque character 1) was pressed
            character2AttackTimer.restart(); // reload cooldown for the attack
            characterView2->punch();
            // if C2 is in the range of the C1
            if (!character1->getGuard() && checkAttackDistance(*characterView2, *characterView1) && !character1IsDead) {
                // reduce damage, animation, if
                character1->reduceDamage(character2->getAttack());
                if(character1->getHealth() <= 0) { // if dead
                    characterView1->hitCollapse();
                    character1IsDead = true;
                    clockDeadCharacter1.restart();
                    endGame = true;
                    congratulationText.setString(character1->getName() + " KO.\nWinner : " + character2->getName());
                    congratulationText.setOrigin(congratulationText.getLocalBounds().width / 2, congratulationText.getLocalBounds().height);
                    congratulationText.setPosition(window->getSize().x / 2, window->getSize().y / 2);
                }
                else
                {
                    characterView1->hit();
                    character2->addEnergy(20);
                }
            }
        } else if (sf::Keyboard::isKeyPressed(keyMap["Droite2"])) {
            characterView2->walkRight();
            character1->setGuard(false);
        } else if (sf::Keyboard::isKeyPressed(keyMap["Gauche2"])) {
            characterView2->walkLeft();
            character1->setGuard(false);
        } else if (sf::Keyboard::isKeyPressed(keyMap["Defendre2"]) && character2->getEnergy() > 0) {
            characterView2->hit();
            character2->reduceEnergy(1);
            character2->setGuard(true);
        } else if(character2->getEnergy() <= 0) {
            character2->setGuard(false);
        }
    }

    // thread of the game
    sf::sleep(sf::milliseconds(50));

    if ((!character1IsDead &&
        clockDeadCharacter1.getElapsedTime().asMilliseconds() >= minimumDeadCharacter2.asMilliseconds()) ||
        clockDeadCharacter1.getElapsedTime().asMilliseconds() < minimumDeadCharacter2.asMilliseconds()) {
        characterView1->animate();
    }

    // if in life or the clock tell he is in animation dead we continue to animate it
    if ((!character2IsDead &&
        clockDeadCharacter2.getElapsedTime().asMilliseconds() >= minimumDeadCharacter1.asMilliseconds()) ||
        clockDeadCharacter2.getElapsedTime().asMilliseconds() < minimumDeadCharacter1.asMilliseconds()) {
        characterView2->animate();
    }

    // Update bar health
    double healthRatio1 = character1->getHealth() / character1->getMaxHealth();
    double healthRatio2 = character2->getHealth() / character2->getMaxHealth();

    if (healthRatio1 < 0) {
        healthRatio1 = 0;
    }
    if (healthRatio2 < 0) {
        healthRatio2 = 0;
    }
    healthBar1.setSize(sf::Vector2f(widhHealthBar * healthRatio1, heightHealthBar));
    healthBar2.setSize(sf::Vector2f(widhHealthBar * healthRatio2, heightHealthBar));

    double energyRatio1 = character1->getEnergy() / 100; // 100 is the max energy
    double energyRatio2 = character2->getEnergy() / 100;
    energyBar1.setSize(sf::Vector2f(widhEnergyBar * energyRatio1, heightEnergyBar));
    energyBar2.setSize(sf::Vector2f(widhEnergyBar * energyRatio2, heightEnergyBar));
}

GameArena::GameArena(GameArena &menu): Menu(menu.window),
character1(new Character(*menu.character1)), character2(new Character(*menu.character2)),
characterView1(new CharacterView(*menu.characterView1)), characterView2(new CharacterView(*menu.characterView2)),
endGame(menu.endGame), healthBar1(menu.healthBar1), healthBar2(menu.healthBar2), energyBar1(menu.energyBar1), energyBar2(menu.energyBar2),
spriteBar1(menu.spriteBar1), spriteBar2(menu.spriteBar2), versusLogoSprite(menu.versusLogoSprite), backgroundSprite(menu.backgroundSprite),
healthBarRed1(menu.healthBarRed1), healthBarRed2(menu.healthBarRed2), character1IsDead(menu.character1IsDead), character2IsDead(menu.character2IsDead),
characterName1(menu.characterName1), characterName2(menu.characterName2), keyMap(menu.keyMap), congratulationText(menu.congratulationText),
character1AttackTimer(menu.character1AttackTimer), character2AttackTimer(menu.character2AttackTimer),
clockDeadCharacter1(menu.clockDeadCharacter1), clockDeadCharacter2(menu.clockDeadCharacter2)
{

}

GameArena &GameArena::operator=(GameArena &menu) {

    if (this != &menu){
        delete character1;
        delete character2;
        delete characterView1;
        delete characterView2;

        character1 = new Character(*menu.character1);
        character2 = new Character(*menu.character2);
        characterView1 = new CharacterView(*menu.characterView1);
        characterView2 = new CharacterView(*menu.characterView2);

        endGame = menu.endGame;
        healthBar1 = menu.healthBar1;
        healthBar2 = menu.healthBar2;
        energyBar1 = menu.energyBar1;
        energyBar2 = menu.energyBar2;
        spriteBar1 = menu.spriteBar1;
        spriteBar2 = menu.spriteBar2;
        versusLogoSprite = menu.versusLogoSprite;
        backgroundSprite = menu.backgroundSprite;
        healthBarRed1 = menu.healthBarRed1;
        healthBarRed2 = menu.healthBarRed2;
        character1IsDead = menu.character1IsDead;
        character2IsDead = menu.character2IsDead;
        characterName1 = menu.characterName1;
        characterName2 = menu.characterName2;
        congratulationText = menu.congratulationText;
        keyMap = menu.keyMap;
        character1AttackTimer = menu.character1AttackTimer;
        character2AttackTimer = menu.character2AttackTimer;
        clockDeadCharacter1 = menu.clockDeadCharacter1;
        clockDeadCharacter2 = menu.clockDeadCharacter2;
    }

    return *this;
}


