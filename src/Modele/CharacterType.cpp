#include "CharacterType.h"

string toString(CharacterType c) {
    switch (c) {
        case CharacterType::PALERMO:
            return "Palermo";
        case CharacterType::ALTARES:
            return "Altares";
        case CharacterType::GODEFROID:
            return "Godefroid";
        case CharacterType::COLMANT:
            return "Colmant";
        case CharacterType::CRESPIN:
            return "Crespin";
        default:
            return "Unknown";
    }
}
