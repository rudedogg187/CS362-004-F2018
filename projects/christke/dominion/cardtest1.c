/* Unit test for adventurer card function */

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

  // Boundary 1: more than two treasures in deck
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = adventurer;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.deckCount[0] = 6;
  G.deck[0][0] = copper;
  G.deck[0][1] = adventurer;
  G.deck[0][2] = copper;
  G.deck[0][3] = feast;
  G.deck[0][4] = copper;
  G.deck[0][5] = mine;
  cardEffect(adventurer, -1, -1, -1, &G, 0, -1);
  assert(G.hand[0][G.handCount[0]-1] == copper && G.hand[0][G.handCount[0]-2] == copper && G.hand[0][G.handCount[0]-3] != copper);

  // Boundary 2: Exactly two treasures in deck
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = adventurer;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.deckCount[0] = 6;
  G.deck[0][0] = gold;
  G.deck[0][1] = adventurer;
  G.deck[0][2] = treasure_map;
  G.deck[0][3] = feast;
  G.deck[0][4] = gold;
  G.deck[0][5] = mine;
  cardEffect(adventurer, -1, -1, -1, &G, 0, -1);
  assert(G.hand[0][G.handCount[0]-1] == gold && G.hand[0][G.handCount[0]-2] == gold && G.hand[0][G.handCount[0]-3] != gold);

  // Boundary 3: fewer than 2 treasures in deck
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = adventurer;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.deckCount[0] = 6;
  G.deck[0][0] = adventurer;
  G.deck[0][1] = silver;
  G.deck[0][2] = treasure_map;
  G.deck[0][3] = feast;
  G.deck[0][4] = mine;
  G.deck[0][5] = mine;
  cardEffect(adventurer, -1, -1, -1, &G, 0, -1);
  assert(G.hand[0][G.handCount[0]-1] == silver && G.hand[0][G.handCount[0]-2] != silver);

  // Boundary 4: No treasures in deck
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = adventurer;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.deckCount[0] = 6;
  G.deck[0][0] = adventurer;
  G.deck[0][1] = smithy;
  G.deck[0][2] = treasure_map;
  G.deck[0][3] = feast;
  G.deck[0][4] = mine;
  G.deck[0][5] = mine;
  cardEffect(adventurer, -1, -1, -1, &G, 0, -1);
  printf("%i %i %i %i %i\n", G.hand[0][G.handCount[0]-1],G.hand[0][G.handCount[0]-2],G.hand[0][G.handCount[0]-3],G.hand[0][G.handCount[0]-4],G.hand[0][G.handCount[0]-5]);
  assert(G.hand[0][G.handCount[0]-1] != copper && G.hand[0][G.handCount[0]-2] != copper);


  printf("Test passed.\n");
  return 0;
}
