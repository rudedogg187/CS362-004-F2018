#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

/* EXAMPLE UNIT TEST PROVIDED IN LECTURES */
int main() {
	int i = -66;
	int seed = 40;
	int numPlayer = 2;
	int maxBonus = 10;
	int p = -66; //player
	int r = -66; //int to catch return value
	int handCount = -66;
	int bonus = -66;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	struct gameState G;
	int maxHandCount = 5;

	int coppers[MAX_HAND];
	int silvers[MAX_HAND];
	int golds[MAX_HAND];

	printf("k[0]: %d , ", k[0]); 

	printf("%d, %d, %d, %d, ", i, seed, numPlayer, maxBonus); 
	printf("%d, %d, %d, ", p, r, handCount); 
	printf("%d, %d, ", bonus, maxHandCount); 
	printf("%d, %d, %d", coppers[0], silvers[0], golds[0]); 

	// fill coin arrays with coin values;
	for(i = 0; i < MAX_HAND; i++) {
		coppers[i] = copper;
		silvers[i] = silver;
		golds[i] = gold;
	}

	printf("\nTesting updateCoints():\n");

	//iterate through players
	for(p = 0; p < numPlayer; p++) {

		//iterate player x's treasure cards
		for(handCount = 1; handCount <= maxHandCount; handCount++) {	
			
			//iterate player x's bonus for each treasure card
			for(bonus = 0; bonus <= maxBonus; bonus++) {
				printf("Test player %d with %d treasure card(s) and %d bonus.\n", p, handCount, bonus);
				//set all bytes that make up G ptr to value of 23
				memset(&G, 23, sizeof(struct gameState));

				//initialize the game w/ players, cards randseed
				r = initializeGame(numPlayer, k, seed, &G);

				//set number of cards on hand for player
				G.handCount[p] = handCount;

				/** copper **/
				//set all cards to copper
				memcpy(G.hand[p], coppers, sizeof(int) * handCount);

				//update playes coints
				updateCoins(p, &G, bonus);	

				printf("COPPER: G.coins = %d, expected = %d\n", G.coins, handCount * 1 + bonus);
				//check if coin count is correct
				assert(G.coins == handCount * 1 + bonus);


				/** silver **/
				//set all cards to silver
				memcpy(G.hand[p], silvers, sizeof(int) * handCount);

				//update playes coints
				updateCoins(p, &G, bonus);	

				printf("SILVER: G.coins = %d, expected = %d\n", G.coins, handCount * 2 + bonus);
				//check if coin count is correct
				assert(G.coins == handCount * 2 + bonus);


				/** gold **/
				//set all cards to gold
				memcpy(G.hand[p], golds, sizeof(int) * handCount);

				//update playes coints
				updateCoins(p, &G, bonus);	

				printf("GOLD: G.coins = %d, expected = %d\n", G.coins, handCount * 3 + bonus);
				//check if coin count is correct
				assert(G.coins == handCount * 3 + bonus);
				
			}
		}
	}















	return 0;

}
