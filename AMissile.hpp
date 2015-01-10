
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

class AMissile : public AGameEntity {

public:

  AMissile();
  AMissile(const AMissile& ship);
  ~AMissile();

  AMissile& operator=(const AMissile& ship);


protected:

  AShip&  _sender;
  float   _power;


private:


};

#endif
