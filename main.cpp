
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

int main() {

  initscr();
  printw("Hello World !!!");
  
  refresh();
  getch();
  endwin();

  return 0;
}
