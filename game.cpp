//Blackjack
//Plays a simple version of the casino game of blackjack; for 1 - 7 players"
/*

  1) destructor : Is it necessary to call clear() ? Answer : NO.
 
*/
#include "game.h"

/*
 * The constructor for a Blackjack game.
 * We must create a player for every player name given to us in the parameter std::vector
 * It must also populate the deck and shuffle the cards
 *
 * Parameters: A reference to a std::vector filled with names of the players
 */
Game::Game(const std::vector<std::string>& names)
{
   m_Players.reserve(7);
 
  std::vector<std::string>::const_iterator it;  // use const_iterator not iterator, since names is a const reference 
  for ( it = names.begin(); it != names.end() ; ++it) {   // in this case, no difference between ++it and it++, but there is 
                                                          //difference between  y = ++x and y = x++
  // for (unsigned int i = 0 ; i < names.size(); i++) {
                 m_Players.push_back(Player(*it));
             //  m_Players.push_back(Player(names[i]));
   
   }
  
   m_Deck.Shuffle();
   //m_Deck.print();


}

/*
 * The destructor for the blackjack game.
 */
Game::~Game()
{
   //m_Players.clear(); // Clear() : remove all the elements in the vector, but the vector object still exists.
   // will it be automatically cleared ? Yes. It will automatically destroys all the elements in the vector destructor.     
}

/*
 * All of the logic to play the blackjack game. You will need to follow the rules here.
 *
 * Start by dealing out a card to every player and then dealing a card to the House.
 * For a second time deal a card to every player and then deal a card to the House.
 * Make sure the first card of the House is flipped.
 *
 * Display every player's hand so they know what they have followed by the House's hand
 *
 * Deal additional cards to every player in order
 *
 * Flip the House's first card and print the hand of the House.
 *
 * Deal additional cards to the House. Then Check the win conditions
 *
 * If the house is busted, for every player which has not currently busted, announce
 * to them that they have won
 *
 * If the House did not bust we must check to see who won
 *
 * For every player, if they have not busted, check:
 * 1. If their total is greater than the house's total. Annouce that they've won.
 * 2. If their total is equal to the house's total. Annouce that they have pushed.
 * 3. Otherwise annouce that the player has lost.
 *
 * At the end, Make sure to clear the hands of each Player and the House.
 *
 * Parameters: None
 * Returns: None
 */
void Game::Play()
{ 
     //deal the first two cards to each player and the house
    unsigned int i; 
    std::vector<Player>::iterator it;
    for (i = 0 ; i < 2; i ++ ) {
         for (it = m_Players.begin(); it != m_Players.end(); it++) {
                 
		m_Deck.Deal(*it);	          
    
         }
       
         m_Deck.Deal(m_House);
         
    }
    m_House.FlipFirstCard(); // make sure the first card faced down
    // display every one's hand
    for (it = m_Players.begin(); it != m_Players.end(); it++) {
                 
		std::cout << *it << "\n";	          
    
    }
    std::cout << m_House << "\n";
    //Deal additional cards to each player and the house
    for (i = 0 ; i < m_Players.size() ; i ++) {
           while(m_Players[i].IsBusted() == false && m_Players[i].IsHitting() == true){

                  m_Deck.AdditionalCards(m_Players[i]);   // will "somebody bust " be printed before printting hand ?  Yes.
                  

           } 
           
    
    }
    m_House.FlipFirstCard(); // make sure flip the first card up
    while(m_House.IsBusted() == false && m_House.IsHitting() == true) {

                  m_Deck.AdditionalCards(m_House);
     
     } 
    
    
    // check win conditions   
    if (m_House.IsBusted()) {
         for (i = 0 ; i < m_Players.size(); i ++ ) {

               if (!m_Players[i].IsBusted()) {
                       m_Players[i].Win();
               }  
        }    
    }
    else {
         for (i = 0 ; i < m_Players.size(); i ++ ) {

               if (!m_Players[i].IsBusted() && m_Players[i].GetTotal() > m_House.GetTotal()) {
                       m_Players[i].Win();
               }  
               if (!m_Players[i].IsBusted() && m_Players[i].GetTotal() < m_House.GetTotal()) {
                       m_Players[i].Lose();
               }
               if (!m_Players[i].IsBusted() && m_Players[i].GetTotal()  == m_House.GetTotal()) {
                       m_Players[i].Push();
               }  
        }    

    } 

    // clear the hands of each player and the house. // It is  very easy to forget and igore. Because the m_deck.clear() method in the deck deconstrcutor will only clear the remaining elements in the deck. 
       for (i = 0 ; i < m_Players.size(); i ++ ) {

                m_Players[i].Clear();
        } 
        m_House.Clear(); 

}

