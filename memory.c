//
// Created by aviel on 18/03/2024.
//

#include "memory.h"
unsigned static IC = MEMORY_START;
unsigned static DC = 0;
unsigned static ICF = 0;
unsigned static DCF = 0;

void increaseDataCounter(int amount)
{
    DC += amount;
}

void increaseInstructionCounter(int amount)
{
    IC += amount;
}

unsigned getDC() { return DC; }

unsigned getIC() { return IC; }

unsigned getICF() { return ICF; }

unsigned getDCF() { return DCF; }

void resetMemoryCounters()
{
    IC = MEMORY_START;
    DC = 0;
    ICF = 0;
    DCF = 0;
}