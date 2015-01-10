
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include "AGameEntity.hpp"


AGameEntity::AGameEntity() {

}

AGameEntity::AGameEntity(const AGameEntity& gameEntity) {
  (void)gameEntity;
}

AGameEntity::~AGameEntity() {

}


AGameEntity& AGameEntity::operator=(const AGameEntity& gameEntity) {
  (void)gameEntity;
  return *this;
}



int   AGameEntity::getColor() {
  return _color;
}

float AGameEntity::getPosX() {
  return _posX;
}

float AGameEntity::getPosY() {
  return _posY;
}

float AGameEntity::getDirX() {
  return _dirX;
}

float AGameEntity::getDirY() {
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
