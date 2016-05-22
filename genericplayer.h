#ifndef GENERIC_PLAYER_H
#define GENERIC_PLAYER_H

#include "common.h"
#include "hand.h"

class GenericPlayer : public Hand
{
    // Overloading the << operator in order to easily print our object
    friend std::ostream& operator<<(std::ostream& os, const GenericPlayer& aGenericPlayer);

public:
    // Set the default name for our GenericPlayer to be ""
    GenericPlayer(const std::string& name = "");
    
    virtual ~GenericPlayer();

    //indicates whether or not generic player wants to keep hitting
    virtual bool IsHitting() const = 0;

    //returns whether generic player has busted - has a total greater than 21
    bool IsBusted() const;

    //announces that the generic player busts
    void Bust() const;

protected:
    // All GenericPlayers must have a name!
    std::string m_Name;
};

#endif
