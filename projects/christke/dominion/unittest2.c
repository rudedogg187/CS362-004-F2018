/* Unit test for fullDeckCount function */

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
  int count;
  int k[10] = {adventurer, council_room, feast, gardens, mine
           , remodel, smithy, village, baron, treasure_maps};

  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  // Case 1, no count in deck, hand, or discard
  count = fullDeckCount(0, adventurer, &G);
  printf("%i\n",count);
  assert(count == 0);

  // case 2: no count in deck, no cound in hand, max count in discard
  G.discardCount[0] = MAX_DECK;
  for(int d = 0; d < MAX_DECK; d++)
    G.discard[0][d] = adventurer;
  count = fullDeckCount(0, adventurer, &G);
  printf("%i\n",count);
  assert(count == MAX_DECK);

  // case 3: no count in deck, max count in hand, max count in discard
  G.handCount[0] = MAX_HAND;
  for(int d = 0; d < MAX_HAND; d++)
    G.hand[0][d] = adventurer;
  count = fullDeckCount(0, adventurer, &G);
  printf("%i\n",count);
  assert(count == MAX_HAND+MAX_DECK);

  // case 4: no count in deck, max count in hand, no count in discard
  G.discardCount[0] = 0;
  for(int d = 0; d < MAX_DECK; d++)
    G.discard[0][d] = smithy;
  count = fullDeckCount(0, adventurer, &G);
  printf("%i\n",count);
  assert(count == MAX_HAND);

  // case 5: max count in deck, max count in hand, no count in discard
  G.deckCount[0] = MAX_DECK;
  for(int d = 0; d < MAX_DECK; d++)
    G.deck[0][d] = adventurer;
  count = fullDeckCount(0, adventurer, &G);
  printf("%i\n",count);
  assert(count == MAX_HAND+MAX_DECK);

  // case 6: max count in deck, no count in hand, no count in discard
  G.handCount[0] = 0;
  for(int d = 0; d < MAX_HAND; d++)
    G.hand[0][d] = smithy;
  count = fullDeckCount(0, adventurer, &G);
  printf("%i\n",count);
  assert(count == MAX_DECK);

  // case 7: max count in deck, no count in hand, max count in discard
  G.discardCount[0] = MAX_DECK;
  for(int d = 0; d < MAX_DECK; d++)
    G.discard[0][d] = adventurer;
  count = fullDeckCount(0, adventurer, &G);
  printf("%i\n",count);
  assert(count == 2*MAX_DECK);

  // case 8: max count in deck, max count in hand, max count in discard
  G.handCount[0] = MAX_HAND;
  for(int d = 0; d < MAX_HAND; d++)
    G.hand[0][d] = adventurer;
  count = fullDeckCount(0, adventurer, &G);
  printf("%i\n",count);
  assert(count == MAX_HAND+2*MAX_DECK);

  printf("Test Passed.\n");
  return 0;

}
