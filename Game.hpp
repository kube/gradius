
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

#include <pthread.h>

class Game {

public:

  Game();
	Game(int x, int y);
  Game(const Game& game);
  ~Game();

  Game& operator=(const Game& game);

  void  run();
  void  draw();
  void  refreshPhysics();

  void  playMusic();
  void  stopMusic();
  World& getWorld();

  static Game& getInstance();


private:

  bool      _running;
	World&    _world;
	Player&   _player1;
  pthread_t _musicThread;

};

#endif
