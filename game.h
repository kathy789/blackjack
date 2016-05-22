#ifndef GAME_H
#define GAME_H

#include "common.h"
#include "deck.h"
#include "genericplayer.h"
#include "house.h"
#include "player.h"


class Game
{
public:
    // The constructor of a blackjack game takes a set of names
    Game(const std::vector<std::string>& names);
    
    ~Game();
    
    //plays the game of blackjack    
    void Play();

private:
    /* Every blackjack game has:
     * 1. A deck of cards
     * 2. A House to deal cards
     * 3. A list of players
     */
    Deck m_Deck;
    House m_House;
    std::vector<Player> m_Players;  
};

#endif