
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

  virtual void draw() = 0;
  virtual void refreshPhysics() = 0;
  void movePosition(float, float);

  World&  getWorld() const;
  int     getColor() const;
  float   getPosX() const;
  float   getPosY() const;
  float   getDirX() const;
  float   getDirY() const;

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

  float _acceleration;
  float _deceleration;
  float _bounce;
  float _maxSpeed;

  World& _world;


private:


};

#endif
