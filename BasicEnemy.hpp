
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef BASICENEMY_HPP
#define BASICENEMY_HPP

#include "World.hpp"
#include "AEnemy.hpp"

class BasicEnemy : public AEnemy {

public:

  BasicEnemy(int x, int y);
  BasicEnemy(const BasicEnemy& game);
  ~BasicEnemy();

  BasicEnemy& operator=(const BasicEnemy& game);

  void    draw();
  void    shoot();
  void    bounce();
  void    collide();
  void    refreshPhysics();


private:

  BasicEnemy();


};

#endif
