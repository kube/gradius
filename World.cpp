
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

#include "Game.hpp"

static void drawRectangle(int x, int y, int width, int height) {

  attron(COLOR_PAIR(2));

  mvvline(y, x, ACS_VLINE, height);
  mvvline(y, x + width, ACS_VLINE, height);

  mvhline(y, x, ACS_HLINE, width);
  mvhline(y + height, x, ACS_HLINE, width + 1);

  mvaddch(y, x, ACS_ULCORNER);
  mvaddch(y, x + width, ACS_URCORNER);

  mvaddch(y + height, x, ACS_LLCORNER);
  mvaddch(y + height, x + width, ACS_LRCORNER);

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

  for (int i = 0; i < _width; i++) {
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
  erase();

  int offsetX = (COLS - _width) / 2;
  int offsetY = (LINES - _height) / 2;

  drawRectangle(offsetX, offsetY, _width, _height);

  for (int i = 0; i < _width; i++)
    for (int j = 0; j < _height; j++)
      if (getEntityAt(i, j))
        getEntityAt(i, j)->draw();
}

void          World::refreshPhysics() {
  for (int i = 0; i < _width; i++)
    for (int j = 0; j < _height; j++)
      if (getEntityAt(i, j))
        getEntityAt(i, j)->refreshPhysics();
}

AGameEntity*  World::getEntityAt(int x, int y) {
  return _map[x][y];
}

void    World::setEntityAt(int x, int y, AGameEntity* entity) {
  if (x < 0 || y < 0 || x >= _width || y >= _height) {
    entity->collide();
    return;
  }  

  // if (this->_map[x][y]) {
  //   this->_map[x][y]->collide();
  //   entity->collide();
  // }
  // else
  	this->_map[x][y] = entity;
}
