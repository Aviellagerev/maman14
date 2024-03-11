//
// Created by Aviel on 11/03/2024.
//

#ifndef MAMAN14_TABLE_H
#define MAMAN14_TABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include "constants.h"


typedef struct
{
    int start;
    int end;
} MacroData;
/*
 * typedef struct
{
    unsigned value;
    unsigned base;
    unsigned offset;
   Attributes attrs; add later
} SymbolData;
*/

typedef enum
{
    Macro,
    Symbol
} ItemType;
typedef struct Item
{
    char *name;
    union
    {
       /* SymbolData s;*/
        MacroData m;
    } val;
    struct Item *next;
} Item;
char *cloneString(char *s);
void initTables();
unsigned hash(char *s);
Item *search(char *s, ItemType type);
Item *add_item(char *name ,ItemType type);
Item *getMacro(char *s);
Item *addMacro(char *name, int start, int end);
int test2();
#endif //MAMAN14_TABLE_H
