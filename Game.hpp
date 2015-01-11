
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

#include "World.hpp"
#include "AShip.hpp"
#include "Player.hpp"

class Game {

public:

  Game();
	Game(int x, int y);
  Game(const Game& game);
  ~Game();

  Game& operator=(const Game& game);

  void  draw();
  void  refreshPhysics();
	World& getWorld();

private:

	World&  _world;
	Player& _player;

};

#endif
