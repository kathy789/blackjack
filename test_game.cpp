
#include "game.h"


int main () {

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





    return 0;
}