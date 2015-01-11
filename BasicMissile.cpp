
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

BasicMissile::BasicMissile(const AShip& sender, float power) :
  AMissile(sender, power)
{
  _posX = _sender.getPosX() + _sender.getShootX();
  _posY = _sender.getPosY() + _sender.getShootY();

  _dirX = _sender.getShootX() * power;
  _dirY = _sender.getShootY() * power;

  // _world[(int)_posX][(int)_posY] = this;
}

void BasicMissile::refreshPhysics() {
  
}

void BasicMissile::draw() {
  int offsetX = (COLS - _world.getWidth()) / 2;
  int offsetY = (LINES - _world.getHeight()) / 2;

  move(offsetY + _posY, offsetX + _posX);
  printw("|");
}

BasicMissile& BasicMissile::operator=(const BasicMissile& missile) {
  (void)missile;
  return *this;
}
