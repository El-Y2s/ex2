#include "Player.h"

void Player::printInfo(){
    printPlayerInfo(this->name, this->level, this->force, this->HP, this->coins);
}

void Player::levelUp(){
    this->level++;
}

const int Player::getLevel(){
    return this->level;
}

void Player::buff(int i){
    this->force += i;
}

void Player::heal(int i){
    if((this->HP + i) >= this->maxHP){
        this->HP = this->maxHP;
        return;
    }
    if(i <= 0) return;
    this->HP += i;
}

void Player::damage(int i){
    if(this->HP <= i){
        this->HP = 0;
        return;
    }
    if(i <= 0) return;
    this->HP -= i;
}

bool Player::isKnockedOut(){
    return !(this->HP);
}

void Player::addCoins(int i){
    if(i <= 0) return;
    this->coins += i;
}

bool Player::pay(int i){
    if((i < 0) || this->coins < i) return false;
    this->coins -= i;
    return true;
}

int Player::getAttackStrength(){
    return (this->force + this->level); 
}
