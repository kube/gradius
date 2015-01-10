
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include "AShip.hpp"

AShip::AShip() {

}

AShip::AShip(const AShip& ship) {
  (void)ship;
}

AShip::~AShip() {

}

AShip&    AShip::operator=(const AShip& ship) {
  return *this;
}

void      AShip::shoot(float power) {
  (void)power;
}



float     AShip::getShootX() {
  return _shootX;
}
float     AShip::getShootY() {
  return _shootY;
}



void      AShip::setShootX(float value) {
  _shootX = value;
}

void      AShip::setShootY(float value) {
  _shootY = value;
}
