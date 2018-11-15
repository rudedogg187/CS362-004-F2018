#include "dominion.h"
#include "dominion_helpers.h"
#include "random_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//number of random test to perform
int testCnt = 200;

//card to test;
int testCard = adventurer;
int main(int argc, char** argv) {
	//print test name
	printf("This is random card tester: Adventurer\n");

	//pseudo random number gen
	srand(time(NULL));

	//gameState struct to be used by test
	struct gameState G;

	//gameState to be copy of original game
	struct gameState G2;

	//track treasures drawn
	int drawnTreasure;
	//hand to hold non-treasurs drawn
	int tempHand[MAX_HAND];
	//capture drawn card	
	int cardDrawn;
	//track number of non-trearuses drawn
	int tempHandCount;
	//track size of players hand
	int handCount;
	
	//int discardCount;

	//int handPos;
	int player;
	int discardCountBefore;
	//int expectedHandCount;
	//int expectedDiscardCount;
	int failCnt = 0;
	int fail;
	int comp;	
	int handCountBefore;
	int deckCountBefore;


	//loop through tests
	for(int testNbr = 0; testNbr < testCnt; testNbr++) {
		//call to create new random test
		newRandomTestGame(testCard, &G);
		printf("\n\n------------\n");
		printf("Test: %d)  Players: %d\n\n", testNbr, G.numPlayers);
		/*************************************************/
		fail = 0;
		player = getRandomPlayer(&G);
		printf("Random Player: %d\n", player);		

		handCountBefore = setPlayerHandRandom(player, &G);
		deckCountBefore = setPlayerDeckRandom(player, &G);

		discardCountBefore = setPlayerDiscardRandom(player, &G);

		drawnTreasure = rand() % 2;
	
		printf("drawnTreasereBefore: %d\n", drawnTreasure);
		//handPos = rand() % handCountsBefore[player];

		printf("Before Hand Count: %d\n", handCountBefore);
		printf("Before Deck Count: %d\n", deckCountBefore);
		printf("Before Discard Count: %d\n", discardCountBefore);
		//printf("Hand Position: %d\n", handPos);

		//duplicate game to G2 game
		memcpy(&G2, &G, sizeof(struct gameState));

		comp = memcmp(&G, &G2, sizeof(struct gameState));
		fail += myAssert(comp, 0);	

		adventurerEffect(&G2);

		tempHandCount = setRandomTempHand(tempHand, &G);

		while(drawnTreasure<2){
			//if (state->deckCount[currentPlayer] < 1) {
			if (G.deckCount[player] >= 1) {
				//shuffle(currentPlayer, &G2);
			}
			drawCard(player, &G);
			handCount = G.handCount[player];
			cardDrawn = G.hand[player][handCount - 1];
			if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
				drawnTreasure++;
			} else {
				tempHand[tempHandCount]=cardDrawn;
				G.handCount[player]--;
				tempHandCount++;
			}
		}

		while(tempHandCount - 1 >= 0){
			G.discard[player][G.discardCount[player]++] = tempHand[tempHandCount - 1];
			tempHandCount--;
		}

		if(myAssert(getPlayerHandCount(player, &G2), handCountBefore + 2)) {
			printf("Fail hand count\n");
			failCnt++;
		} else {
			printf("PASS\n");
		}
		printf("handCountAfter: %d\n", getPlayerHandCount(player, &G2));
		printf("drawnTreasereAfter: %d\n", drawnTreasure);
		if(fail > 0) {
			failCnt++;
		}

		/*************************************************/
		printf("\n------------\n\n");
	}

	
	printf("%d out of %d tests passed\n", (testCnt - failCnt), testCnt); 
	return 0;
}

