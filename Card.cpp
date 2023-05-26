#include "Card.h"
#include "utilities.h"


// constructor for the Card class - initializes all of its member values
Card::Card(CardType type, const CardStats& stats) : m_effect(type), m_stats(stats) {}

// Handling the player's applyEncounter with the card of any type
void Card::applyEncounter(Player& player) const {
    switch (m_effect){
        case CardType::Battle:
            if(player.getAttackStrength() >= m_stats.force){ // win (playerF >= cardF)
                player.levelUp();
                player.addCoins(m_stats.loot);
            } else{ // lose
                player.damage(m_stats.hpLossOnDefeat);
            }
            printBattleResult(player.getAttackStrength() >= m_stats.force); // argument finds if win or lose
            break;
        case CardType::Buff:
            if(player.pay(m_stats.cost)){
                player.buff(m_stats.buff);
            }
            break;
        case CardType::Heal:
            if(player.pay(m_stats.cost)){
                player.heal(m_stats.heal);
            }
            break;
        case CardType::Treasure:
            player.addCoins(m_stats.loot);
            break;
        default:
            // Handle unknown card type - do nothing (cannot happen due to enum)
            break;
    }
}

void Card::printInfo() const {
    switch (m_effect){
        case CardType::Battle:
            printBattleCardInfo(m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(m_stats);
            break;
        default:
            // Handle unknown card type - do nothing (cannot happen due to enum)
            break;
    }
}

