#include "AnimationManager.h"
#include "RessourceManager.h"

AnimationManager::AnimationManager(Character * character, sf::Sprite * animatedSprite):
character(character), animatedSprite(animatedSprite)
{
    createAnimationSet();
}

AnimationManager::~AnimationManager() {

    auto it = animationSet.begin();

    while (it != animationSet.end()) {

        Animation *tmp = it->second;

        // Erase the current element and get the iterator to the next one
        it = animationSet.erase(it);

        // Delete the animation
        delete tmp;
    }

}

bool AnimationManager::addAnimation(AnimationType key, Animation * animation) {
    if (animation != nullptr){
        animationSet[key] = new Animation(*animation);
        return true;
    }

    return false;
}

void AnimationManager::playSelectedAnimation() {
    if (selectedAnimation->play()){
        selectedAnimation = defaultAnimation;
    }
}

void AnimationManager::createAnimationSet() {

    string perso = toString(character->getType());

    animationSet[AnimationType::IDLE] =
            new Animation(animatedSprite, RessourceManager::getTexture(perso + "Idle"), sf::Vector2i(96, 63), 6, 4, true);
    animationSet[AnimationType::WALK] =
            new Animation(animatedSprite, RessourceManager::getTexture(perso + "Walk"), sf::Vector2i(96, 63), 10, 4, true);
    animationSet[AnimationType::PUNCH] =
            new Animation(animatedSprite, RessourceManager::getTexture(perso + "Punch"), sf::Vector2i(96, 63), 10, 3, false);
    animationSet[AnimationType::HIT] =
            new Animation(animatedSprite, RessourceManager::getTexture(perso + "Hit"), sf::Vector2i(96, 63), 6, 2, false);
    animationSet[AnimationType::HIT_COLLAPSE] =
            new Animation(animatedSprite, RessourceManager::getTexture(perso + "HitCollapse"), sf::Vector2i(96, 63), 6, 4, false);

    defaultAnimation = animationSet[AnimationType::IDLE];
    selectedAnimation = defaultAnimation;
}

void AnimationManager::setSelectedAnimation(AnimationType key) {
    selectedAnimation = animationSet[key];
    animatedSprite->setTexture(*selectedAnimation->getSpritesheet());
}

AnimationManager::AnimationManager(AnimationManager &am):
character(am.character), animatedSprite(am.animatedSprite)
{
    for (auto it = am.animationSet.begin(); it != am.animationSet.end(); it++){
        animationSet[it->first] = new Animation(*it->second);
    }
}

