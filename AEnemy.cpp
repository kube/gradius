
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
#include "AEnemy.hpp"


AEnemy::AEnemy() :
  AShip(100, 100, 100, 0, -1, 0)
{
  // std::cout << "Welcome to the AEnemy !" << std::endl;
}

AEnemy::AEnemy(int x, int y) :
	AShip(100, 100, 100, 0, -1, 0)
{
  _posX = x;
  _posY = y;
  // std::cout << "Welcome to the AEnemy !" << std::endl;
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
