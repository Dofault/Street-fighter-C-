#include "AnimationType.h"


string toString(AnimationType a){
    switch (a) {
        case AnimationType::IDLE:
            return "Idle";
        case AnimationType::WALK:
            return "Walk";
        case AnimationType::PUNCH:
            return "Punch";
        case AnimationType::HIT:
            return "Hit";
        case AnimationType::HIT_COLLAPSE:
            return "HitCollapse";
        default:
            return "Unknown"; // Cas par défaut si la valeur de l'enum n'est pas reconnue
    }
}
