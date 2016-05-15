#ifndef HAND_H
#define HAND_H

#include "card.h"
#include "common.h"

class Hand
{
public:
    Hand();
    
    // Don't forget we want to make the destructor virtual!
    virtual ~Hand();

    //adds a card to the hand
    void Add(Card* pCard);
 
    //clears hand of all cards
    void Clear();
 
    //gets hand total value, intelligently treats aces as 1 or 11
    int GetTotal() const;

protected:
    std::vector<Card*> m_Cards;
};


#endif