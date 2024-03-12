//
// Created by Aviel on 11/03/2024.
//
#include "table.h"
static Item *symbols[HASHSIZE] = {0};
static Item *macros[HASHSIZE] = {0};
static unsigned entriesCount = 0;
static unsigned externalCount = 0;
/*might move to another file */

char *cloneString(char *s)
{
    char *copy;
    if (!(*s))
        return "";
    copy = (char *)calloc(strlen(s), sizeof(char *));
    strcpy(copy, s);
    return copy;
}

void initTables()
{
    extern unsigned externalCount, entriesCount;
    int i =0;
    externalCount = entriesCount = 0;
    while (i < HASHSIZE)
    {
        symbols[i] = NULL;
        macros[i] = NULL;
        i++;
    }
}
unsigned hash(char *s)
{
    unsigned hashval = 1;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}
Item *search(char *s, ItemType type)
{
    Item *np;
    int i = hash(s);
    for (np = (type == Symbol ? symbols[i] : macros[i]); np != NULL; np = np->next)
        if (!strcmp(s, np->name))
            return np;

    return NULL;
}
Item *add_item(char *name ,ItemType type){
    unsigned hashval;
    Item *np;
    np = (Item *)malloc(sizeof(Item));

    if (np == NULL)
    {
        return NULL; /*error handiling here later*/
    }
    else{
        np->name = cloneString(name);
        if(type==Macro){
            np->val.m.start = -1;
            np->val.m.end = -1;
        }
        hashval = hash(name);
        np->next = (type == Symbol ? symbols[hashval] : macros[hashval]);
        if (type == Symbol)
            symbols[hashval] = np;
        else
            macros[hashval] = np;
    }
    return np;
}
Item *getMacro(char *s)
{
    return search(s, Macro);
}

Item *addMacro(char *name, int start, int end)
{
    Item *macro = search(name,Macro);

    if (macro != NULL)
    {
        return NULL; /*error here */
    }
    else
    {
        macro = add_item(name, Macro);

        if (start != -1)
            macro->val.m.start = start;
        if (end != -1)
            macro->val.m.end = end;
    }

    return macro;
}


