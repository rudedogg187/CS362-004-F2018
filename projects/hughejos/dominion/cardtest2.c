#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>


// adventurer
int main() {
	int useCardEffect = 1;
	int card = adventurer;
	int choice1 = 0;
	int choice2 = 0;
	int choice3 = 0;
	int handPos = 0;
	int bonus = 0;
	//int isTrash = 0;
	int treasureCnt = 0;
	int tempHand[MAX_HAND];
	int tempCnt = 0;
	

	printf("Adventurer Card Test\n");

	int seed = 3;
	int players = 3;
	struct gameState G;
	struct gameState G2;
	
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	initializeGame(players, k, seed, &G);
	memcpy(&G2, &G, sizeof(struct gameState));

	int currPlayer = G.whoseTurn;
	int currPlayer2 = G2.whoseTurn;

	if(useCardEffect == 0) {
		adventurerEffect(&G);
	} else {
		cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);
	}

	for(int treasure= 0; treasure < 2; treasure++) {
		if(G2.deckCount[currPlayer] < 1) {
			printf("HERE\n");
			shuffle(currPlayer2, &G2);
		}

		drawCard(currPlayer2, &G2);
		int cardDrawn = G2.hand[currPlayer2][G2.handCount[currPlayer2] - 1];

		if(cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
			treasureCnt++;	
		} else {
			tempHand[tempCnt] = cardDrawn;
			G2.handCount[currPlayer2]--;
			tempCnt ++;
		}
	}

	while(tempCnt - 1 >= 0) {
		G2.discard[currPlayer2][G2.discardCount[currPlayer2]++ ] = tempHand[tempCnt - 1];
		tempCnt = tempCnt -1;

	}


	int cardCnt = G.handCount[currPlayer];
	int cardCnt2 = G2.handCount[currPlayer];

	int cmp = memcmp(&G, &G2, sizeof(struct gameState));

	if(cardCnt != cardCnt2) {
		printf("FAIL - CARD COUNTS DIFFER BY %d\n", cardCnt - cardCnt2);
	}

	if(cmp != 0) {
		printf("FAIL - GAME-STATE and TEST GAME STATE DIFFER (%d)\n", cmp);
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
