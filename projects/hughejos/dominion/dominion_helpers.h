#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state, 
		int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);



int adventureEffect(struct gameState *state);
int councilRoomEffect(struct gameState *state, int handPos);
int featEffect(struct gameState *state, int handPos, int choice);
int mineEffect(struct gameState *state, int handPos, int choice1, 
		int choice2);
int remodelEffect(struct gameState *state, int handPos, int choice1, 
		int choice2);
int smithyEffect(struct gameState *state, int handPos);

int cardEffect(int card, int choice1, int choice2, int choice3, 
	       struct gameState *state, int handPos, int *bonus);

#endif
