
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include <ncurses.h>
#include "Player.hpp"


Player::Player() :
  AShip(100, 100, 100, 0, 1, 53)
{
  // std::cout << "Welcome to the Player !" << std::endl;
}

Player::Player(int x, int y) :
  AShip(100, 100, 100, 0, 1, 53)
{
  _posX = x;
  _posY = y;
  // std::cout << "Welcome to the Player !" << std::endl;
}

Player::Player(const Player& game) :
  AShip(game)
{
  *this = game;
}

Player::~Player() {

}

Player& Player::operator=(const Player& game) {
  (void)game;
  
  return *this;
}


void  Player::draw(int offsetX, int offsetY) {

  move(offsetY + _posY, offsetX + _posX);
  printw("A");
}
