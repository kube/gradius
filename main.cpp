
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
	std::cout << game->getWorld().getEntityAt(0, 0)->getColor() << std::endl;;

	
	(void)player;
	std::cout << "ShootX : " <<player->getShootX()<< "  ShootY : "<< player->getShootY() << std::endl;

	
/*  initscr();
  printw("Hello World !!!");
  
  refresh();
  getch();
  endwin();
*/


  return 0;
}
