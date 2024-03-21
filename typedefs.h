#ifndef MAMAN14_TYPEDEFS_H
#define MAMAN14_TYPEDEFS_H
#include "constants.h"
typedef struct {
    int start;
    int end;
} MacroData;
typedef enum
{
    emptyDeclaretionOfEntryOrExternalVariables,

    emptyEntryDeclaretion,
    emptyExternalDeclaretion,
    instructionHasNoArguments,
    emptyDataDeclaretion

} Warning;
typedef struct
{
    unsigned int code : 1;
    unsigned int data : 1;
    unsigned int entry : 1;
    unsigned int external : 1;
    unsigned int mdefine:1;

} Attributes;

typedef struct
{

    unsigned value;
    unsigned base;
    unsigned offset;
    Attributes attrs;
} SymbolData;
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
        SymbolData s;
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
