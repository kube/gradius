
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
#include "BasicMissile.hpp"
#include "AShip.hpp"
#include "World.hpp"

#include "Game.hpp"

BasicMissile::BasicMissile(const AShip& sender, float power) :
  AMissile(sender, power)
{
  _deceleration = 1.0001;
  _acceleration = 0.1;
  _bounce = 0.0;
  _maxSpeed = 0.7;
  _skin = ACS_BULLET;

  _posX = _sender.getPosX() + _sender.getShootX();
  _posY = _sender.getPosY() + _sender.getShootY();

  _dirX = _sender.getShootX() * power * _acceleration;
  _dirY = _sender.getShootY() * power * _acceleration;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

BasicMissile::BasicMissile(const AShip& sender, float power,
              float offsetX, float offsetY, float dirX, float dirY) :
  AMissile(sender, power)
{
  _deceleration = 1.0001;
  _acceleration = 0.1;
  _bounce = 0.0;
  _maxSpeed = 0.7;
  _skin = ACS_BULLET;

  _posX = _sender.getPosX() + _sender.getShootX() + offsetX;
  _posY = _sender.getPosY() + _sender.getShootY() + offsetY;

  _dirX = (_sender.getShootX() + dirX) * power * _acceleration;
  _dirY = (_sender.getShootY() + dirY) * power * _acceleration;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

BasicMissile& BasicMissile::operator=(const BasicMissile& missile) {
  (void)missile;
  return *this;
}

BasicMissile::~BasicMissile() {

}



void  BasicMissile::think() {

}

void BasicMissile::draw() {
  int offsetX = (COLS - _world.getWidth()) / 2;
  int offsetY = (LINES - _world.getHeight()) / 2;

  move(offsetY + _posY, offsetX + _posX);
  addch(_skin);
}

void BasicMissile::bounce() {
  _world.setEntityAt((int)_posX, (int)_posY, NULL);
  delete this;
}

void BasicMissile::collide() {
  _world.setEntityAt((int)_posX, (int)_posY, NULL);
  delete this;
}
