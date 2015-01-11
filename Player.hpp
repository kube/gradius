
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

  void    draw(int offsetX, int offsetY);


private:

  Player();


};

#endif
