
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#ifndef GAME_HPP
#define GAME_HPP

class Game {

public:

  Game();
  Game(const Game& ship);
  ~Game();

  Game& operator=(const Game& ship);


protected:

  AShip& _sender;
  float _power;


private:


};

#endif
