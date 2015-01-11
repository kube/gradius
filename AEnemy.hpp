
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef AENEMY_HPP
#define AENEMY_HPP

#include "World.hpp"
#include "AShip.hpp"

class AEnemy : public AShip {

public:

  AEnemy(int x, int y);
  AEnemy(const AEnemy& game);
  ~AEnemy();

  AEnemy& operator=(const AEnemy& game);

  void    draw(int offsetX, int offsetY);


private:

  AEnemy();


};

#endif
