#ifndef ANIMATIONTYPE_H_INCLUDED
#define ANIMATIONTYPE_H_INCLUDED


#include "iostream"

using namespace std;

enum class AnimationType {
    WALK,
    IDLE,
    PUNCH,
    HIT,
    HIT_COLLAPSE
};

string toString(AnimationType a);

#endif // ANIMATIONTYPE_H_INCLUDED
