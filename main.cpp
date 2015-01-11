
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include <iostream>
#include <ncurses.h>
#include <unistd.h>

#include "Game.hpp"
#include "Player.hpp"

int main() {

	Game * game = new Game(6,6);
	Player * player = new Player();
	(void)game;
	std::cout <<"View Attrib : of Game -> WORLD -> ATTRIB -> COLOR : "<< game->getWorld().getEntityAt(0, 0)->getColor() << std::endl;

	
	(void)player;
	std::cout << "INFO PLAYER : ShootX : " <<player->getShootX()<< "  ShootY : "<< player->getShootY() << std::endl;



	game->getWorld().setEntityAt(2, 2, player);
	std::cout <<"View Attrib : of Game -> WORLD -> ATTRIB -> COLOR : "<<  game->getWorld().getEntityAt(2, 2)->getColor();
/*  initscr();
  printw("Hello World !!!");
  
  refresh();
  getch();
  endwin();
*/


  return 0;
}
