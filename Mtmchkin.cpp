#include "Mtmchkin.h"
#include <cstring>

// int Mtmchkin::curCard = 0;
// char* Mtmchkin::playerName = nullptr;  // Initialize to nullptr
// const Card* Mtmchkin::cardsArray = nullptr;
// Player Mtmchkin::player(playerName);
// int Mtmchkin::numOfCards = 0;

Card* createCardsArr(const Card* cardsArr, int n){
    Card* newArr = new Card[n];
    for (int i = 0; i < n; i++){
        newArr[i] = cardsArr[i];
    }
    return newArr;
}

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
:   m_player(playerName),
    m_cardsArray(createCardsArr(cardsArray, numOfCards)),
    m_numOfCards(numOfCards),
    m_curCard(0)
{}

Mtmchkin::Mtmchkin(Mtmchkin& otherMtmchkin)
:   m_player(otherMtmchkin.m_player),
    m_cardsArray(createCardsArr(otherMtmchkin.m_cardsArray, otherMtmchkin.m_numOfCards)),
    m_numOfCards(otherMtmchkin.m_numOfCards),
    m_curCard(0)
{}

void Mtmchkin::playNextCard(){
    const Card* card = m_cardsArray + (m_curCard % m_numOfCards); // card to play
    card->printInfo();
    card->applyEncounter(m_player);
    m_curCard++;
    m_player.printInfo();
}

bool Mtmchkin::isOver() const{
    if(m_player.isKnockedOut() || m_player.getLevel() == m_player.MAX_LEVEL)  return true;
    return false;
}


GameStatus Mtmchkin::getGameStatus() const{
    if(!isOver()) return  GameStatus::MidGame;

    if(m_player.isKnockedOut()){
        return GameStatus::Loss;
    } //else it has to be a Win
    return GameStatus::Win;
}

Mtmchkin::~Mtmchkin(){
    delete[] m_cardsArray;
}