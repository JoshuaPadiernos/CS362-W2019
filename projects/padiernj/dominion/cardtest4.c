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


#define TESTCARD "village"

int main() {
    int i, j, l, m;
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

  // ----------- TEST 1: Checking If Village Card's Effect Works Properly --------------
  printf("TEST 1: Draw +1 Card, +2 Action\n");
  
  i = numHandCards(&G);
  j = G.numActions;
  printf("Player has %d cards in hand\n", i);
  printf("Player has %d actions available\n", j);
  assert(cardEffect(village, choice1, choice2, choice3, &G, 0, NULL) == 0);
  m = numHandCards(&G);
  l = G.numActions;
  assert(m == i);
  printf("Player has %d cards in hand after %s is played\n", m, TESTCARD);
  assert(l == j+2);
  printf("Player has %d actions available after %s is played\n", l, TESTCARD);


  printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

  return 0;
}
