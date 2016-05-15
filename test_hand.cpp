#include "common.h"
#include "hand.h"
/*
 * we have test cases:
 * 1) 9 ,8       // points: 17
 * 2) 9, 8, Ace  // points : 18
 * 3) 9, Ace    // points: 20
 * 4) 9, Ace, Ace   // points : 21
*/
int main () {
      Hand hand;
      Card card1(NINE, SPADES, true);
      Card card2(ACE, HEARTS, true);
      Card card3(ACE, HEARTS, true);
      hand.Add(&card1);
      hand.Add(&card2);
      hand.Add(&card3);
      std:: cout << "hand total: " << hand.GetTotal() << std:: endl;
      hand.Clear();
      return 0;


}