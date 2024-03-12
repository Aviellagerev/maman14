#ifndef MAMAN14_TYPEDEFS_H
#define MAMAN14_TYPEDEFS_H
#include "constants.h"
typedef struct {
    int start;
    int end;
} MacroData;

typedef enum {
    False = 0,
    True = 1
} Bool;

typedef enum {
    Macro,
    Symbol
} ItemType;

typedef struct Item {
    char *name;
    union {
        MacroData m;
    } val;
    struct Item *next;
} Item;
typedef enum
{
    assemblyCodeFailedToCompile,
    startProgram,
    parsingMacros,
    firstRun,
    secondRun,
    exportFiles,
    exitProgram
} State;
#endif
