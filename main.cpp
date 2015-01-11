
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include "Game.hpp"

int main() {
  Game& game = *(Game::getInstance());


  game.setPlayer1(4, 4);

  game.run();

  return 0;
}
