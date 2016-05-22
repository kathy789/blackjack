#include "card.h"
#include "hand.h"
#include "deck.h"
#include "player.h"
#include "house.h"

int main () {
    std::string output("nisha:\n");
    std::cout << output<< std::endl;
    
    
    Deck deck1;
    //deck1.print();
    deck1.Shuffle();
    std::cout << "after shuffle :" << std::endl;
    deck1.print();
    Hand hand1;
    deck1.Deal(hand1);
    std::cout << "hand1 total: after deal once :" << hand1.GetTotal() << std::endl;
    deck1.Deal(hand1); 
    std::cout << "hand1 total: after deal twice : " << hand1.GetTotal() << std::endl;
    Player gplayer1("Nisha");
    deck1.Deal(gplayer1);
    std::cout << "gplayer1 total: after deal once :" << gplayer1.GetTotal() << std::endl;
    deck1.Deal(gplayer1);
    std::cout << "gplayer1 total: after deal twice: " << gplayer1.GetTotal() << std::endl;
  
    std::cout << gplayer1 << std::endl;
   
   if(gplayer1.IsHitting()) {

        deck1.AdditionalCards(gplayer1);
   }
   
   if (gplayer1.IsBusted() ) {
        
        gplayer1.Bust();
   }  
   gplayer1.Win();
   gplayer1.Lose();
   gplayer1.Push();
   // test house
   std::cout << "test house \n"; 
   House house;
   //deck1.m_Cards.back() -> Flip();  // error:m_Cards is protected // how to solve the problem of making the first card face down 
  // My first thoughts are flipping the card down inside or outside of Hand::Deal method. Outside of the method means in game.cpp or main. 
   deck1.Deal(house);  
  // house.FlipFirstCard();  // From the design given, the house himslef flip the card down and then later flip the card up.
   deck1.Deal(house);
   std::cout << "the first card is face down, house total: " << house.GetTotal() << "\n";
   house.FlipFirstCard();
   std::cout << "the first card is face up, house total: " << house.GetTotal() << "\n"; 
    return 0;
}
