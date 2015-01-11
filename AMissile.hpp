
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

#include "AGameEntity.hpp"

class AShip;

class AMissile : public AGameEntity {

public:

  AMissile(const AShip& sender, float power);
  ~AMissile();

  AMissile& operator=(const AMissile& missile);


protected:

  const AShip&  _sender;
  float         _power;


private:

  AMissile();
  AMissile(const AMissile& missile);


};

#endif
