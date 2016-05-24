
all: main test_deck
main: card.cpp hand.cpp deck.cpp genericplayer.cpp player.cpp house.cpp game.cpp main.cpp 
	g++ -std=c++11 -Wall -Werror -g card.cpp hand.cpp deck.cpp genericplayer.cpp player.cpp house.cpp game.cpp main.cpp -o main
test_deck: card.cpp hand.cpp deck.cpp genericplayer.cpp player.cpp house.cpp test_deck.cpp 
	g++ -Wall -Werror -g  card.cpp hand.cpp deck.cpp genericplayer.cpp player.cpp house.cpp test_deck.cpp -o test_deck
clear:
	rm -f main test_deck
