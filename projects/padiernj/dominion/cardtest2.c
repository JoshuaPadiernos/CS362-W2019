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


#define TESTCARD "smithy"

int main() {
    int i, j;
    int seed = 1000;
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
      sea_hag, tribute, smithy, council_room};
    int choice1, choice2, choice3;
    choice1 = choice2 = choice3 = 0;

  // initialize a game state and player cards
  initializeGame(numPlayers, k, seed, &G);

  printf("----------------- Testing Function: %s ----------------\n", TESTCARD);

  // ----------- TEST 1: Checking If Smithy Card's Effect Works Properly --------------
  printf("TEST 1: Draw +3 Cards\n");
  
  i = numHandCards(&G);
  printf("Player has %d cards in hand\n", i);
  assert(cardEffect(smithy, choice1, choice2, choice3, &G, 0, NULL) == 0);
  j = numHandCards(&G);
  printf("Player has %d cards in hand after %s is played\n", j, TESTCARD);
  assert(j == i+2);


  printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

  return 0;
}
