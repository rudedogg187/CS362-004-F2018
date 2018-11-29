#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>


// smithy
int main() {
	//int useCardEffect = 1;
	int card = smithy;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int handPos = 0;
	int bonus = 0;
	int isTrash = 0;

	printf("Smithy Card Test\n");

	int seed = 3;
	int players = 3;
	struct gameState G;
	struct gameState G2;
	
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	initializeGame(players, k, seed, &G);
	memcpy(&G2, &G, sizeof(struct gameState));
/*
	if(useCardEffect == 0) {
		smithyEffect(&G, handPos);
	} else {
		cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);
	}
*/
	cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);

	int currPlayer = G.whoseTurn;

	int currPlayer2 = G2.whoseTurn;

	for(int draw = 0; draw < 3; draw++) {
		drawCard(currPlayer2, &G2);
	}

	discardCard(handPos, currPlayer2, &G2, isTrash);

	int cardCnt = G.handCount[currPlayer];
	int cardCnt2 = G2.handCount[currPlayer];

	int cmp = memcmp(&G, &G2, sizeof(struct gameState));

	if(cardCnt != cardCnt2) {
		printf("FAIL - CARD COUNTS DIFFER BY %d\n", cardCnt - cardCnt2);
	}

	if(cmp != 0) {
		printf("FAIL - GAME-STATE and TEST GAME-STATE DIFFER (%d)\n", cmp);
	}

	if(cmp == 0 && cardCnt == cardCnt2) {
		printf("PASS - TEST COMPLETE\n");
	}
	
	//assert(cardCnt == cardCnt2);
	//assert(cmp == 0);

	//printf("cp: %d, hc: %d\n", currPlayer, cardCnt);
	//printf("cp: %d, hc: %d\n", currPlayer2, cardCnt2);
	//printf("cmp: %d\n", cmp);

	return 0;

}
