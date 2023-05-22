#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
private:
    char* name;
    int level;
    int force;
    int maxHP;
    int HP;
    int coins;

public:
    Player(char* name, int maxHp = 100, int force = 5);

    void printInfo() const;
    void levelUp();
    int getLevel() const;
    void buff(const int i);
    void heal(const int i);
    void damage(const int i);
    bool isKnockedOut() const;
    void addCoins(const int i);
    bool pay(const int i);
    int getAttackStrength() const;
    // Add other member functions or variables as needed
};

#endif
