
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
#include "BasicEnemy.hpp"
#include "BasicMissile.hpp"

#include "Game.hpp"

BasicEnemy::BasicEnemy(int x, int y) :
  AEnemy(x, y)
{
  _posX = x;
  _posY = y;

  _dirX = 0.2;
  _dirY = 1;
  _acceleration = 0.001;
  _deceleration = 1.00001;
  _skin = ACS_DARROW;

  _bounce = 0.4;
  _maxSpeed = 0.1;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

BasicEnemy::BasicEnemy(const BasicEnemy& game) :
  AEnemy(game)
{
  *this = game;

  _dirX = 0;
  _dirY = 1;
  _acceleration = 0.001;
  _deceleration = 1.0001;
  _skin = ACS_DARROW;

  _bounce = 0.4;
  _maxSpeed = 0.1;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

BasicEnemy::~BasicEnemy() {

}

BasicEnemy& BasicEnemy::operator=(const BasicEnemy& game) {
  (void)game;
  
  return *this;
}


void  BasicEnemy::draw() {
  int offsetX = (COLS - _world.getWidth()) / 2;
  int offsetY = (LINES - _world.getHeight()) / 2;

  move(offsetY + _posY, offsetX + _posX);
  addch(_skin);
}

void BasicEnemy::bounce() {
  _world.setEntityAt((int)_posX, (int)_posY, NULL);
  delete this;
}

void BasicEnemy::collide() {
  _world.setEntityAt((int)_posX, (int)_posY, NULL);
  delete this;
}

void  BasicEnemy::shoot() {
  new BasicMissile(*this, 1.0f);
}