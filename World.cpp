
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


static void drawRectangle(int x, int y, int width, int height) {

  attron(COLOR_PAIR(2));

  mvvline(y, x, '*', height);
  mvvline(y, x + width, '*', height);

  mvhline(y, x, '*', width);
  mvhline(y + height, x, '*', width);

  attroff(COLOR_PAIR(2));
}


World::World() :
  _width(87),
  _height(70)
{
  _createMap();
}

World::World(int width, int height) :
  _width(width),
  _height(height)
{
  _createMap();
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

int           World::getHeight() {
  return _height;
}

int           World::getWidth() {
  return _width;
}

void          World::draw() {
  clear();

  int offsetX = (COLS - _width) / 2;
  int offsetY = (LINES - _height) / 2;

  drawRectangle(offsetX, offsetY, _width, _height);
}

void          World::refreshPhysics() {

}

AGameEntity*  World::getEntityAt(int x, int y) {
  return _map[x][y];
}

void    World::setEntityAt(int x, int y, AGameEntity* entity) {
	this->_map[x][y] = entity;
}
