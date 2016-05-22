#ifndef PLAYER_H
#define PLAYER_H

#include "common.h"
#include "genericplayer.h"

class Player : public GenericPlayer
{
public:
    // Set the default name for a player to be ""
    Player(const std::string& name = "");

    virtual ~Player();

    //returns whether or not the player wants another hit       
    virtual bool IsHitting() const;

    //announces that the player wins
    void Win() const;

    //announces that the player loses
    void Lose() const;

    //announces that the player pushes
    void Push() const;
};


#endif