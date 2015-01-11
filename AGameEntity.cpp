
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
  _world(Game::getInstance()->getWorld())
{

}

AGameEntity::AGameEntity(int x, int y) :
  _color(1),
  _posX(x),
  _posY(y),
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
