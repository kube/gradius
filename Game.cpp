
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

Game::Game() :
	_world(*(new World(1, 1))),
	_player(*(new Player()))
{
  std::cout << "Welcome to the Game !" << std::endl;
}

Game::Game(int x, int y) :
    _world(*(new World(x, y))),
    _player(*(new Player()))
{
	std::cout << "Welcome to the Game !" << std::endl;
}

Game::Game(const Game& game) :
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


void  Game::draw() {

}

void  Game::refreshPhysics() {

}

World& Game::getWorld()
{
	return _world;
}
