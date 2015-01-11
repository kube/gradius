
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

#include <ncurses.h>
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
	void			      setEntityAt(int x, int y, AGameEntity * entity);

private:

  void            _createBox();
  void            _createMap();

  int             _width;
  int             _height;
  WINDOW*         _box;
  AGameEntity***  _map;


};

#endif
