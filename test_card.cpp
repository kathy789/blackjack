#include "common.h"
#include "card.h"
//extern suit {CLUBS, DIAMONDS, HEARTS, SPADES};
//extern rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               //JACK, QUEEN, KING};
int main () {
	int * ptr;
	ptr = new int(7); // the compiler will throw an error: ptr not initialized yet
	std:: cout << *ptr << std::endl;
    Card cards[3]; // it will call the user defined default constructor three times
    cards[0] = Card(NINE, DIAMONDS, true); // create a new Card and copy it to cards[0]  // does the compiler
 // has a default assignment operator? Yes. The compiler creates its own default copy constructor and assignment operator
// for every class if it does not have user defined copy constructor and assignment operator.


    cards[1] = Card(EIGHT, HEARTS, false); // cards[2] will use the user defined default constructor
    
    
    int i;
    for (i = 0 ; i < 3; i ++) {
    	//std::cout << cards[1].GetValue() << std::endl;
    	std::cout << "before flip" << "\n"
                  << cards[i] << std::endl;
    	cards[i].Flip();
    	std:: cout << "after flip" << "\n"
    	           << cards[i] <<std::endl;
    	//std::cout << cards[1].GetValue() << std::endl;
    }


	return 0;
}