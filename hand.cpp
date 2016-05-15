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
{
   m_Cards.push_back(pCard);
}
 
/*
 * Cleans up all of the cards in our Hand.
 * This function must also delete all of the memory taken up by the cards
 *
 * Parameters: None
 * Returns: None
 */
void Hand::Clear()
{
	unsigned int i;
	for (i = 0 ; i < m_Cards.size(); i ++ ) {

		delete(m_Cards[i]);
	}
	m_Cards.clear();
}

/*
 * Get the total points for our hand. Add up the points for each card
 * 
 * Parameters: none
 * Returns:
 *      If the hand is empty, return 0
 *      If one of the cards in the hand is face down, return 0  // the house does not calculate points until he flip the first card
 *      Otherwise return the total value of all the cards in the hand.
 *      If one of the cards is an ACE and the total of the hand would be 21 or lower,
 *      treat the Ace as value 11 instead of 1. // which case treat Ace as 11, which case treat Ace as 1
 */
int Hand::GetTotal() const
{
	if (m_Cards.size() == 0) {
		return 0;
	}
	unsigned int i;
	unsigned int sum = 0; 
	bool flag = false; // is it possible to treat Ace as 11 twice ? No. because twice will be at least 22.
	                     // we want AA stands for 12 points, not 22 points. so we use flag instead of count.
	for (i = 0 ; i < m_Cards.size() ; i ++) {
		if (m_Cards[i] -> GetValue() == 0) {
			return 0;
		}
		if (m_Cards[i] ->GetValue() == 1 && sum <= 10) {
			sum += 11;
			flag = true;
		} 
		else if (sum >= 21 && flag == true) {
			sum -= 10;
		}
		else {
			sum += m_Cards[i] ->GetValue();
        }
	}

    return sum;
}