#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

// getCost input cardNumber:
// getCost return cost of card;
int main() {
	printf("getCost() Test\n");
	int fail = 0;
	int costLst[treasure_map + 1] = {
		0, //curse
		2, //estate
		5, //duchy
		8, //province
		
		0, //copper
		3, //silver
		6, //gold
		
		6, //adventurer
		5, //council_room
		4, //feast
		4, //gardens
		5, //mine

		4, //remodel
		4, //smithy
		3, //village

		4, //baron
		3, //great_hall
		5, //minion
		3, //steward
		5, //tribute

		3, //ambassador
		4, //cutpurse
		2, //embargo
		5, //outpost
		4, //salvager
		4, //sea_hag
		4  //treasure_map
	};

	for(int card = curse; card <= treasure_map; card++) {
		printf("card: %d cost:%d\n", card, costLst[card]);
		printf("getCost():%d\n", getCost(card));

		if(getCost(card) != costLst[card]) {
			printf("FAIL\n\n");
			fail++;
		} else {
			printf("PASS\n\n");
		}

		//assert(getCost(card) == costLst[card]);
	}

	if(fail > 0) {
		printf("FAILED TEST\n");
	} else {
		printf("PASSED TEST\n");
	}
		
	


	return 0;

}
