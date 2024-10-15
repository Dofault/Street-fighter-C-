#ifndef CHARACTER_H
#define CHARACTER_H

#include "CharacterType.h"

#include "iostream"

using namespace std;

class Character
{
public:
    Character(string name, CharacterType c, double health, double attack, double range, double speed);


    Character() : type(CharacterType::CRESPIN), health(100.0), attack(7.0), range(300.0), speed(17.0), healthMax(health) {}


    ~Character();
    // Constructeur de copie
    Character(const Character& other);

    // Opérateur d'assignation de copie
    Character& operator=(const Character& other);


    // Méthode pour obtenir
    double getHealth() const;
    void setHealth(double newHealth);
    double getAttack() const;
    void setAttack(double newAttack);

    double getRange() const;
    void setRange(double newRange);
    double getSpeed() const;
    void setSpeed(double newSpeed);
    double getMaxHealth() const;

    double getEnergy() const;
    void setEnergy(double newEnergy);
    void reduceEnergy(double energy);
    void addEnergy(double energy);

    void reduceDamage(double damage);
    CharacterType getType() const;

    bool getGuard() const;
    void setGuard(bool guard);

    bool isDead() const;
    void dead();

    string getName() const;
private:
    string name;

    bool deadd=false;

    CharacterType type;
    bool guard;
    double energy;
    double health;
    double attack;
    double range;
    double speed;
    double healthMax;
};

#endif // CHARACTER_H
