#include "card.h"

/*
 *  The constructor for the Card class.
 *  Fills the members of the Card based on the parameters
 *
 *  parameters:
 *      r - a value from the enumeration rank
 *      s - a suit from the enumeration suit
 *      ifu - a boolean tell us whether the card is face up or not
 */

Card::Card(rank r, suit s, bool ifu)
{
	m_Rank = r;
	m_Suit = s;
	m_IsFaceUp = ifu;
} 

/*
 * Return the blackjack numerical value of a card
 *
 * Parameters: None
 * Return:
 *      If the card is face down, return 0
 *      Otherwise follow this scheme:
 *      For an Ace, return 1
 *      For 2-9 return, return their value
 *      For 10, Jack, Queen, King return 10
 *
 */
int Card::GetValue() const
{
    if (m_IsFaceUp == false) {
    	return 0;
    }
  
    if (m_Rank > 10) {
    	return 10;
    }
    return m_Rank;
}

/*
 *  Flip the boolean.
 *  If the card was previously face down, now it is face up
 *  If the card was previously face up, now it is face down
 *
 *  Parameters: None
 *  Returns: None
 */
void Card::Flip()
{
	//std::cout << "in flip function: before flip: " << m_IsFaceUp << std::endl;
	m_IsFaceUp = !m_IsFaceUp;
	//std:: cout <<"in flip function : after flip :" << m_IsFaceUp << std:: endl;
}


/*
 * Overloads << operator so Card object can be sent to cout
 * If a card is face down, print "XX"
 * Otherwise print the rank followed by the suit
 *
 * Parameters:
 *      lefthand side: a reference to an output stream
 *      righthand side: a reference to the card we wish to print
 *
 * Returns:
 *      a reference to an output stream
 */
std::ostream& operator<<(std::ostream& os, const Card& aCard)
{
    if (aCard.m_IsFaceUp == false) {
    	os << "XX";

    }
    else {
    	os << aCard.m_Rank << " " << aCard.m_Suit;
    }

    return os;
}