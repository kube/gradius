
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
#include <stdlib.h>
#include "Game.hpp"
#include "BasicEnemy.hpp"

static void initColors() {
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_CYAN, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
}

static int min(int a, int b) {
  return a < b ? a : b;
}

void Game::_drawScore() {
  mvprintw(3, COLS / 2 - 5, "SCORE: %d", _score);
}

void Game::_drawGameOver() {
  mvprintw(LINES / 2, COLS / 2 - 4, "GAME OVER");
}


Game::Game(int width, int height) :
  _running(true),
  _score(0),
  _gameOver(false),
  _world(*(new World(width, height)))
{

}

Game::~Game() {

}

Game& Game::operator=(const Game& game) {
  (void)game;
  
  return *this;
}



void  Game::setPlayer1(int x, int y) {
  _player1 = new Player(x, y);
}

void  Game::_getKey() {
  int key = getch();

  switch (key) {

    case 27:
      _running = false;
      break;

    case KEY_RIGHT:
      if (!_gameOver)
        _player1->moveImpulsion(0.5, 0);
      break;

    case KEY_LEFT:
      if (!_gameOver)
        _player1->moveImpulsion(-0.5, 0);
      break;

    case KEY_UP:
      if (!_gameOver)
        _player1->moveImpulsion(0, -0.1);
      break;

    case KEY_DOWN:
      if (!_gameOver)
        _player1->moveImpulsion(0, 0.1);
      break;

    case ' ':
      if (!_gameOver)
        _player1->shoot();
      break;
  }
}


void  Game::run() {
  static int elapsedMicroSeconds = 0;
  _elapsedTime = 0;

  initscr();
  ESCDELAY = 10;
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  curs_set(0);
  noecho();
  initColors();


  setPlayer1(_world.getWidth() / 2, _world.getHeight() * 3 / 4);
  

  // playMusic();

  while (_running) {
    _getKey();
    refreshPhysics();
    draw();
    refresh();

    popRandomEnemy();
  
    usleep(300);
    elapsedMicroSeconds += 310;
    if (elapsedMicroSeconds > 1000) {
      elapsedMicroSeconds = elapsedMicroSeconds % 1000;
      _elapsedTime++;
    }
  }

  // stopMusic();

  echo();
  endwin();
}

void  Game::stop() {
  _running = false;
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

  _drawScore();

  if (_gameOver)
    _drawGameOver();
}

void  Game::gameOver() {
  _gameOver = true;
}

void  Game::refreshPhysics() {
  _world.refreshPhysics();
}

World& Game::getWorld() {
	return _world;
}

void  Game::popRandomEnemy() {
  static int lastEnemyTimestamp = 0;

  if (_elapsedTime - lastEnemyTimestamp > min(2000 - _elapsedTime / 100, 300)) {
    lastEnemyTimestamp = _elapsedTime;
    
    new BasicEnemy(_world.getWidth() * (rand() % 100) / 100, 1);
  }
}

void  Game::updateScore(int value) {
  if (!_gameOver)
    _score += value;
}

int   Game::getElapsedTime() {
  return _elapsedTime;
}

Game* Game::getInstance() {
  return _instance;
}

Game* Game::_instance = new Game(103, 74);
