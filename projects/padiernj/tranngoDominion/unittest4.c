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


#define TESTFUNCTION "isGameOver"

int main() {
    int i;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &G);

  printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);

  // ----------- TEST 1: Checking If The Current Game Is Over --------------
  printf("TEST 1: Checking If The Current Game Is Over\n");
  i = isGameOver(&G);
  assert(i == 0);
  printf("Function isGameOver passes test when called right after initializeGame is called\n");

  G.supplyCount[province] = 0;
  i = isGameOver(&G);
  assert(i == 1);
  printf("Function isGameOver passes test when called after supplyCount[province] is set to 0\n");

  G.supplyCount[province] = 1;
  i = isGameOver(&G);
  assert(i == 0);

  G.supplyCount[1] = 0;
  G.supplyCount[2] = 0;
  G.supplyCount[3] = 0;

  i = isGameOver(&G);
  assert(i == 1);
  printf("Function isGameOver passes test when called after 3 supply piles are set to 0\n");


  printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);


  return 0;
}
