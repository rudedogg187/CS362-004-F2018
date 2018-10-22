/* Unit test for whoseTurn function */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(void)
{
  struct gameState G;
  int seed = 1000;
  int numPlayer = 2;
  int k[10] = {adventurer, council_room, feast, gardens, mine
           , remodel, smithy, village, baron, treasure_map};

  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  // Boundary case 1: whoseTurn = 0 (init)
  if(whoseTurn(&G) != 0)
  {
    printf("error: failed boundary case 1\n\n");
    return -1;
  }

  // Boundary case 2: whoseTurn < 0
  G.whoseTurn = -1;
  if(whoseTurn(&G) != -1)
  {
    printf("error: failed boundary case 2\n\n");
    return -1;
  }

  // Boundary case 2: whoseTurn > 0
  G.whoseTurn = 1;
  if(whoseTurn(&G) != 1)
  {
    printf("error: failed boundary case 3\n\n");
    return -1;
  }

  printf("whoseTurn unit test Passed\n\n");
  return 0;

}
