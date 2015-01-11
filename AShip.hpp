
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef ASHIP_HPP
#define ASHIP_HPP

#include "AGameEntity.hpp"

class AMissile;

class AShip : public AGameEntity {

public:

  AShip();
	AShip(int health, int maxHealth, float maxPower, float shootX, float shootY);
  AShip(const AShip& ship);
  ~AShip();

  AShip& operator=(const AShip& ship);

  void        shoot(float power);

  float       getShootX();
  float       getShootY();

  void        setShootX(float);
  void        setShootY(float);

protected:

  int         _health;
  int         _maxHealth;
  AMissile*   _currentWeapon;
  float       _maxPower;

  float       _shootX;
  float       _shootY;

private:  


};

#endif
