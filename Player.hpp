
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

class Player : public AShip{

public:

  Player();
  Player(const Player& game);
  ~Player();

  Player& operator=(const Player& game);
};

#endif
