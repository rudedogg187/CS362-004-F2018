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
int testCard = council_room;

int main(int argc, char** argv) {
	//print test name
	printf("This is random card tester: Council Room\n");

	srand(time(NULL));

	//gameState struct to be used by test
	struct gameState G;

	//gameState to be copy of original game
	struct gameState G2;

	int handPos;
	int player;
	int discardCountBefore;
	//int expectedHandCount;
	//int expectedDiscardCount;
	int failCnt = 0;
	int fail;
	int comp;	
	//int handError = 0;
	//int discardError = 0;
	int handCountsBefore[MAX_PLAYERS];
	int deckCountsBefore[MAX_PLAYERS];

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

		for(int i =0; i < G.numPlayers; i++) {
			handCountsBefore[i] = setPlayerHandRandom(i, &G);
			deckCountsBefore[i] = setPlayerDeckRandom(i, &G);
		}

		discardCountBefore = setPlayerDiscardRandom(player, &G);

		handPos = rand() % handCountsBefore[player];

		printf("Before Hand Count: %d\n", handCountsBefore[player]);
		printf("Before Discard Count: %d\n", discardCountBefore);
		printf("Hand Position: %d\n", handPos);

		//duplicate game to G2 game
		memcpy(&G2, &G, sizeof(struct gameState));

		comp = memcmp(&G, &G2, sizeof(struct gameState));
		fail += myAssert(comp, 0);	

		councilRoomEffect(&G2, handPos);

		for(int i =0; i < G.numPlayers; i++) {
			if(i != player) {
				G.handCount[i] = G.handCount[i] + 1;
				G.deckCount[i] = G.deckCount[i] - 1;
				if(myAssert(getPlayerHandCount(i, &G), getPlayerHandCount(i, &G2))) {
					fail++;
					printf("Other Player (i) Hand Count Fail\n");
				}
				if(myAssert(getPlayerDeckCount(i, &G), getPlayerDeckCount(i, &G2))) {
					fail++;
					printf("Other Player (i) Deck Count Fail\n");
				}
			} else {
				G.handCount[i] = G.handCount[i] + 3;
				G.deckCount[i] = G.deckCount[i] - 4;
				if(myAssert(getPlayerHandCount(i, &G), getPlayerHandCount(i, &G2))) {
					fail++;
					printf("Current Player Hand Count Fail\n");
				}
				if(myAssert(getPlayerDeckCount(i, &G), getPlayerDeckCount(i, &G2))) {
					fail++;
					printf("Current Player Deck Count Fail\n");
				}
			}
			printf("\nPlayer[%d] Hand Count Before: %d\n", i,  handCountsBefore[i]);
			printf("Player[%d] Hand Count After: %d\n", i,  getPlayerHandCount(i, &G2));
			printf("Player[%d] Deck Count Before: %d\n", i,  deckCountsBefore[i]);
			printf("Player[%d] Deck Count After: %d\n", i,  getPlayerDeckCount(i, &G2));
		}



		if(fail > 0) {
			failCnt++;
		}

		/*************************************************/
		printf("\n------------\n\n");
	}

	
	printf("%d out of %d tests passed\n", (testCnt - failCnt), testCnt); 
	return 0;
}

