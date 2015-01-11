
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include "Player.hpp"

Player::Player() : AShip(100, 100, 100, 0, 1, 53)
{
  std::cout << "Welcome to the Player !" << std::endl;
}

Player::Player(const Player& game) : AShip(game)
{
  *this = game;
}

Player::~Player() {

}

Player& Player::operator=(const Player& game) {
  (void)game;
  
  return *this;
}

