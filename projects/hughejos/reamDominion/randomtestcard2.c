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
int testCnt = 500;

//card to test;
int testCard = smithy;

int main(int argc, char** argv) {
	//print test name
	printf("This is random card tester: Smithy\n");

	srand(time(NULL));

	//gameState struct to be used by test
	struct gameState G;

	//gameState to be copy of original game
	struct gameState G2;

	int handPos;
	int player;
	//int deckCountBefore;
	int handCountBefore;
	int discardCountBefore;
	int expectedHandCount;
	int expectedDiscardCount;
	int failCnt = 0;
	int fail;
	int comp;	
	int handError = 0;
	int discardError = 0;

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

		//deckCountBefore = setPlayerDeckRandom(player, &G);
		setPlayerDeckRandom(player, &G);
		handCountBefore = setPlayerHandRandom(player, &G);
		discardCountBefore = setPlayerDiscardRandom(player, &G);

		expectedHandCount = handCountBefore + 3;
		expectedDiscardCount = discardCountBefore + 1;
		
		handPos = rand() % handCountBefore;

		printf("Before Hand Count: %d\n", handCountBefore);
		printf("Before Discard Count: %d\n", discardCountBefore);
		printf("Hand Position: %d\n", handPos);

		//duplicate game to G2 game
		memcpy(&G2, &G, sizeof(struct gameState));

		comp = memcmp(&G, &G2, sizeof(struct gameState));
		fail += myAssert(comp, 0);	

		//smithyEffect(&G2, handPos);
		smithyEffect(player, &G2, handPos);

		if(myAssert(getPlayerHandCount(player, &G2), expectedHandCount)) {
			printf("Hand FAIL\n");
			fail++;
			handError++;
		}
	
		if(myAssert(getPlayerDiscardCount(player, &G2), expectedDiscardCount)) {
			printf("Discard FAIL\n");
			fail++;
			discardError++;
		}

		printf("handcount: %d\n", getPlayerHandCount(player, &G));	
		printf("handcount: %d\n", getPlayerHandCount(player, &G2));	

		if(fail > 0) {
			failCnt++;
		}
	
		/*************************************************/
		printf("\n------------\n\n");
	}

	
	printf("%d out of %d tests passed\n", (testCnt - failCnt), testCnt); 
	printf("%d hand errors\n", handError);
	printf("%d discard errors\n", discardError);
	return 0;
}

