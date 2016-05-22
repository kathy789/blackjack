#ifndef DECK_H
#define DECK_H

#include "common.h"
#include "genericplayer.h"
#include "hand.h"
#include "player.h"
#include "house.h"


class Deck : public Hand
{
public:
    Deck();
    
    virtual ~Deck();
    void print(); // add it by myself
    //create a standard deck of 52 cards
    void Populate();

    //shuffle cards
    void Shuffle();

    //deal one card to a hand
    void Deal(Hand& aHand);

    //give additional cards to a generic player 
    void AdditionalCards(GenericPlayer& aGenericPlayer);
};

#endif
