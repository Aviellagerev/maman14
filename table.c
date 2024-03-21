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
void printMacroTable()
{
    int i = 0;
    printf("\n\t ~ MACRO TABLE ~ \n");
    printf("\tname\tstart\tend");
    while (i < HASHSIZE)
    {
        if (macros[i] != NULL)
            printMacroItem(macros[i]);
        i++;
    }
    printf("\n\n");
}
int printMacroItem(Item *item)
{

    printf("\n\t%s\t %5d\t%6d", item->name, item->val.m.start, item->val.m.end);
    if (item->next != NULL)
        printMacroItem(item->next);
    return 0;
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
    unsigned hash_value = 1;
    for (hash_value = 0; *s != '\0'; s++)
        hash_value = *s + 31 * hash_value;
    return hash_value % HASHSIZE;
}
void freeHashTable(ItemType type)
{

    int i = 0;
    while (i < HASHSIZE)
    {

        if (type == Symbol)
        {
            if (symbols[i] != NULL)
                freeTableItem(symbols[i]);
        }
        else
        {
            if (macros[i] != NULL)
                freeTableItem(macros[i]);
        }

        i++;
    }
}
void freeTableItem(Item *item)
{
    if (item->next != NULL)
        freeTableItem(item->next);
    /*     printf("item->name:%s\n", item->name); */
    free(item);
    return;
}

Item *search(char *s, ItemType type)
{
    unsigned hash_value;
    Item *node_pointer;
    int i = hash(s);
    for (node_pointer = (type == Symbol ? symbols[i] : macros[i]); node_pointer != NULL; node_pointer = node_pointer->next)
        if (!strcmp(s, node_pointer->name))
            return node_pointer;

    return NULL;
}
Item *add_item(char *name ,ItemType type){

    unsigned hash_value;
    Item *node_pointer;
    node_pointer = (Item *)malloc(sizeof(Item));

    if (node_pointer == NULL)
    {
     /*error here */
        return NULL;
    }
    else
    {
        node_pointer->name = cloneString(name);
        if (type == Symbol)
        {
            node_pointer->val.s.attrs.code = 0;
            node_pointer->val.s.attrs.entry = 0;
            node_pointer->val.s.attrs.external = 0;
            node_pointer->val.s.attrs.data = 0;
            node_pointer->val.s.attrs.mdefine=0;
            node_pointer->val.s.base = 0;
            node_pointer->val.s.value = 0;
            node_pointer->val.s.offset = 0;
        }
        else if (type == Macro) {
            node_pointer->val.m.start = -1;
            node_pointer->val.m.end = -1;
        }
        hash_value = hash(name);
        node_pointer->next = (type == Symbol ? symbols[hash_value] : macros[hash_value]);
        if (type == Symbol)
            symbols[hash_value] = node_pointer;
        else
            macros[hash_value] = node_pointer;
    }

    return node_pointer;
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
Bool addSymbol(char *name, unsigned value, unsigned is_code, unsigned is_data, unsigned is_entry, unsigned is_external,unsigned is_mdefine)
{
    unsigned base;
    unsigned offset;
    Item *pointer;

    if (name[strlen(name) - 1] == ':')
        name[strlen(name) - 1] = '\0';
/*
    if (!verifyLabelNamingAndPrintErrors(name))
        return False;
    pointer = lookup(name, Symbol);
    if (pointer != NULL)
        return updateSymbol(pointer, value, isCode, isData, isEntry, isExternal);
        */
    else
    {
        pointer = add_item(name, Symbol);
        offset = value % 16;
        base = value - offset;
        pointer->val.s.value = value;
        pointer->val.s.base = base;
        pointer->val.s.offset = offset;
        pointer->val.s.attrs.code = is_code ? 1 : 0;
        pointer->val.s.attrs.entry = is_entry ? 1 : 0;
        pointer->val.s.attrs.external = is_external ? 1 : 0;
        pointer->val.s.attrs.data = is_data ? 1 : 0;
    }

    return True;
}

