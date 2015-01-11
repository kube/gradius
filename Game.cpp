
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <ncurses.h>
#include "Game.hpp"


static void initColors() {
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_CYAN, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
}


Game::Game() :
  _running(true),
  _world(*(new World())),
  _player1(*(new Player(_world.getWidth() / 2, _world.getHeight() * 3 / 4)))
{
  // std::cout << "Welcome to the Game !" << std::endl;
}

Game::Game(int width, int height) :
    _running(true),
    _world(*(new World(width, height))),
    _player1(*(new Player(width / 2, height * 3 / 4)))
{
	// std::cout << "Welcome to the Game !" << std::endl;
}

Game::Game(const Game& game) :
  _running(true),
  _world(*(new World(game._world))),
  _player1(*(new Player(game._player1)))
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
  initColors();

  // playMusic();

  while (_running) {
    refresh();
    move(0, 0);

    // Check times here
    draw();
    refreshPhysics();

    if (getch() == KEY_BACKSPACE)
      _running = false;

    usleep(20000);
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
  int offsetX = (COLS - _world.getWidth()) / 2;
  int offsetY = (LINES - _world.getHeight()) / 2;

  _world.draw();
  _player1.draw(offsetX, offsetY);
}

void  Game::refreshPhysics() {

}

World& Game::getWorld()
{
	return _world;
}
