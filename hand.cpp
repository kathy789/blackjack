#include "hand.h"
/*
 *difference between my code and solution:
 *1) constructor and destructor. They have something and we do not. In destructor, Do not understand why it is no different with or without Clear()
 *2) Add() method: we forgot to check nullptr;
 *3) Clear method: After deleter the pointers, they set the pointer to null. (dereference it to 0) It is good practice to set dangling ptr to NUll.
 *4) GetTotal() method: the solution has more clear logic : add everything up and check whether we need treat Ace as 11.
*/
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
{ 
 // Clear()  // no difference 
}

/*
 * Add a card to your hand
 *
 * Parameters: A card pointer for a card we wish to add to our hand
 * Returns: None
 */
void Hand::Add(Card* pCard)
{
   if (pCard != NULL) { // Do not forget to check null pointer!
      m_Cards.push_back(pCard);
   }
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

		delete(m_Cards[i]);  // is it necessary? Yes. Because in the deck.cpp they will creat Card pointers and add them in Deck. 
                                     // Then Deal the card pointers to players and house.
	        m_Cards[i] = 0;
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
		
		else {
			sum += m_Cards[i] ->GetValue();
                }
                if (sum > 21 && flag == true) {
			sum -= 10;
		}
	}

      return sum;
}
