#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>


// remodel
int main() {
	int useCardEffect = 1;
	int card = remodel;
	int choice1 = embargo;
	int choice2 = adventurer;
	int choice3 = 0;
	int handPos = 0;
	int bonus = 0;
	int isTrash = 0;
	int isFlag = 0;

	printf("Remodel Card Test\n");

	int seed = 3;
	int players = 3;
	struct gameState G;
	struct gameState G2;
	
	int k[10] = { adventurer, remodel, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	initializeGame(players, k, seed, &G);
	memcpy(&G2, &G, sizeof(struct gameState));

	if(useCardEffect == 0) {
		remodelEffect(&G, handPos, choice1, choice2);
	} else {
		cardEffect(card, choice1, choice2, choice3, &G, handPos, &bonus);
	}

	int currPlayer = G.whoseTurn;
	int currPlayer2 = G2.whoseTurn;


	int toTrash = G2.hand[currPlayer2][choice1];
	if( getCost(toTrash) + 2 <= getCost(choice2)) {
		gainCard(choice2, &G2, isFlag, currPlayer2);
		discardCard(handPos, currPlayer2, &G2, isTrash);
		for(int c = 0; c < G2.handCount[currPlayer2]; c++) {
			if(G2.hand[currPlayer2][c] == toTrash) {
				discardCard(c, currPlayer2, &G2, isTrash);
				break;
			}
		}
	}


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
