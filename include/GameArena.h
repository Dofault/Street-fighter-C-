#ifndef GAMEARENA_H
#define GAMEARENA_H

#include <SFML/Graphics.hpp>
#include "Character.h"
#include "AnimationManager.h"
#include "iostream"
#include "CharacterView.h"
#include "CharacterType.h"
#include "KeybindingOptionMenu.h"
#include "Menu.h"

using namespace std;

class GameArena : public Menu{
public:
    GameArena(sf::RenderWindow * window, Character * character1, Character * character2);
    ~GameArena() override;
    GameArena(GameArena & menu);
    GameArena & operator=(GameArena & menu);

    void draw() override;
    void updateValues() override;
    void handleEvent(sf::Event event) override;
    Menu * clone() override;

    void play();

    void setTextPseudo();
    void setInfoBar();
    bool checkAttackDistance(CharacterView &attacker, CharacterView &defender);
    void readConfigFile(const std::string &filename);

private:

    // Character and CharacterView
    Character * character1;
    Character * character2;
    CharacterView * characterView1;
    CharacterView * characterView2;

    // Constantes necessaires
    double paddingTopHealthBar = 40;
    double heightEnergyBar = 9;
    double widhEnergyBar = 400;
    double widhHealthBar = 400;
    double heightHealthBar = 30;

    bool endGame=false;

    // health bar of players
    sf::RectangleShape healthBar1;
    sf::RectangleShape healthBar2;
    sf::RectangleShape energyBar1;
    sf::RectangleShape energyBar2;
    sf::Sprite spriteBar1;
    sf::Sprite spriteBar2;
    sf::Sprite versusLogoSprite;
    sf::Sprite backgroundSprite;
    sf::RectangleShape healthBarRed1;
    sf::RectangleShape healthBarRed2;
    bool character1IsDead = false;
    bool character2IsDead = false;
    sf::Text characterName1;
    sf::Text characterName2;
    std::unordered_map<std::string, sf::Keyboard::Key> keyMap;

    sf::Text congratulationText;

    // Clocks of daed and attack of the player
    sf::Clock character1AttackTimer;
    sf::Clock character2AttackTimer;
    sf::Clock clockDeadCharacter1;
    sf::Clock clockDeadCharacter2;

    // Clock use for the delay between each punch
    sf::Time speedAttackCharacter1 = sf::milliseconds(700); // ajustable selon les personnages
    sf::Time speedAttackCharacter2 = sf::milliseconds(700);

    // Clock use for the delay between the dead of the player and the end of animation of the dead of the player
    sf::Time minimumDeadCharacter1 = sf::milliseconds(600);
    sf::Time minimumDeadCharacter2 = sf::milliseconds(600);

};

#endif // GAMEARENA_H
