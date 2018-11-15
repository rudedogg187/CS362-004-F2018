#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int myAssert(int valueIs, int valueShouldBe) {
	if(valueIs == valueShouldBe) {
		//printf("PASS\n");
		return 0;
	}
	//printf("FAIL\n");
	return 1;

}

int isCardInSet(int card, int* cardSet, int setSize) {
	for(int i = 0; i < setSize; i++) {
		//printf("cond: %d == %d\n", cardSet[i], card);
		//printf("res: %d\n", cardSet[i] == card);
		if(cardSet[i] == card) {
			//printf("retun 1\n");
			return 1;
		}
	}
	//printf("retun 0\n\n");

	return  0;
}

void printCardSet(int* cardSet, int setSize) {
	printf("cards in set\n");
	for(int i = 0; i < setSize; i++) {
		printf(" Card %d: %d\n", i, cardSet[i]);
	}
}


void fillKingdomSet(int testCard, int* kLst, int setSize) {
	//int for king card	
	int kingCard;
	
	//position to put card
	int cardPos = 0;

	//bool to test if king card is alread in king set
	int isIn;

	//set first card in king card array to test card
	kLst[cardPos] = testCard;

	//assert that test card is in king card set
//	myAssert(kLst[cardPos], testCard);

	//decrease cards needed by one
	cardPos++;

	//array of all kingdom cards	
	int kMasterLst[20] = {
		adventurer, 
		council_room,
		feast,
		gardens,
		mine,
		remodel,
		smithy,
		village,
		baron,
		great_hall,
		minion,
		steward,
		tribute,
		ambassador,
		cutpurse,
		embargo,
		outpost,
		salvager,
		sea_hag,
		treasure_map
	};

	int r;
	//do/while to fill king card array with unique king cards
	do {
		r = rand() % 20;
		//set king card to one of the 20 king cards in the king master list
		kingCard = kMasterLst[r];

		//test if the king card is already in king card set
		isIn = isCardInSet(kingCard, kLst, setSize);

		//if king card is not already in king card set
		if(isIn == 0) {
			//put the king card at the current card postion in set
			kLst[cardPos] = kingCard;
			//move to the next card position
			cardPos++;
		}

	//continue until all king card set is filled with unique king cards
	} while (cardPos < setSize);

}

void newRandomTestGame(int testCard, struct gameState* G) {
	//int to hold random seed
	int seed = rand();
	//int to hold random # of players (2, 3, 4)
	int players = 2 + (seed % 3);
	//int for king set size;
	int setSize = 10;

	int kSet[10] = { 66, 66, 66, 66, 66, 66, 66, 66, 66, 66 };
//	int kSet[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

	//null out game struct
	memset(G, 0, sizeof(&G));
	fillKingdomSet(testCard, kSet, setSize);

	//print number of players and random seed used for test game
//	printf("Players: %d,  Seed:%d\n", players, seed);
	//print king cards for test game
//	printCardSet(kSet, setSize);
	
	initializeGame(players, kSet, seed, G);

}

void setCurrentPlayer(int player, struct gameState* G) {
	G->whoseTurn = player;

}

int getNumPlayers(struct gameState* G) {
	return G->numPlayers;

}

int setPlayerDeckRandom(int player, struct gameState* G) {
	int r = rand();
	int card;
	int deckCount = 10 + (r % (MAX_DECK / G->numPlayers));
	G->deckCount[player] = deckCount;	

	for(int i = 0; i < deckCount; i++) {
		card = rand() % 27;
		G->deck[player][i] = card;

	}
	return deckCount;
}

int setPlayerHandRandom(int player, struct gameState* G) {
	int r = rand();
	int card;
	int handCount = 3 +  (r % (G->deckCount[player] - 3));
	G->handCount[player] = handCount;	

	for(int i = 0; i < handCount; i++) {
		card = G->deck[player][i];
		G->hand[player][i] = card;

	}
	return handCount;
}

int setRandomTempHand(int tempHand[], struct gameState* G) {
	int r = rand();
	int player = whoseTurn(G);
	int deckCount = G->deckCount[player];
	int tempHandCount = r % (deckCount);
	int card;

	printf("deck count: %d\n", deckCount);	
	printf("temp hand count: %d\n", tempHandCount);	
	for(int i = 0; i < tempHandCount; i++) {
		card = G->deck[player][deckCount - i];
		tempHand[i] = card;

		G->deckCount[player]--;

	}

	return tempHandCount;

}

int setPlayerDiscardRandom(int player, struct gameState* G) {
	int r = rand();
	int card;
	int discardCount = (r % (G->deckCount[player] - G->handCount[player] ));
	G->discardCount[player] = discardCount;	

	for(int i = 0; i < discardCount; i++) {
		card = G->deck[player][i];
		G->discard[player][i] = card;

	}
	return discardCount;
}

int getRandomPlayer(struct gameState* G) {
	int players = G->numPlayers;
	int r = rand();

	for(int i = 0; i < (r % players); i++) {
		endTurn(G);
	} 
	
	int player = whoseTurn(G);
	return player;
}

int getPlayerDeckCount(int player, struct gameState* G) {
	int deckSize = G->deckCount[player];
	return deckSize;
}

int getPlayerHandCount(int player, struct gameState* G) {
	int handSize = G->handCount[player];
	return handSize;
}

int getPlayerDiscardCount(int player, struct gameState* G) {
	int discardCount = G->discardCount[player];
	return discardCount;
}

void setPlayerDeckCount(int player, int deckSize, struct gameState* G) {
	G->deckCount[player] = deckSize;
}

void randomizePlayerDeck(int player, struct gameState* G) {
	int deckSize = G->deckCount[player];

	for(int i = 0; i < deckSize; i++) {
		
		printf("  Card %d:  %d\n", i + 1, G->deck[player][i]);

	}


}

void printPlayerDeck(int player, struct gameState* G) {
	printf("Printing deck for Player %d\n", player);
	int deckSize = G->deckCount[player];

	for(int i = 0; i < deckSize; i++) {
		//printf("decksize %d\n", deckSize);	
		printf("  Card %d:  %d\n", i + 1, G->deck[player][i]);
	}
}

void printPlayerHand(int player, struct gameState* G) {
	printf("Printing hand for Player %d\n", player);
	int handSize = G->handCount[player];

	for(int i = 0; i < handSize; i++) {
		//printf("decksize %d\n", deckSize);	
		printf("  Card %d:  %d\n", i + 1, G->hand[player][i]);
	}
}

