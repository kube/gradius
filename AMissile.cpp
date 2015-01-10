
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


AMissile::AMissile() {

}

AMissile::AMissile(const AMissile& missile) {
	(void)missile;
}

AMissile::~AMissile() {

}


AMissile& AMissile::operator=(const AMissile& missile) {
  (void)missile;
  return *this;
}
