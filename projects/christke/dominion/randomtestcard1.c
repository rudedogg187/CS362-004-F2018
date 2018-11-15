/* Random test for adventurer card function */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <assert.h>
#include "rngs.h"

void randomInitialization(struct gameState *G, int *handPos, int *choice1)
{
  int i,j,p,handSize,deckSize,discardSize,playedSize,players,randCard,unique;
  int kCards[10];
  int possibleCards[17];
  players = (int)((rand()%(MAX_PLAYERS-1))+2);
  printf("Players: %i\n", players);
  kCards[0] = smithy;
  /* Randomly select remaining kingdom cards */
  for(i = 1; i < 10; i++)
  {
    j=0;
    unique = 0;
    randCard = (int)((rand()%19)+7);
    while(!unique)
    {
      if(randCard == kCards[j] && j!=i)
      {
        randCard = (int)((rand()%19)+7);
        j = 0;
      }
      else if(j >= 10)
      {
        kCards[i] = randCard;
        possibleCards[i] = kCards[i];
        unique = 1;
      }
      else j++;
    }
  }
  for(i = 10; i < 17; i++)
  {
    possibleCards[i] = i-10;
  }
  // printf("%i; %i; %i; %i; %i; %i; %i; %i; %i; %i;\n", kCards[0],kCards[1],kCards[2],kCards[3],kCards[4],kCards[5],kCards[6],kCards[7],kCards[8],kCards[9]);
  /* Create random game state */
  for (i = 0; i < sizeof(struct gameState); i++) {
    ((char*)G)[i] = (char)(rand()%256);
  }
  p = (int)(rand()%players);
  printf("Current player: %i\n", p);
  handSize = (int)((rand()%(MAX_HAND-1))+2);
  printf("Hand Size: %i\n", handSize);
  *handPos = (int)((rand()%handSize));
  printf("Hand Position: %i\n", *handPos);
  deckSize = (int)((rand()%MAX_DECK)+1);
  printf("Deck Size: %i\n", deckSize);
  discardSize = (int)((rand()%MAX_DECK)+1);
  printf("Discard Size: %i\n", discardSize);
  playedSize = (int)((rand()%MAX_DECK)+1);
  printf("Played Size: %i\n", playedSize);

  G->numPlayers = players;
  G->numActions = 1;
  G->numBuys = 1;
  G->whoseTurn = p;
  G->handCount[p] = handSize;
  G->deckCount[p] = deckSize;
  G->discardCount[p] = discardSize;
  G->playedCardCount = playedSize;

  *choice1 = kCards[(int)(rand()%10)];


  for(i = 0; i < 17; i++)
  {
    G->supplyCount[possibleCards[i]] = (int)(rand()%10);
  }
  for(i = 0; i < handSize; i++)
  {
    randCard = (int)(rand()%17);
    G->hand[p][i] = possibleCards[randCard];
  }
  G->hand[p][*handPos] = smithy;
  for(i = 0; i < deckSize; i++)
  {
    randCard = (int)(rand()%17);
    G->deck[p][i] = possibleCards[randCard];
  }
  for(i=0; i < discardSize; i++)
  {
    randCard = (int)(rand()%17);
    G->discard[p][i] = possibleCards[randCard];
  }
  for(i=0; i < playedSize; i++)
  {
    randCard = (int)(rand()%17);
    G->playedCards[i] = possibleCards[randCard];
  }

  return;
}

int testCardFeast(struct gameState *G)
{
  int i,cost,supply,precount,postcount,choice1,position;
  cost = 0;
  supply = 0;
  precount = 0;
  postcount = 0;
  randomInitialization(G, &position, &choice1);    // Randomly set initialization variables

  cost = getCost(choice1);
  supply = G->supplyCount[choice1];
  printf("Cost = %i\nSupply = %i\n",cost, supply);
  precount = G->discardCount[G->whoseTurn];
  // precount = G->playedCardCount;
  printf("Precount = %i\n",precount);
  cardEffect(feast, choice1, -1, -1, G, position, (int *)-1);  // cardEffect_adventurer(G);
  postcount = G->discardCount[G->whoseTurn];
  // postcount = G->playedCardCount;
  printf("Postcount = %i\n",postcount);
  if(cost <= 5 && supply > 0)
  {
    assert(supply == G->supplyCount[choice1]+1);
    assert(postcount == precount+1);
  }
  else
    assert(postcount == precount);

  return 0;
}

int main(void)
{
  srand(time(NULL));
  SelectStream(1);
  PutSeed((long)(1000));
  struct gameState G;
  int ret, pos;

  // Boundary 1: more than two treasures in deck
  for(int i = 0; i < 2000; i++)
  {
    ret = testCardFeast(&G);
    assert(!ret);
  }

  printf("Test Successful.\n");
  return 0;

}
