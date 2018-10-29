#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

// updateCoins input player, gameState, bonus:
// updateCoins return 0;
// updateCoins modifies gameState->coins;
int main() {

	printf("updateCoins() Test\n");
	int fail = 0;
	int player = 0;
	int players = 3;
	int seed = 3;

	struct gameState G;


	int testBonusLst[4] = {-1, 0, 1, 9999};

	int k[10] = { adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

	initializeGame(players, k, seed, &G);

	int handCnt = G.handCount[player];

	int valueLst[treasure_map + 1] = {
		0, //curse
		0, //estate
		0, //duchy
		0, //province
		
		1, //copper
		2, //silver
		3, //gold
		
		0, //adventurer
		0, //council_room
		0, //feast
		0, //gardens
		0, //mine

		0, //remodel
		0, //smithy
		0, //village

		0, //baron
		0, //great_hall
		0, //minion
		0, //steward
		0, //tribute

		0, //ambassador
		0, //cutpurse
		0, //embargo
		0, //outpost
		0, //salvager
		0, //sea_hag
		0  //treasure_map
	};

	for(int bonusIdx = 0; bonusIdx < 4; bonusIdx++) {
		int bonus = testBonusLst[bonusIdx];

		for(int card = curse; card <= treasure_map; card++) {
			int expected = 0;

			if(bonus > 0) {
				expected += bonus;
			}

			printf("card: %d, bonus: %d, value:%d\n", card, bonus, valueLst[card]);
			for(int cardNum = 0; cardNum < handCnt; cardNum++) {
				G.hand[player][cardNum] = card;
				
				if(card >= copper && card <= gold) {
					expected++;
				}
				
				if(card >= silver && card <= gold) {
					expected++;
				}

				if(card == gold) {
					expected++;
				}
			}

			updateCoins(player, &G, bonus);
			printf("coins: %d\n", G.coins);
			printf("expected: %d\n", expected);
			if(expected == G.coins) {
				printf("PASS\n\n");
			} else {
				fail++;
				printf("FAIL\n\n");

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
