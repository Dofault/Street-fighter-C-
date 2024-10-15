#include "CharacterView.h"


CharacterView::CharacterView(Character * character)
:character(character), sprite(new sf::Sprite()), animationManager(new AnimationManager(character, sprite))
{
    sprite->setTextureRect(sf::IntRect(0, 0, CHARACTER_DIMENSIONS.x, CHARACTER_DIMENSIONS.y));
    if(character->getType() == CharacterType::PALERMO) {
        sprite->setScale(5, 5);
    } else {
        sprite->setScale(6, 6);
    }
    sprite->setOrigin(sprite->getLocalBounds().width / 2, sprite->getLocalBounds().height / 2);
}
CharacterView::~CharacterView() {
    delete sprite;
    delete animationManager;
}

void CharacterView::animate() {
    animationManager->playSelectedAnimation();
}

void CharacterView::idle() {
    animationManager->setSelectedAnimation(AnimationType::IDLE);
}

void CharacterView::walkRight() {
    animationManager->setSelectedAnimation(AnimationType::WALK);
    sprite->setScale(-abs(sprite->getScale().x), sprite->getScale().y);
    sprite->move(character->getSpeed(), 0);
}

void CharacterView::walkLeft() {
    animationManager->setSelectedAnimation(AnimationType::WALK);
    sprite->setScale(abs(sprite->getScale().x), sprite->getScale().y);
    sprite->move(-character->getSpeed(), 0);
}

sf::Sprite *CharacterView::getSprite() {
    return sprite;
}

void CharacterView::punch() {
    animationManager->setSelectedAnimation(AnimationType::PUNCH);
}

void CharacterView::hit() {
    animationManager->setSelectedAnimation(AnimationType::HIT);
}

void CharacterView::hitCollapse() {
    animationManager->setSelectedAnimation(AnimationType::HIT_COLLAPSE);
}

CharacterView::CharacterView(CharacterView &c)
: sprite(new sf::Sprite(*c.sprite)), character(c.character), animationManager(new AnimationManager(character, sprite))
{

}

CharacterView &CharacterView::operator=(const CharacterView &c) {

    if (this != &c){

        delete sprite;
        delete animationManager;

        character = c.character;
        sprite = new sf::Sprite(*c.sprite);
        animationManager = new AnimationManager(*c.animationManager);
    }

    return *this;
}

double CharacterView::getRange() const {
    return character->getRange();
}
