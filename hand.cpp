#include "hand.h"

/*
 * Constructor for the Hand class
 */
Hand::Hand()
{}

/*
 * Destructor for the Hand class.
 *
 * REMEMBER every class that inherits from Hand will call this method
 */
Hand::~Hand()  
{}

/*
 * Add a card to your hand
 *
 * Parameters: A card pointer for a card we wish to add to our hand
 * Returns: None
 */
void Hand::Add(Card* pCard)
{}
 
/*
 * Cleans up all of the cards in our Hand.
 * This function must also delete all of the memory taken up by the cards
 *
 * Parameters: None
 * Returns: None
 */
void Hand::Clear()
{}

/*
 * Get the total points for our hand. Add up the points for each card
 * 
 * Parameters: none
 * Returns:
 *      If the hand is empty, return 0
 *      If one of the cards in the hand is face down, return 0
 *      Otherwise return the total value of all the cards in the hand.
 *      If one of the cards is an ACE and the total of the hand would be 21 or lower,
 *      treat the Ace as value 11 instead of 1.
 */
int Hand::GetTotal() const
{
    return 0;
}