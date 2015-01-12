
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
  _acceleration = 0.001 + (float)(Game::getInstance()->getElapsedTime()) / 100000000;
  _deceleration = 1.00001 + (float)(Game::getInstance()->getElapsedTime()) / 100000000;
  _skin = ACS_DARROW;

  _bounce = 0.4;
  _maxSpeed = 0.1;
  _lastShootTimestamp = 0;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

BasicEnemy::BasicEnemy(const BasicEnemy& game) :
  AEnemy(game)
{
  *this = game;

  _dirX = 0;
  _dirY = 1;
  _acceleration = 0.001 + (float)(Game::getInstance()->getElapsedTime()) / 10000000;
  _deceleration = 1.00001 + (float)(Game::getInstance()->getElapsedTime()) / 10000000;
  _skin = ACS_DARROW;

  _bounce = 0.4;
  _maxSpeed = 0.1;
  _lastShootTimestamp = 0;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

BasicEnemy::~BasicEnemy() {

}

BasicEnemy& BasicEnemy::operator=(const BasicEnemy& game) {
  (void)game;
  
  return *this;
}



void  BasicEnemy::think() {
  if (Game::getInstance()->getElapsedTime() - _lastShootTimestamp > 1000) {
    _lastShootTimestamp = Game::getInstance()->getElapsedTime();
    shoot();
  }
}

void  BasicEnemy::draw() {
  int offsetX = (COLS - _world.getWidth()) / 2;
  int offsetY = (LINES - _world.getHeight()) / 2;

  attron(COLOR_PAIR(2));
  move(offsetY + _posY, offsetX + _posX);
  addch(_skin);
  attroff(COLOR_PAIR(2));
}

void BasicEnemy::bounce() {
  _world.setEntityAt((int)_posX, (int)_posY, NULL);
  delete this;
}

void BasicEnemy::collide() {
  Game::getInstance()->updateScore(100);
  _world.setEntityAt((int)_posX, (int)_posY, NULL);
  delete this;
}

void  BasicEnemy::shoot() {
  new BasicMissile(*this, 1.0f, 0.0f, 0.0f, 0.0f, +0.1f);
}
