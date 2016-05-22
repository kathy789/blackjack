#ifndef HOUSE_H
#define HOUSE_H

#include "common.h"
#include "genericplayer.h"

class House : public GenericPlayer
{
public:
    // Set the default name of a House object to be "House"
    House(const std::string& name = "House");

    virtual ~House();

    //indicates whether house is hitting - will always hit on 16 or less
    virtual bool IsHitting() const;

    //flips over first card
    void FlipFirstCard();
};


#endif