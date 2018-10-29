#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

// whoseTurn input: gameState struct
// whoseTurn return: current player
int main() {
	printf("whoseTurn() Test\n");

	int fail = 0;

	// minium number of players requried for game
	int minPlayers = 2;
	// maximum number of players allowd for game
	int maxPlayers = MAX_PLAYERS;

	int testCases[4] = {-1, 0, 1, 9999};

	// declare a gameState struct
	struct gameState G;

	// counters to track tries and successes
	int try = 0;
	int pass = 0;

	// iterate from min number of players to max number of players
	for(int players = minPlayers; players <= maxPlayers; players++) {
		// set game state players to current number of player in iteratiion
		G.numPlayers = players;
		// print the number of players involved in current test
		printf(" G.numPlayers: %d\n", G.numPlayers);

		// iterate through test case array - turn number to test
		for(int c = 0; c < 4; c++) {
			// save the index of the test case to a var
			int testCase = testCases[c];	
			// print the turn number involved in current test
			printf("  Testing Turn Number: %d\n", testCase);

			// save curent turn as player 1 - number of players in current game
			int currTurn = testCase % players + 1;
			// set the game states whose turn member to currTurn var
			G.whoseTurn = currTurn;
			
			// assert that whoseTurn() returns the value just set	
			assert(currTurn == whoseTurn(&G));
			// increment try counter for each attempt
			try++;
			// if test passes
			if(currTurn == whoseTurn(&G)) { 
				// print pass message
				printf("  PASS\n\n");
				// increment pass counter with each success
				pass++;
			} else {
				// if fail print message
				printf("  FAIL\n\n");
				fail++;
			};
			
		}
	}
	
	// print attempts, successes and success percentage
	//printf("%d of %d %f&& passed\n\n", pass, try, (pass * 1.0)  / try);

	if(fail > 0) {
		printf("FAILED TEST\n");
	} else {
		printf("PASSED TEST\n");
	}

	return 0;

}
