
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

#include "BasicMissile.hpp"

Player::Player() :
  AShip(100, 100, 100, 0, 1, 53)
{

}

Player::Player(int x, int y) :
  AShip(100, 100, 100, 0, 1, 53)
{
  _posX = x;
  _posY = y;
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


void  Player::shoot() {
  new BasicMissile(*this, 1.0f);
}

void  Player::refreshPhysics() {
  _posX += _dirX / 3;
  _posY += _dirY / 3;

  _dirX *= 0.98;
  _dirY *= 0.98;

  if (_posX <= 1) {
    _posX = 1;
    _dirX = -_dirX * 2 / 3;
  }
  else if (_posX >= _world.getWidth()) {
    _posX = _world.getWidth();
    _dirX = -_dirX * 2 / 3;
  }

  _posY = _posY > _world.getHeight() ? _world.getHeight() - 1 : _posY;
  _posY = _posY < 1 ? 1 : _posY;
}

void  Player::moveImpulsion(float x, float y) {
  _dirX += x;
  _dirY += y;

  _dirX = _dirX > 4 ? 4 : _dirX;
  _dirY = _dirY > 4 ? 4 : _dirY;
}

void  Player::draw() {
  int offsetX = (COLS - _world.getWidth()) / 2;
  int offsetY = (LINES - _world.getHeight()) / 2;

  move(offsetY + _posY, offsetX + _posX);
  printw("A");
}
