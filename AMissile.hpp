
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef AMISSILE_HPP
#define AMISSILE_HPP

#include "AShip.hpp"

class AMissile : public AGameEntity {

public:

  AMissile(const AShip& sender, float power);
  AMissile(const AMissile& ship);
  ~AMissile();

  AMissile& operator=(const AMissile& ship);


protected:

  const AShip&  _sender;
  float         _power;


private:

  AMissile();


};

#endif
