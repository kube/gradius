
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef BASICMISSILE_HPP
#define BASICMISSILE_HPP

#include "AMissile.hpp"

class AShip;

class BasicMissile : public AMissile {

public:

  BasicMissile(const AShip& sender, float power);
  ~BasicMissile();

  BasicMissile& operator=(const BasicMissile& ship);

  void  draw();
  void  refreshPhysics();


protected:


private:

  BasicMissile();
  BasicMissile(const BasicMissile& ship);


};

#endif