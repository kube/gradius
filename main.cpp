
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

	Game * game = new Game(2,2);
	(void)game;
	std::cout << game->getWorld().getEntityAt(0, 0)->getColor();

	

/*  initscr();
  printw("Hello World !!!");
  
  refresh();
  getch();
  endwin();
*/


  return 0;
}
