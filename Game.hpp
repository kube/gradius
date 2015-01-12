
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
  void  stop();

  void  draw();
  void  refreshPhysics();

  int   getElapsedTime();

  void  playMusic();
  void  stopMusic();
  void  gameOver();
  World& getWorld();
  void  updateScore(int score);

  static Game* getInstance();

  void  setPlayer1(int x, int y);
  void  setPlayer2(int x, int y);
  void  popRandomEnemy();


private:

  void      _getKey();

  bool      _running;
  int       _score;
  int       _gameOver;
  int       _elapsedTime;


  World&    _world;
  Player*   _player1;
  Player*   _player2;
  pthread_t _musicThread;

  void      _drawScore();
  void      _drawGameOver();
  static Game* _instance;

  Game();
  Game(const Game& game);


};

#endif
