#ifndef _RANDOM_HELPERS_H
#define _RANDOM_HELPERS_H

#include "dominion.h"

int myAssert(int valueIn, int valueShouldBe);
int isCardInSet(int card, int* cardSet, int setSize);
void printCardSet(int* cardSet, int setSize);
void fillKingdomSet(int testCard, int* kLst, int setSize);
void newRandomTestGame(int testCard, struct gameState* G);


int getNumPlayers(struct gameState* G);
int getRandomPlayer(struct gameState* G);
int getPlayerDeckCount(int player, struct gameState* G);
int getPlayerHandCount(int player, struct gameState* G);
int getPlayerDiscardCount(int player, struct gameState* G);

int setPlayerHandRandom(int player, struct gameState* G);
int setPlayerDeckRandom(int player, struct gameState* G);
int setPlayerDiscardRandom(int player, struct gameState* G);
int setRandomTempHand(int tempHand[], struct gameState* G);
void setPlayerDeckCount(int player, int deckSize, struct gameState* G);
void setCurrentPlayer(int player, struct gameState* G);

void printPlayerDeck(int player, struct gameState* G);

#endif
