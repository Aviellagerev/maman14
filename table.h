//
// Created by Aviel on 11/03/2024.
//

#ifndef MAMAN14_TABLE_H
#define MAMAN14_TABLE_H
#include "library.h"
#include "typedefs.h"

/*
 * typedef struct
{
    unsigned value;
    unsigned base;
    unsigned offset;
   Attributes attrs; add later
} SymbolData;
*/


char *cloneString(char *s);
void initTables();
unsigned hash(char *s);
Item *search(char *s, ItemType type);
Item *add_item(char *name ,ItemType type);
Item *getMacro(char *s);
Item *addMacro(char *name, int start, int end);
int test2();
#endif //MAMAN14_TABLE_H
