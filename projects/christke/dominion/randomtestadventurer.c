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

void randomInitialization(struct gameState *G, int *handPos)
{
  int i,j,p,handSize,deckSize,discardSize,players,randCard,unique;
  int kCards[10];
  int possibleCards[17];
  players = (int)((rand()%(MAX_PLAYERS-1))+2);
  printf("Players: %i\n", players);
  kCards[0] = adventurer;
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

  G->numPlayers = players;
  G->numActions = 1;
  G->numBuys = 1;
  G->whoseTurn = p;
  G->handCount[p] = handSize;
  G->deckCount[p] = deckSize;
  G->discardCount[p] = discardSize;

  for(i = 0; i < handSize; i++)
  {
    randCard = (int)(rand()%17);
    G->hand[p][i] = possibleCards[randCard];
  }
  G->hand[p][*handPos] = adventurer;
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

  return;
}

int testCardAdventurer(struct gameState *G)
{
  int i,treasureCountDeckDiscard,precount,postcount,position;
  treasureCountDeckDiscard = 0;
  precount = 0;
  postcount = 0;
  randomInitialization(G, &position);    // Randomly set initialization variables

  for(i = 0; i < G->deckCount[G->whoseTurn]; i++)
  {
    if(G->deck[G->whoseTurn][i]>3 && G->deck[G->whoseTurn][i]<7)
      treasureCountDeckDiscard++;
  }
  for(i = 0; i < G->discardCount[G->whoseTurn]; i++)
  {
    if(G->discard[G->whoseTurn][i]>3 && G->discard[G->whoseTurn][i]<7)
      treasureCountDeckDiscard++;
  }
  for(i = 0; i < G->handCount[G->whoseTurn]; i++)
  {
    if(G->hand[G->whoseTurn][i]>3 && G->hand[G->whoseTurn][i]<7)
      precount++;
  }
  printf("Precount = %i\n",precount);
  cardEffect(adventurer, -1, -1, -1, G, position, (int *)-1);  // cardEffect_adventurer(G);
  for(i = 0; i < G->handCount[G->whoseTurn]; i++)
  {
    if(G->hand[G->whoseTurn][i]>3 && G->hand[G->whoseTurn][i]<7)
      postcount++;
  }
  printf("Postcount = %i\n",postcount);
  if(treasureCountDeckDiscard>1)
    assert(postcount == precount+2);
  else
    assert(postcount == precount+treasureCountDeckDiscard);

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
    ret = testCardAdventurer(&G);
    assert(!ret);
  }

  printf("Test Successful.\n");
  return 0;

}
