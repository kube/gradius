
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>

#include "Game.hpp"
#include "AGameEntity.hpp"
#include "World.hpp"

AGameEntity::AGameEntity () :
  _color(1),
  _skin('*'),
  _world(Game::getInstance()->getWorld())
{

}

AGameEntity::AGameEntity(int x, int y) :
  _posX(x),
  _posY(y),
  _color(1),
  _skin('*'),
  _world(Game::getInstance()->getWorld())
{

}

AGameEntity::AGameEntity(const AGameEntity& gameEntity) :
  _world(Game::getInstance()->getWorld())
{
  (void)gameEntity;
}

AGameEntity::~AGameEntity() {

}


AGameEntity& AGameEntity::operator=(const AGameEntity& gameEntity) {
  (void)gameEntity;
  return *this;
}



void  AGameEntity::refreshPhysics() {
  int didBounce = false;

  _world.setEntityAt((int)_posX, (int)_posY, NULL);

  _posX += _dirX * _acceleration;
  _posY += _dirY * _acceleration;

  _dirX *= _deceleration;
  _dirY *= _deceleration;

  if (_posX < 1) {
    _posX = 1;
    _dirX = -_dirX * _bounce;
    didBounce = true;
  }
  else if (_posX >= _world.getWidth()) {
    _posX = _world.getWidth() - 1;
    _dirX = -_dirX * _bounce;
    didBounce = true;
  }

  if (_posY < 1) {
    _posY = 1;
    _dirY = -_dirY * _bounce;
    didBounce = true;
  }
  else if (_posY >= _world.getHeight()) {
    _posY = _world.getHeight() - 1;
    _dirY = -_dirY * _bounce;
    didBounce = true;
  }
  _world.setEntityAt((int)_posX, (int)_posY, this);

  if (didBounce)
    bounce();
}


World& AGameEntity::getWorld() const {
  return _world;
}

int   AGameEntity::getColor() const {
  return _color;
}

float AGameEntity::getPosX() const {
  return _posX;
}

float AGameEntity::getPosY() const {
  return _posY;
}

float AGameEntity::getDirX() const {
  return _dirX;
}

float AGameEntity::getDirY() const {
  return _dirY;
}


void AGameEntity::setColor(int value) {
  _color = value;
}

void AGameEntity::setPosX(float value) {
  _posX = value;
}

void AGameEntity::setPosY(float value) {
  _posY = value;
}

void AGameEntity::setDirX(float value) {
  _dirX = value;
}

void AGameEntity::setDirY(float value) {
  _dirY = value;
}
