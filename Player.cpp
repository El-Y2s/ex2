#include "Player.h"
#include "utilities.h"
#include <iostream>
#include <cstring>

// checks if the force Input is valid
// returns the force Input if valid, or the default force if not
int isValidForce(int forceIn){
    if(forceIn < 0) return 5;
    return forceIn;
}

// checks if the MaxHP Input is valid
// returns the MaxHP Input if valid, or the default MaxHP if not
int isValidMaxHP(int MaxHP){
    if(MaxHP <= 0) return 100;
    return MaxHP;
}

Player::Player(const char* otherName, int otherMaxHP, int otherForce)
    : m_name(new char[strlen(otherName) + 1]),
      m_level(1),
      m_force(isValidForce(otherForce)),
      m_maxHP(isValidMaxHP(otherMaxHP)),
      m_HP(m_maxHP),
      m_coins(0)
{
    strcpy(m_name, otherName);
}


Player::Player(const Player& otherPlayer)
:   m_name(strcpy(new char[strlen(otherPlayer.m_name+1)], otherPlayer.m_name)),
    m_level(1),
    m_force(isValidForce(otherPlayer.m_force)),
    m_maxHP(isValidMaxHP(otherPlayer.m_maxHP)),
    m_HP(m_maxHP),
    m_coins(0)
{}


void Player::printInfo() const{
    printPlayerInfo(m_name, m_level, m_force, m_HP, m_coins);
}

void Player::levelUp(){
    if(m_level == MAX_LEVEL) return;
    m_level++;
}

int Player::getLevel() const{
    return m_level;
}

void Player::buff(const int i){
    m_force += i;
}

void Player::heal(const int i){
    if(i <= 0) return;
    if((m_HP + i) >= m_maxHP){
        m_HP = m_maxHP;
        return;
    }
    m_HP += i;
}

void Player::damage(const int i){
    if(i <= 0) return;
    if(m_HP <= i){
        m_HP = 0;
        return;
    }
    m_HP -= i;
}

bool Player::isKnockedOut() const{
    return !(m_HP);
}

void Player::addCoins(const int i){
    m_coins += i;
}

bool Player::pay(const int i){
    if(m_coins < i) return false;
    m_coins -= i;
    return true;
}

int Player::getAttackStrength() const{
    return (m_force + m_level); 
}

Player::~Player(){
    delete[] m_name;
}