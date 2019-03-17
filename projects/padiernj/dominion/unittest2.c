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


#define TESTFUNCTION "updateCoins"

int main() {
    int i;
    int seed = 1000;
    int numPlayers = 2;
	struct gameState G;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};


	printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);

	// ----------- TEST 1: Checking If updateCoins Updates # of Coins --------------
	printf("TEST 1: Checking If updateCoins Updates # of Coins Properly\n");

	for (i = 0; i < 10; i++) {
		initializeGame(numPlayers, k, seed, &G);
		G.coins = 0;
		G.hand[0][0] = copper;
		G.hand[0][1] = silver;
		G.hand[0][2] = gold;
		G.hand[0][3] = gold;
		G.hand[0][4] = silver;
		updateCoins(0, &G, 0);
		assert(G.coins == 11);
		printf("G.coins has %d coins\n", G.coins);
	}

	for (i = 0; i < 10; i++) {
		initializeGame(numPlayers, k, seed, &G);
		G.hand[0][0] = adventurer;
		G.hand[0][1] = embargo;
		G.hand[0][2] = village;
		G.hand[0][3] = minion;
		G.hand[0][4] = mine;
		updateCoins(0, &G, 0);
		assert(G.coins == 0);
		printf("G.coins has %d coins\n", G.coins);
	}

	printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);


	return 0;
}
