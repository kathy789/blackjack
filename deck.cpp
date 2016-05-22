#include "deck.h"
/*
 *notes:
 * 1) AdditionalCards() method: for now I think we implement the requirement of additional deal in game class.

 */
void Deck::print() {
   unsigned int i;
   if (m_Cards.size() == 0 ) {
        std::cout << "m_Cards is empty" << std::endl;
        return;
   }
   for (i = 0 ; i < m_Cards.size(); i++) {
         std::cout << *(m_Cards[i]) << std::endl;

   }
  



}
/*
 * Constructor for the Deck class
 * Populates the deck with all 52 distinct cards
 *
 * Parameters: None
 */
Deck::Deck()
{
  
      this->Populate();              
  
}

/*
 * Destructor for the Deck. Don't forget the destructor for Hand will be called after this.
 */
Deck::~Deck()
{
      this->Clear(); 


 }


/*
 * If there were previously cards in the deck, get rid of them
 * Allocates space for all 52 cards and adds them to the deck
 *
 * Parameters: None
 * Returns: None
 */
void Deck::Populate()
{
    if(m_Cards.size() > 0 ) {
        this ->Clear();  
    } 
    m_Cards.reserve(52);
    
    int i, j;
    for ( i = 0 ; i < 4; i ++ ){
 	for (j = 1; j < 14; j ++) {  

               //this ->Add(new Card(rank(j), suit(i)));  // if we do not use new 
               // and use &, the complier will complain returning temporary address.
               Add(new Card((rank) j, (suit) i ));   // same output as above
        }

     }         
    
    /*
     for (suit s = CLUBS; s <= SPADES; ++ (static_cast<unsigned int> (s)) ){  // the complier complain "lvalue required as increment operand"
	   for (rank r = ACE; r <= KING; ++(static_cast<unsigned int> (r)) ){  // same error as above
 
                  Add(new Card(r, s));
   
          }

     }
   */    

}

/*
 * Shuffles all of the cards in the deck
 * Hint: If you get stuck, go read up on lesson 3 algorithm to learn about the standard library
 *
 * Parameters: None
 * Returns: None
 */
void Deck::Shuffle()
{
    srand(time(0));
    random_shuffle(m_Cards.begin(), m_Cards.end());
    

}

/*
 * Deal one card from the deck to a Hand. If the deck has no cards remaining print out
 * "Out of cards. Unable to deal."
 *
 * Parameters: A reference to a Hand object
 * Returns: None
 */
bool flag = false; // this flag is used to indicate whether the first card has face down for house
 // this flag has to be global variable. If it is local, it will flip every cards of house to face down.
void Deck::Deal(Hand& aHand)
{   
    // how to know whether aHand is house or player ? after the below test : dynamic_cast<Type >  works.
    Hand * anoHand = &aHand;
    /*
    Player* player = dynamic_cast<Player*> (anoHand);
    if (player != NULL) {

         player-> Win();
         std::cout << "I am a player \n";
    }
    House* house = dynamic_cast<House*>(anoHand);
    if (house != NULL) {
         std::cout <<"house is hitting or not : " << house ->IsHitting() << "\n";
    }
   */
    //int num = aHand.m_Cards.size();  // compilation error: Hand::m_Cards is protected 
     
    if (m_Cards.size() > 0 ) {
        
         House * house2 = dynamic_cast<House*> (anoHand);
         if (house2 != NULL && flag == false) {
                m_Cards.back()-> Flip(); 
                flag = true;      
                
          }
          aHand.Add(m_Cards.back());  // we could not write "aHand.Add(m_Cards.end());" // because m_Cards.end() return an interator, not an   element or element reference
          m_Cards.pop_back();
         //std::cout << "newly added in hand: " << *(aHand.m_Cards[num-1]) <<std::endl; //  compilation error: Hand::m_Cards is protected 
    }
    else {
          std::cout<< "Out of cards. Unable to deal" << std::endl;
    }
}


/*
 * Deal out any additional cards to a player beyond the first two cards.
 * A player can only be dealt extra cards if:
 * 1.) They have not busted yet
 * 2.) They wish to be hit
 *
 * After a card is dealt, print out the current hand so the player can keep making the decision
 * whether to stay or hit
 * If a player busts, let the player know they have busted
 *
 * Parameter: A reference to a Generic Player
 * Returns: None
 */

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
    
    Deal(aGenericPlayer);
    std::cout << " after additional deal total points for now: " <<  aGenericPlayer.GetTotal() << std::endl;   // we need to print out the hand ?
     
    if(aGenericPlayer.IsBusted() ) {
           aGenericPlayer.Bust();
    } 
    

} 

