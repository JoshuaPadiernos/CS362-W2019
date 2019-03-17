/*
Joshua Padienros
Assignment 4
3/2/19
NOTES: Used sample cardtest4.c as a skeleton/reference
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define TESTCARD "village"

int main() {
	int newCards = 0;
	int discarded = 1;
	int shuffledCards = 0;
	int i, numHPassed = 0, numDPassed = 0, numAPassed = 0;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int numOfActions = 0;
    int seed;
    int numPlayers = 2;
    int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	seed = Random() * 1000;
	// initialize a game state and player cards
	initializeGame(numPlayers, k, seed, &G);

	for (i = 0; i < 2000; i++) {
		thisPlayer = floor(Random() * 2);
		G.deckCount[thisPlayer] = floor(Random() * MAX_DECK);
		G.discardCount[thisPlayer] = floor(Random() * MAX_DECK);
		G.handCount[thisPlayer] = floor(Random() * MAX_HAND);


		printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
		// ----------- TEST 1: choice1 = 1 = +2 cards --------------
		printf("TESTING choice1: +1 Card, +2 Action\n");

		memcpy(&testG, &G, sizeof(struct gameState));
		choice1 = 1, newCards = 1, numOfActions = 2;
		cardEffect(village, choice1, choice2, choice3, &testG, handpos, &bonus);


		printf("EXPECTED Hand count = %d, ACTUAL Hand count = %d\n", G.handCount[thisPlayer] + newCards - discarded, testG.handCount[thisPlayer]);
		if (G.handCount[thisPlayer] + newCards - discarded == testG.handCount[thisPlayer]) {
			printf("%s hand count: Passed\n", TESTCARD);
			numHPassed++;
		} else {
			printf("%s hand count: Failed\n", TESTCARD);
		}

		printf("EXPECTED Deck count = %d, ACTUAL Deck count = %d\n", G.deckCount[thisPlayer] - newCards + shuffledCards, testG.deckCount[thisPlayer]);
		if (G.deckCount[thisPlayer] - newCards + shuffledCards == testG.deckCount[thisPlayer]) {
			printf("%s deck count: Passed\n", TESTCARD);
			numDPassed++;
		} else {
			printf("%s deck count: Failed\n", TESTCARD);
		}

		printf("EXPECTED Action count = %d, ACTUAL Action count = %d\n", G.numActions + numOfActions, testG.numActions);
		if (G.numActions + numOfActions == testG.numActions) {
			printf("%s Number of Actions count: Passed\n", TESTCARD);
			numAPassed++;
		} else {
			printf("%s Number of Actions count: Failed\n", TESTCARD);
		}
	}
	printf("%d/%d Tested Hand Counts Passed\n",numHPassed, i);
	printf("%d/%d Tested Deck Counts Passed\n",numDPassed, i);
	printf("%d/%d Tested Number of Actions Count Passed\n",numAPassed, i);
	return 0;
}