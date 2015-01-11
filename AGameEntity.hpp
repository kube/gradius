
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

class World;

class AGameEntity {

public:

  AGameEntity();
  AGameEntity(int x, int y);
  AGameEntity(const AGameEntity& gameEntity);
  ~AGameEntity();

  AGameEntity& operator=(const AGameEntity& gameEntity);

  virtual void refreshPhysics() = 0;
  void movePosition(float, float);

  World& getWorld();
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

  World& _world;


private:


};

#endif
