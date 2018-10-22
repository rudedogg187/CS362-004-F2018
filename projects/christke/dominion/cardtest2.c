/* Unit test for smithy card function */

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

  // Case 1: deck > 3, discard = 0
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = smithy;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.deckCount[0] = 6;
  G.deck[0][0] = feast;
  G.deck[0][1] = adventurer;
  G.deck[0][2] = treasure_map;
  G.deck[0][3] = curse;
  G.deck[0][4] = copper;
  G.deck[0][5] = treasure_map;
  cardEffect(smithy, -1, -1, -1, &G, 0, -1);
  assert(G.handCount[0] == 7);

  int ecnt,tmcnt,cprcnt,crscnt;
  for(int i = 0; i < G.handCount[0]; i++)
  {
    switch(G.hand[0][i])
    {
      case curse:
        crscnt++;
        break;
      case copper:
        cprcnt++;
        break;
      case estate:
        ecnt++;
        break;
      case treasure_map:
        tmcnt++;
        break;
    }
  }
  assert(crscnt == 1 && cprcnt == 1 && ecnt == 4 && tmcnt == 1);

  // Case 2: deck = 3, discard = 0
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = smithy;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.deckCount[0] = 3;
  G.deck[0][0] = curse;
  G.deck[0][1] = copper;
  G.deck[0][2] = treasure_map;
  cardEffect(smithy, -1, -1, -1, &G, 0, -1);
  assert(G.handCount[0] == 7);

  ecnt=0;
  tmcnt=0;
  cprcnt=0;
  crscnt=0;
  for(int i = 0; i < G.handCount[0]; i++)
  {
    switch(G.hand[0][i])
    {
      case curse:
        crscnt++;
        break;
      case copper:
        cprcnt++;
        break;
      case estate:
        ecnt++;
        break;
      case treasure_map:
        tmcnt++;
        break;
    }
  }
  assert(crscnt == 1 && cprcnt == 1 && ecnt == 4 && tmcnt == 1);

  // Case 3: deck < 3, discard = 0
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = smithy;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.deckCount[0] = 2;
  G.deck[0][0] = curse;
  G.deck[0][1] = treasure_map;
  cardEffect(smithy, -1, -1, -1, &G, 0, -1);
  assert(G.handCount[0] == 6);

  ecnt=0;
  tmcnt=0;
  cprcnt=0;
  crscnt=0;
  for(int i = 0; i < G.handCount[0]; i++)
  {
    switch(G.hand[0][i])
    {
      case curse:
        crscnt++;
        break;
      case copper:
        cprcnt++;
        break;
      case estate:
        ecnt++;
        break;
      case treasure_map:
        tmcnt++;
        break;
    }
  }
  assert(crscnt == 1 && cprcnt == 0 && ecnt == 4 && tmcnt == 1);

  // Case 4: deck = 3, discard > 0
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = smithy;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.discardCount[0] = 3;
  G.discard[0][0] = silver;
  G.discard[0][1] = gold;
  G.discard[0][2] = mine;

  G.deckCount[0] = 3;
  G.deck[0][0] = curse;
  G.deck[0][1] = copper;
  G.deck[0][2] = treasure_map;
  cardEffect(smithy, -1, -1, -1, &G, 0, -1);
  assert(G.handCount[0] == 7);

  ecnt=0;
  tmcnt=0;
  cprcnt=0;
  crscnt=0;
  for(int i = 0; i < G.handCount[0]; i++)
  {
    switch(G.hand[0][i])
    {
      case curse:
        crscnt++;
        break;
      case copper:
        cprcnt++;
        break;
      case estate:
        ecnt++;
        break;
      case treasure_map:
        tmcnt++;
        break;
    }
  }
  assert(crscnt == 1 && cprcnt == 1 && ecnt == 4 && tmcnt == 1);

  // Case 4: deck < 3, discard > 0
  memset(&G, 23, sizeof(struct gameState));   // clear the game state
  initializeGame(numPlayer, k, seed, &G); // initialize a new game

  G.whoseTurn = 0;
  G.handCount[0] = 5;
  G.hand[0][0] = smithy;
  for(int i = 1; i < G.handCount[0]; i++)
    G.hand[0][i] = estate;

  G.discardCount[0] = 3;
  G.discard[0][0] = silver;
  G.discard[0][1] = gold;
  G.discard[0][2] = mine;

  G.deckCount[0] = 2;
  G.deck[0][0] = curse;
  G.deck[0][1] = treasure_map;
  cardEffect(smithy, -1, -1, -1, &G, 0, -1);
  assert(G.handCount[0] == 7);

  ecnt=0;
  tmcnt=0;
  cprcnt=0;
  crscnt=0;
  int scnt,gcnt,mcnt;
  for(int i = 0; i < G.handCount[0]; i++)
  {
    switch(G.hand[0][i])
    {
      case curse:
        crscnt++;
        break;
      case copper:
        cprcnt++;
        break;
      case estate:
        ecnt++;
        break;
      case treasure_map:
        tmcnt++;
        break;
      case gold:
        gcnt++;
        break;
      case silver:
        scnt++;
        break;
      case mine:
        mcnt++;
        break;
    }
  }
  assert(crscnt == 1 && ecnt == 4 && tmcnt == 1 && (gcnt+scnt+mcnt == 1));

  printf("Test passed.\n");
  return 0;
}
