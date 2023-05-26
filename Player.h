#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player {
public:
    /*
     * C'tor of the player:
     *
     * @param name - The name of the player.
     * @param maxHp - the maxHP of the player, defaulted to 100.
     * @param force - the force of the player, defaulted to 5.
     * @result
     *      An instance of Player
    */
    Player(const char* name, int maxHp = 100, int force = 5);

    /*
     * Copy C'tor of the player:
     *
     * @param otherPlayer - The player to be copied.
     * @result
     *      An instance of Player identical to the first.
    */
    Player(const Player& otherPlayer);

    /*
     *  prints the player's info:
     *  @return: void
     */
    void printInfo() const;

    /*
     *  levels up the player by 1, capping at MAX_LEVEL:
     *  @return: void
     */
    void levelUp();

    /*
     *  gets the level of the player:
     *  @return: int
     */
    int getLevel() const;

    /*
     *  buffs up the player's force by the given non-negative value:
     *  @return: void
     */
    void buff(const int i);

    /*
     *  heals up the player by the given non-negative value, capping at maxHP:
     *  @return: void
     */
    void heal(const int i);

    /*
     *  deducts the player's health by the given non-negative value, never going below 0:
     *  @return: void
     */
    void damage(const int i);

    /*
     *  checks if the player's health has reached 0:
     *  @return: void
     */
    bool isKnockedOut() const;

    /*
     *  adds to the player's coins by the given non-negative value:
     *  @return: void
     */
    void addCoins(const int i);

    /*
     *  deducts from to the player's coins by the given non-negative value if possible:

     *  possible deeduction = coins > value
     *  @return:
     *      true if deduction was possible, false if not
     */
    bool pay(const int i);

    /*
     *  gets the Attack Strength of the player, which is (Level + Force):
     *  @return: int
     */
    int getAttackStrength() const;
    
    /*
     * D'tor of the Player:
     *
     * @result
     *      the destruction of the Player
    */
    ~Player();

    static const int MAX_LEVEL = 10;

private:
    const char* m_name;
    int m_level;
    int m_force;
    const int m_maxHP;
    int m_HP;
    int m_coins;

};

#endif
