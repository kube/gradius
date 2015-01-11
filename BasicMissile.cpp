
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
  _posX = _sender.getPosX() + _sender.getShootX();
  _posY = _sender.getPosY() + _sender.getShootY();

  _dirX = _sender.getShootX() * power;
  _dirY = _sender.getShootY() * power;

  _deceleration = 1.00001;
  _acceleration = 0.05;
  _bounce = 0.0;
  _maxSpeed = 0.8;

  _world.setEntityAt((int)_posX, (int)_posY, this);
}

BasicMissile& BasicMissile::operator=(const BasicMissile& missile) {
  (void)missile;
  return *this;
}

BasicMissile::~BasicMissile() {

}



void BasicMissile::draw() {
  int offsetX = (COLS - _world.getWidth()) / 2;
  int offsetY = (LINES - _world.getHeight()) / 2;

  move(offsetY + _posY, offsetX + _posX);
  printw("|");
}

void BasicMissile::bounce() {
  _world.setEntityAt((int)_posX, (int)_posY, NULL);
  delete this;
}

void BasicMissile::collide() {
  _world.setEntityAt((int)_posX, (int)_posY, NULL);
  delete this;
}
