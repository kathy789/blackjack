#ifndef COMMON_H
#define COMMON_H
enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
               JACK, QUEEN, KING};
enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

/*  These are important files we will be using over and over.
    Instead of copying this to every cpp file, it is a good idea to put place them
    in a common header file which all cpp files may include.

    People commonly organize these in alphabetical order. When this list gets huge,
    it is much easier to search if a given library exists if everything is 
    alphabetized and sorted correctly.
*/
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>


#endif