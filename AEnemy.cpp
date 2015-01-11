
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include "AEnemy.hpp"

AEnemy::AEnemy(int x, int y) :
	AShip(100, 100, 100, 0, 1, 0)
{
  _posX = x;
  _posY = y;

}

AEnemy::AEnemy(const AEnemy& game) :
  AShip(game)
{
  *this = game;
}

AEnemy::~AEnemy() {

}

AEnemy& AEnemy::operator=(const AEnemy& game) {
  (void)game;
  
  return *this;
}


void  AEnemy::draw(int offsetX, int offsetY) {

  move(offsetY + _posY, offsetX + _posX);
  printw("O");
}
