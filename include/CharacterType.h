#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include "iostream"

using namespace std;

enum class CharacterType {
    PALERMO,
    ALTARES,
    GODEFROID,
    COLMANT,
    CRESPIN
};

string toString(CharacterType c); // Déclaration seulement

#endif // CHARACTERTYPE_H
