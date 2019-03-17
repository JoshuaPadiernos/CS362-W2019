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


#define TESTFUNCTION "getCost"

int main() {
  int i, j;
  const char* cardNames[] = {
    "curse",
    "estate",
    "duchy",
    "province",
    "copper",
    "silver",
    "gold",
    "adventurer",
    "council_room",
    "feast",
    "gardens",
    "mine",
    "remodel",
    "smithy",
    "village",
    "baron",
    "great_hall",
    "minion",
    "steward",
    "tribute",
    "ambassador",
    "cutpurse",
    "embargo",
    "outpost",
    "salvager",
    "sea_hag",
    "treasure_map",
    "Non-existant_Card"
  };

  long int cardCosts[] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4, -1};
  
  printf("----------------- Testing Function: %s ----------------\n", TESTFUNCTION);
  
  // ----------- TEST 1: Checking If getCost Checks Cards' Cost Properly --------------
  printf("TEST 1: Checking If getCost Checks Cards' Cost Properly\n");

  for (i = 0; i < 28; i++) {
  	j = getCost(i);	
  	assert(j == cardCosts[i]);
  	printf("%s costs %d coins\n", cardNames[i], j);
  }
  
  printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTFUNCTION);
  
  return 0;
}
