
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include <ncurses.h>
#include "World.hpp"

World::World() :
  _width(200),
  _height(200)
{
  _createMap();
  _createBox();
}

World::World(int width, int height) :
  _width(width),
  _height(height)
{
  _createMap();
  _createBox();
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


void          World::_createMap() {
  this->_map = new AGameEntity**[_width];

  for (int i = 0; i < _width; i++)  {
    this->_map[i] = new AGameEntity*[_height];

    for (int j = 0; j < _height; j++)
      this->_map[i][j] = NULL;
  }
}

void          World::_createBox() {

}

void          World::draw() {
  ///
  int offsetX = (COLS - _width) / 2;
  int offsetY = (LINES - _height) / 2;

  _box = newwin(_height, _width, offsetY, offsetX);
  ///

  box(_box, 0, 0);
  wrefresh(_box);
}

void          World::refreshPhysics() {

}

AGameEntity*  World::getEntityAt(int x, int y) {
  return _map[x][y];
}

void    World::setEntityAt(int x, int y, AGameEntity* entity) {
	this->_map[x][y] = entity;
}
