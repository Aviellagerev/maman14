//
// Created by aviel on 18/03/2024.
//

#ifndef MAMAN14_MEMORY_H
#define MAMAN14_MEMORY_H
#include "constants.h"

void increaseDataCounter(int amount);
/* @ Function: increaseDataCounter
   @ Arguments: The function gets int amount- the amount of addresses in the memory the data counter holds.
   @ Description: The function increases the data counter by amount- the amount of addresses in the memory the data counter holds.
   The function doesn't return any value.
*/

void increaseInstructionCounter(int amount);
/* @ Function: increaseInstructionCounter
   @ Arguments: The function gets int amount- the amount of addresses in the memory the instruction counter holds.
   @ Description: The function increases the instruction counter by amount- the amount of addresses in the memory the instruction counter holds.
   The function does'nt return any value.
*/

void resetMemoryCounters();
/* @ Function: resetMemoryCounters
   @ Arguments: The function gets no arguments.
   @ Description: The function reset the counter that counts the exact amount of space required to generate the compiled image.
   The function doesn't return any value.
*/
unsigned getDC();
unsigned getIC();
unsigned getICF();
unsigned getDCF();

#endif //MAMAN14_MEMORY_H
