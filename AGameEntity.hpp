
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef AGAMEENTITY_HPP
#define AGAMEENTITY_HPP

class AGameEntity {

public:

  AGameEntity();
  AGameEntity(const AGameEntity& gameEntity);
  ~AGameEntity();

  AGameEntity& operator=(const AGameEntity& gameEntity);

  virtual void refreshPhyxsics() = 0;
  virtual void move(float, float) = 0;

  int   getColor();
  float getPosX();
  float getPosY();
  float getDirX();
  float getDirY();

  void  setColor(int);
  void  setPosX(float);
  void  setPosY(float);
  void  setDirX(float);
  void  setDirY(float);


protected:

  int   _color;

  float _posX;
  float _posY;

  float _dirX;
  float _dirY;


private:


};

#endif
