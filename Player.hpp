
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "World.hpp"
#include "AShip.hpp"

#include <ncurses.h>

class Player : public AShip {

public:

  Player(int x, int y);
  Player(const Player& game);
  ~Player();

  Player& operator=(const Player& game);

  void    draw();
  void    bounce();
  void    collide();
  void    think();
  void    moveImpulsion(float x, float y);
  void    shoot();


private:

  Player();
  

};

#endif
