
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include "Game.hpp"

#include <unistd.h>
#include <pthread.h>
#include <ncurses.h>


Game::Game() :
  _running(true),
  _world(*(new World(1, 1))),
  _player(*(new Player()))
{
  // std::cout << "Welcome to the Game !" << std::endl;
}

Game::Game(int x, int y) :
    _running(true),
    _world(*(new World(x, y))),
    _player(*(new Player()))
{
	// std::cout << "Welcome to the Game !" << std::endl;
}

Game::Game(const Game& game) :
  _running(true),
  _world(game._world),
  _player(*(new Player()))
{
  *this = game;
}

Game::~Game() {

}

Game& Game::operator=(const Game& game) {
  (void)game;
  
  return *this;
}


void  Game::run() {
  initscr();
  nodelay(stdscr, TRUE);
  curs_set(0);
  noecho();

  // playMusic();

  while (_running) {
    refresh();
    move(0, 0);

    // Check times here
    draw();
    refreshPhysics();

    if (getch() == 27)
      _running = false;

    usleep(310);
  }

  echo();
  // stopMusic();
  endwin();
}


static void *musicThreadedPlay(void *args) {
  (void)args;
  execl("/usr/bin/afplay", "afplay", "Open.mp3", NULL);
  pthread_exit(NULL);
}

void Game::playMusic() {
  pthread_create(&_musicThread, NULL, musicThreadedPlay, NULL);
}

void Game::stopMusic() {
  pthread_cancel(_musicThread);
}


void  Game::draw() {
  _world.draw();
}

void  Game::refreshPhysics() {

}

World& Game::getWorld()
{
	return _world;
}
