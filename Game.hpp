
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

  Game(int x, int y);
  ~Game();

  Game& operator=(const Game& game);

  void  run();
  void  draw();
  void  refreshPhysics();

  void  playMusic();
  void  stopMusic();
  World& getWorld();

  static Game* getInstance();

  void  setPlayer1(int x, int y);
  void  setPlayer2(int x, int y);


private:

  void      _getKey();

  bool      _running;
  World&    _world;
  Player*   _player1;
  Player*   _player2;
  pthread_t _musicThread;

  static Game* _instance;

  Game();
  Game(const Game& game);


};

#endif
