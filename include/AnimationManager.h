#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include "iostream"
#include "Animation.h"
#include "Character.h"
#include "AnimationType.h"

using namespace std;

class AnimationManager {
private:
    map<AnimationType, Animation*> animationSet;
    Animation * selectedAnimation;
    Animation * defaultAnimation;
    sf::Sprite * animatedSprite;
    Character * character;

public:
    AnimationManager(Character * character, sf::Sprite * animatedSprite);
    AnimationManager(AnimationManager & am);
    AnimationManager & operator=(AnimationManager & a);
    ~AnimationManager();

    void createAnimationSet();
    void playSelectedAnimation();
    void setSelectedAnimation(AnimationType key);
    bool addAnimation(AnimationType key, Animation * animation);

};

#endif // ANIMATIONMANAGER_H
