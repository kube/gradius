
      /*#######.        
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef WORLD_HPP
#define WORLD_HPP

#include "AShip.hpp"

class World {

public:

  World();
	World(int x, int y);
  World(const World& world);
  ~World();

  World& operator=(const World& ship);

  void            draw();
  void            refreshPhysics();

  AGameEntity*    getEntityAt(int, int);
	void			setEntityAt(int x, int y, AGameEntity * entity);

private:

  AGameEntity***  _map;


};

#endif
