
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include "World.hpp"

World::World() {
  std::cout << "Welcome to the World !" << std::endl;
}

World::World(const World& world) {
  *this = world;
}

World::~World() {

}

World& World::operator=(const World& world) {
  (void)world;

  return *this;
}


void          World::draw() {

}

void          World::refreshPhysics() {

}

AGameEntity*  World::getEntityAt(int x, int y) {
  return _map[y][x];
}
