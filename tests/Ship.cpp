
      /*#######.
     ########",#:
   #########',##".
  ##'##'##".##',##.
   ## ## ## # ##",#.
    ## ## ## ## ##'
     ## ## ## :##
      ## ## ##*/

#include "Expectator.hpp"
#include "../AShip.hpp"

void testShip() {

  describe("AShip");

    it("can be implemented");

      AShip& ship = *(new AShip());

      ship.move(2.5, 48.0);
      expect(ship.getPosX()).no().equal(3);

  return 0;
}
