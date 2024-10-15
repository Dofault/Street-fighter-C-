#ifndef ANIMATION_H
#define ANIMATION_H

#include "SFML/Graphics.hpp"
#include "iostream"

using namespace std;

class Animation {
private:
    sf::Sprite * sprite;
    sf::Texture * spritesheet;
    sf::IntRect frameRect;
    sf::Vector2i frameDimension;
    sf::Clock clock;
    int frameRate;
    int nbFrames;
    bool loop;

public:

    Animation(
            sf::Sprite * sprite,
            sf::Texture * spritesheet,
            sf::Vector2i frameDimension,
            int frameRate,
            int nbFrames,
            bool loop
    );
    ~Animation();
    Animation(const Animation & a);
    Animation & operator=(const Animation & a);

    bool play();
    sf::Texture * getSpritesheet();

};

#endif // ANIMATION_H
