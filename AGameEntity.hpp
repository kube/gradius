
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
	AGameEntity(int x, int y);
  AGameEntity(const AGameEntity& gameEntity);
  ~AGameEntity();

  AGameEntity& operator=(const AGameEntity& gameEntity);

  void refreshPhyxsics() ;
  void move(float, float) ;

  int   getColor();
  float getPosX();
  float getPosY();
  float getDirX();
  float getDirY();

	void	setActive(int);
  void  setColor(int);
  void  setPosX(float);
  void  setPosY(float);
  void  setDirX(float);
  void  setDirY(float);


protected:

	int  _active;
  
  int   _color;

  float _posX;
  float _posY;

  float _dirX;
  float _dirY;


private:


};

#endif
