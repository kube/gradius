
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
	int x = 6;
	int y = 7;
	int i = 0;
	int e = 0;
	std::cout << "Welcome to the World !" << std::endl;
	this->_map = new AGameEntity**[x];
	while (i < x)
	{
		this->_map[i] = new AGameEntity*[y];
		e = 0;
		while (e < y)
		{
			this->_map[i][e] = new AGameEntity(x, y);
			e++;
		}
		i++;
	}
}

World::World(int x, int y) {
    int i = 0;
	int e;	
	std::cout << "Welcome to the World ! This size is, x : "<< x << " and y : "<< y  << std::endl;
    this->_map = new AGameEntity**[x];
    while (i < x)
    {
        this->_map[i] = new AGameEntity*[y];
        e = 0;
        while (e < y)
        {
            this->_map[i][e] = new AGameEntity(i, e);
            e++;
        }
        i++;
    }
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
  return _map[x][y];
}

void    World::setEntityAt(int x, int y, AGameEntity * entity)
{
	this->_map[x][y] = entity;
}
