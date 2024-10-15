#ifndef CHARACTERVIEW_H
#define CHARACTERVIEW_H

#include "iostream"
#include "Character.h"
#include "AnimationManager.h"
#include "SFML/Graphics.hpp"

const sf::Vector2i CHARACTER_DIMENSIONS(96, 63);

class CharacterView {
private:

    Character * character;
    sf::Sprite * sprite;
    AnimationManager * animationManager;

public:
    CharacterView(Character * character);
    ~CharacterView();
    CharacterView(CharacterView & c);
    CharacterView & operator=(const CharacterView & c);

    void animate();

    void idle();
    void walkLeft();
    void walkRight();
    void punch();
    void hit();
    void hitCollapse();

    double getRange() const;

    sf::Sprite * getSprite();
};


#endif // CHARACTERVIEW_H
