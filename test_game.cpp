
#include "game.h"


int main () {
    /*
    bool test1 = 'N'; 
    bool test2 = 'y';
    std::cout << "N: " << test1 << " y: "<< test2 << std::endl; // output: N: 1 y: 1
    test = 'N' or 'y' ; // keyword or in C++ mean logical operator ||, so test = true.
    */
    char res;
    do {
	    std::cout << "welcome to play blackjack game\n";
	    std::cout << "How many player want to play?";
	    int num_players;
	    std::cin >> num_players;
	    std::vector<std::string> names;
	    std::string name;
	    for (int i = 0; i < num_players; i++ ) {

		  std::cout << "Enter player's name : " ;
		  std::cin >> name;
		  names.push_back(name);

	   } 
	     
	   Game game(names);
	   game.Play();
           //flag = false;
	   std::cout<< "do you want to play again? (Y or N) ";
	   std::cin >> res;
           std::cout << "res : " << res << "\n";
   }while(res == 'Y' or res =='y');
 

    return 0;
}
