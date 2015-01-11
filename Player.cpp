
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


void  Player::refreshPhysics() {

  _posX += _dirX / 3;
  _posY += _dirY / 3;

  // std::max();

  _dirX *= 0.99;
  _dirY *= 0.99;
}

void  Player::moveImpulsion(float x, float y) {
  _dirX += x;
  _dirY += y;

  _dirX = _dirX > 4 ? 4 : _dirX;
  _dirY = _dirY > 4 ? 4 : _dirY;
}

void  Player::draw(int offsetX, int offsetY) {

  move(offsetY + _posY, offsetX + _posX);
  printw("A");
}
