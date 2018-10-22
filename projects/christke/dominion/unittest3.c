/* Unit test for getCost function */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main(void)
{
  int cardCosts[] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
  int output;

  // Test for correct values
  for (int i = 0; i<27; i++)
  {
    output = getCost(i);
    printf("Output = %i; Expected = %i\n",output,cardCosts[i]);
    assert(output == cardCosts[i]);
  }

  // Boundary case: card < 0
  output = getCost(-1);
  printf("Output = %i; Expected = %i\n",output,-1);
  assert(output == -1);

  // Boundary case: card > 27 (maximum number of cards in enum)
  output = getCost(treasure_map+1);
  printf("Output = %i; Expected = %i\n",output,-1);
  assert(output == -1);

  printf("Test Passed\n");
  return 0;
}
