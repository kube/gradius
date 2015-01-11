
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

Player::Player() : AShip()
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

