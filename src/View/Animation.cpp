#include "Animation.h"

Animation::Animation
(sf::Sprite * sprite, sf::Texture * spritesheet, sf::Vector2i frameDimension, int frameRate, int nbFrames, bool loop)
:sprite(sprite), spritesheet(spritesheet), frameDimension(frameDimension), frameRate(frameRate), nbFrames(nbFrames), loop(loop)
{
    frameRect = sf::IntRect(0, 0, frameDimension.x, frameDimension.y);
}

Animation::Animation(const Animation &a)
:sprite(a.sprite), spritesheet(a.spritesheet), frameDimension(a.frameDimension),
frameRate(a.frameRate), nbFrames(a.nbFrames), loop(a.loop), frameRect(a.frameRect)
{

}

Animation::~Animation() {}

Animation &Animation::operator=(const Animation &a) {

    if (this != &a){
        frameRect = a.frameRect;
        sprite = a.sprite;
        spritesheet = a.spritesheet;
        frameDimension = a.frameDimension;
        frameRate = a.frameRate;
        nbFrames = a.nbFrames;
        loop = a.loop;
    }

    return *this;
}

bool Animation::play() {

    if (sprite->getTexture() != spritesheet){
        sprite->setTexture(*spritesheet);
    }

    // Si le temps dépasse le temps donné par frame, on change la frame
    if (clock.getElapsedTime().asSeconds() >= 1.0/frameRate){

        // Si c'est la dernière frame, on remet le frameRect à 0 (revient à la première frame)
        if (frameRect.left == frameDimension.x * (nbFrames - 1)){
            frameRect.left = 0;
            if (!loop) return true;

            // Sinon, on passe à la frame suivante
        }else{
            frameRect.left += frameDimension.x;
        }

        // On rafraichit le sprite et on relance le timer
        sprite->setTextureRect(frameRect);
        clock.restart();
    }

    return false;
}

sf::Texture * Animation::getSpritesheet() {
    return spritesheet;
}
