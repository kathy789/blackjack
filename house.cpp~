#include "house.h"

/*
 * The Constructor for the House class
 * Call the super constructor with the given name
 *
 * Parameters: A reference to a std::string name
 */
House::House(const std::string& name) : GenericPlayer(name)
{}

/*
 * The destructor for the House object
 */
House::~House()
{}

/*
 * The Artificial intelligence for our computer player
 * Feel free to make this method as complex as you wish.
 * If you want to be as simple as possible, hit when you have <= 16 as your points
 *
 * You should return true whenever you think it would be a good time to ask for a card.
 * ALWAYS make AI methods modular so you can change parts as much as you wish.
 * AI can be done in different ways (Finite State Machines) or rules. Look up card counting
 * for a good blackjack AI idea.
 *
 * Parameters: None
 * Returns: ????? (up to you) a boolean whenever it wishes to draw a card
 */
bool House::IsHitting() const
{
     if (GetTotal() <= 16) {
             return true;  
     }
     return false;
}   

/*
 * Because the House always has their first card face down, we want a method to flip the first card
 * If the hand is empty simply print "No card to flip!\n" and return.
 * Otherwise flip the first card of the House's hand.
 *
 * Parameters: None
 * Returns: None
 */
void House::FlipFirstCard()
{
   if (m_Cards.size() == 0 ) {

         std::cout << "No card to flip!\n";
   }
   else {
         m_Cards[0] -> Flip();    

   }
      

}
