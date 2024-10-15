#include "Character.h"

#include "CharacterType.h"
Character::Character(string name, CharacterType c, double health, double attack, double range, double speed)
        : name(name), type(c), health(health), attack(attack), range(range), speed(speed), healthMax(health) {
    energy = 10; // default energy

    setGuard(false);
}

Character::~Character() {
    // Destructeur
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        deadd = other.deadd;
        type = other.type;
        guard = other.guard;
        energy = other.energy;
        health = other.health;
        attack = other.attack;
        range = other.range;
        speed = other.speed;
        healthMax = other.healthMax;
    }
    return *this;
}

Character::Character(const Character& other):
name(other.name), type(other.type), health(other.health), attack(other.attack), range(other.range), speed(other.speed),
healthMax(other.health), energy(other.energy), deadd(other.deadd), guard(other.guard)
{

}


double Character::getMaxHealth() const {
    return healthMax;
};

bool Character::isDead() const {
    return deadd;
};

void Character::dead() {
    deadd = true;
};

void Character::reduceDamage(double damage) {
    if(health-damage < 0) {
        health = 0;
    }
    else
    {
        health = health - damage;
    }

    return;
}


double Character::getEnergy() const {
    return energy;
};
void Character::setEnergy(double newEnergy) {
    energy = newEnergy;
};
void Character::reduceEnergy(double energynb) {

    energy = energy - energynb;

    if(energy < 0) {
        energy = 0;
    }
};

string Character::getName() const {
    return name;
};

void Character::addEnergy(double energynb) {
    if(energy + energynb > 100) {
        energy = 100;
    }
    else
    {
        energy = energy + energynb;
    }
};


bool Character::getGuard() const {
    return guard;
};
void Character::setGuard(bool newguard) {
    guard = newguard;
};

CharacterType Character::getType() const {
    return type;
};

double Character::getHealth() const {
    return health;
}

void Character::setHealth(double newHealth) {
    health = newHealth;
}

double Character::getAttack() const {
    return attack;
}
void Character::setAttack(double newAttack) {
    attack = newAttack;
}

double Character::getRange() const {
    return range;
};
void Character::setRange(double newRange) {
    range = newRange;
    return;
};
double Character::getSpeed() const {
    return speed;
};
void Character::setSpeed(double newSpeed) {
    speed = newSpeed;
    return;
};


