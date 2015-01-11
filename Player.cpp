
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
#include <unistd.h>
#include "Player.hpp"
#include "BasicMissile.hpp"


Player::Player() :
  AShip(100, 100, 100, 0, -1, 53)
{
  _deceleration = 0.998;
  _acceleration = 0.08;
  _bounce = 0.4;
  _maxSpeed = 1.3;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

Player::Player(int x, int y) :
  AShip(100, 100, 100, 0, -1, 53)
{
  _posX = x;
  _posY = y;

  _deceleration = 0.998;
  _acceleration = 0.08;
  _bounce = 0.4;
  _maxSpeed = 1.3;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

Player::Player(const Player& player) :
  AShip(player)
{
  *this = player;
}

Player::~Player() {

}

Player& Player::operator=(const Player& player) {
  (void)player;
  
  return *this;
}


void  Player::draw() {
  int offsetX = (COLS - _world.getWidth()) / 2;
  int offsetY = (LINES - _world.getHeight()) / 2;

  move(offsetY + _posY, offsetX + _posX);
  printw("A");
}

void Player::bounce() {

}

void Player::collide() {

}

void  Player::shoot() {
  new BasicMissile(*this, 1.0f);
}

float abs(float a) {
  if (a < 0)
    return -a;
  return a;
}

void  Player::moveImpulsion(float x, float y) {
  _dirX += x;
  _dirY += y;

  _dirX = abs(_dirX) > _maxSpeed ? _dirX / abs(_dirX) * _maxSpeed : _dirX;
  _dirY = abs(_dirY) > _maxSpeed ? _dirY / abs(_dirY) * _maxSpeed : _dirY;
}
