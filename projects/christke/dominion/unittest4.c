/* Unit test for isGameOver function */

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

  // Boundary case: provinces still left, no other piles empty
  assert(isGameOver(&G) == 0);

  // Boundary Case: no provinces Left
  G.supplyCount[province] = 0;
  assert(isGameOver(&G) == 1);

  //Boundary Case: negative provinces left
  // G.supplyCount[province] = -1;
  // assert(isGameOver(&G) == 1);

  //Boundary Case: provinces still left, 3 piles empty. Choose piles at extremes of enum
  G.supplyCount[province] = 1;
  G.supplyCount[curse] = 0;
  G.supplyCount[adventurer] = 0;
  G.supplyCount[treasure_map] = 0;
  assert(isGameOver(&G) == 1);

  printf("Test Passed.\n");
  return 0;
}
