#include "Player.h"
#include "utilities.h"

Player::Player(char* otherName, int otherMaxHP = 100, int otherForce = 5)
{
    this->name = otherName;
    this->level = 1;
    this->coins = 0;

    if(otherMaxHP <= 0)     otherMaxHP = 100;
    if(otherForce <  0)     otherForce = 5;
    this->force = otherForce;
    this->maxHP = otherMaxHP;
    
    this->HP = otherMaxHP;
}

void Player::printInfo() const{
    printPlayerInfo(name, level, force, HP, coins);
}

void Player::levelUp(){
    if(level == 10) return;
    level++;
}

int Player::getLevel() const{
    return level;
}

void Player::buff(const int i){
    force += i;
}

void Player::heal(const int i){
    if(i <= 0) return;
    if((HP + i) >= maxHP){
        HP = maxHP;
        return;
    }
    HP += i;
}

void Player::damage(const int i){
    if(i <= 0) return;
    if(HP <= i){
        HP = 0;
        return;
    }
    HP -= i;
}

bool Player::isKnockedOut() const{
    return !(HP);
}

void Player::addCoins(const int i){
    coins += i;
}

bool Player::pay(const int i){
    if(coins < i) return false;
    coins -= i;
    return true;
}

int Player::getAttackStrength() const{
    return (force + level); 
}
