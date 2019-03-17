/*
	Used cardtest4.c sample as skeleton for this file
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>


#define TESTFUNCTION "whoseTurn"

int main() {
    int i, j;
    int seed = 1000;
    int numPlayers = 4;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);

	// ----------- TEST 1: Checking Which Players' Turn It Is --------------
	printf("TEST 1: Checking Which Players' Turn It Is\n");

	for (i = 0; i < 10; i++) {
		initializeGame(numPlayers, k, seed, &G);
		j = whoseTurn(&G);
		assert(j == G.whoseTurn);
		printf("It is Player %d\'s turn\n", j+1);
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);


	return 0;
}
