#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

// isGameOver input gameState struct:
// isGameOver return 1 if true; return 0 if false;
int main() {
	printf("isGameOver() Test\n");

	int fail = 0;

	// min number of players required for game
	int minPlayers = 2;
	// max number of players allowed for game
	int maxPlayers = MAX_PLAYERS;

	// declare a gameState struct
	struct gameState G;

	// random seed for game init	
	int seed = 3;

	int provinceCnt;

	int isOver;

	// cards for game
	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };
	// iterate from min number of players to max number of players

	for(int players = minPlayers; players <= maxPlayers; players++) {
		initializeGame(players, k, seed, &G);
		printf(" G.numPlayers: %d\n", G.numPlayers);
		provinceCnt = G.supplyCount[province];

		while(provinceCnt > 0) {
			G.supplyCount[province]--;
			provinceCnt--;
			printf("Provence Count: %d\n", provinceCnt);

			if(provinceCnt == 0) {
				isOver = 1;	
			} else {
				isOver = 0;
			}

			printf("Game Over: %d\n", isOver);

			//assert(isOver == isGameOver(&G));
			if(isOver == isGameOver(&G)) {
				printf("PASS\n");
			} else {
				printf("FAIL\n");
				fail++;
			}

		}
		
	}

	if(fail > 0) {
		printf("FAILED TEST\n");
	} else {
		printf("PASSED TEST\n");
	}


	return 0;

}
