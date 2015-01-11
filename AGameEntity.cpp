
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


AGameEntity::AGameEntity() : _active(0), _color(1){
	std::cout << "Default Constructor AGameEntity" << std::endl;
}

AGameEntity::AGameEntity(int x, int y) : _active(0), _color(1), _posX(x), _posY(y){
	std::cout << "Position Constructor AGameEntity with X : "<< _posX<< " and Y : " << _posY << std::endl;
}

AGameEntity::AGameEntity(const AGameEntity& gameEntity) {
  *this = gameEntity;
}

AGameEntity::~AGameEntity() {

}


AGameEntity& AGameEntity::operator=(const AGameEntity& gameEntity) {
  (void)gameEntity;
  return *this;
}


int   AGameEntity::getActive() {
	return _active;
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

void AGameEntity::setActive(int value) {
	_active = value;
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
