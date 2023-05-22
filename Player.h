#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "utilities.h"

class Player {
private:
    char* name;
    int level;
    int force;
    int maxHP;
    int HP;
    int coins;

public:
    Player(char* name, const int maxHp = 100, const int force = 5);

    void printInfo();
    void levelup();
    const int getLevel();
    void buff(int i);
    void heal(int i);
    void damage(int i);
    bool isKnockedOut();
    void addCoins(int i);
    bool pay(int i);
    int getAttackStrength();
    // Add other member functions or variables as needed
};

#endif
