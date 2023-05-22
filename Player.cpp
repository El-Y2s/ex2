#include "Player.h"

Player::Player(char* name, const int maxHp, const int force)
{
    this->name = name;
    this->level = 1;
    this->coins = 0;
    this->force = force;
    this->maxHP = maxHp;
    this->HP = maxHp;
}

void Player::printInfo(){
    printPlayerInfo(name, level, force, HP, coins);
}

void Player::levelUp(){
    level++;
}

const int Player::getLevel(){
    return level;
}

void Player::buff(int i){
    force += i;
}

void Player::heal(int i){
    if((HP + i) >= maxHP){
        HP = maxHP;
        return;
    }
    if(i <= 0) return;
    HP += i;
}

void Player::damage(int i){
    if(HP <= i){
        HP = 0;
        return;
    }
    if(i <= 0) return;
    HP -= i;
}

bool Player::isKnockedOut(){
    return !(HP);
}

void Player::addCoins(int i){
    if(i <= 0) return;
    coins += i;
}

bool Player::pay(int i){
    if((i < 0) || coins < i) return false;
    coins -= i;
    return true;
}

int Player::getAttackStrength(){
    return (force + level); 
}
