
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

  int             getWidth();
  int             getHeight();

  AGameEntity*    getEntityAt(int x, int y);
	void			      setEntityAt(int x, int y, AGameEntity * entity);

  void            popRandomEnemy();

private:

  void            _createBox();
  void            _createMap();

  int             _width;
  int             _height;
  AGameEntity***  _map;


};

#endif
