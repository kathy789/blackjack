#include "player.h"

/*
 * The Player constructor.
 * 
 * Call the super constructor with the given name
 */
Player::Player(const std::string& name) : GenericPlayer(name)  // without specifying the super class constuctor, it will call the default
                                                               // constructor of the super class
{
   //std::cout << "player constructor is called" << std::endl;
}

/*
 * Player destructor
 */
Player::~Player()
{}
    
/*
 * Prompt the player whether they wish to hit with the message
 * "<name>, do you want a hit? (Y/N): "
 * Use the standard input to record their answer.
 *
 * Parameters: None
 * Returns:
 *      true if the answer was 'y' or 'Y'
 *      false otherwise
 *
 * Teaching moment:
 * There are multiple ways to handle this situation of taking input from a user.
 * We can have a few correct responses and a default answer "That's not a valid answer"
 * or we can use what is called a fail-safe default. That is to say if the answer is neither
 * 'y' or 'Y' we assume the answer is actually "No". Neither approach is really wrong.
 *
 * On the other hand, the one wrong answer would be to allow access or grant the request
 * for a "garbage" value. That is to say, we should not return true for the value 'x'.
 * This is usually seen as a security flaw. Get in the habit of only approving "positive"
 * matches and rejecting anything which does not match.
 */
bool Player::IsHitting() const
{
    char res;
    std::cout << m_Name << ", do you want a hit? (Y/N): " ;
    std::cin >> res;
    std::cout << std::endl;	 
    if (res == 'y' or  res == 'Y') {

            return true;
    }

    return false;
}

/*
 * Announce to the player that they have won. Use the message:
 * "<name> wins.\n"
 *
 * Parameters: None
 * Returns: None
 */
void Player::Win() const
{
   std::cout << m_Name << " wins.\n";

}

/*
 * Announce to the player that they have lost. Use the message:
 * "<name> loses.\n"
 *
 * Parameters: None
 * Returns: None
 */
void Player::Lose() const
{
   std::cout << m_Name << " loses.\n"; 
}

/*
 * Announce to the player that they have pushed (tied). Use the message:
 * "<name> pushes.\n"
 *
 * Parameters: None
 * Returns: None
 */
void Player::Push() const
{
    std::cout << m_Name << " pushes.\n";

}
