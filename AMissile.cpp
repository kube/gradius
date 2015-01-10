
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include "AMissile.hpp"
#include "AShip.hpp"

AMissile::AMissile(const AShip& sender, float power) : _sender(sender), _power(power) {

}

AMissile::AMissile(const AMissile& missile) : AGameEntity(), _sender(missile._sender) {
	(void)missile;
}

AMissile::~AMissile() {

}


AMissile& AMissile::operator=(const AMissile& missile) {
  (void)missile;
  return *this;
}
