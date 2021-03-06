#include "main.h"
/*
  difference between my code and solution : solution check whether num_players is in the range of 1 and 7 by while loop
   Final question: design ptr to card , virtual function, iterator
*/
 
/*
 * This is your main title screen for your game
 *
 * Start by setting up the seed for your random number generator
 * Print a message to your players that they are playing your game!
 * Find out how many players wish to play (between [1, 7])
 *
 * Use the standard input to find out their names then create a blackjack game
 * Create some loop logic such that we can play the game over and over again
 * so long as the players say they wish to play again.
 */
int main()
{
    
   
    srand(time(0));
    char res;
    std::cout << "welcome to play blackjack game\n";
    int num_players = 0; // it has to be out of the range, then it can goes into the loop.
    while (num_players < 1 || num_players > 7) {
	    std::cout << "How many player want to play?";

	    
	    std::cin >> num_players;
            if (num_players < 1 || num_players > 7) {

                   std::cout << "Number of players is in the range of [1, 7]\n";
            }
    }
    std::vector<std::string> names;
    std::string name;
   for (int i = 0; i < num_players; i++ ) {

       std::cout << "Enter player's name : " ;
       std::cin >> name;
       names.push_back(name);
   } 
		     
   Game game(names);

   do {
	    
	   game.Play();
          
	   std::cout<< "do you want to play again? (Y or N) ";
	   std::cin >> res;
           std::cout << "res : " << res << "\n";
   }while(res == 'Y' or res =='y');
   std::cout << "Thank you so much for playing our game!\n";
    
   return 0;
}
