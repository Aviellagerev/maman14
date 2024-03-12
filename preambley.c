//
// Created by aviel on 06/03/2024.
//

#include "preambley.h"
#include "table.h"
#include "table.c"
#include "states.h"
#include "states.c"
#include "library.h"
int test() {
    printf("eat by balls pre\n");
    return 69;
}

void read_source_file(FILE *src, FILE *des) {
    char line[81] = {0};
    char line_cpy[81] = {0};
    char *token, c;
    int i = 0;
    void (*resetCurrentLineCounter)() = &resetCurrentLineNumber;
    (*resetCurrentLineCounter)();
    while (((c = fgetc(src)) != EOF)) {
        line[i++] = c;
        if (i >= 81 - 2 && !isspace(c)) {
            c = '\n';
        }
        if (c == '\n') {
            if (i > 0) {
                strncpy(line_cpy, line, i);
                token = strtok(line_cpy, " \t\n\f\r");
                if (token != NULL)
                    write_destenation_file(line, token, src, des);

                memset(line_cpy, 0, i);

                memset(line, 0, i);

                i = 0;
            }
        }
    }
    if (i > 0)
    {
        strcpy(line_cpy, line);
        token = strtok(line_cpy, " \t\n\f\r");
        if (token != NULL)
            write_destenation_file(line, token, src, des);
    }
}

void write_destination_file(char *line,char *token,FILE *src, FILE *des){
    void (*currentLineNumberPlusPlus)() = &increaseCurrentLineNumber;
    static char macroName[MAX_LABEL_LEN] = {0}, *next;
    static Bool isReadingMacro = False;
    static long start = 0, end = 0;
    extern Bool isPossiblyUseOfMacro(char *s);
    extern Bool isMacroOpening(char *s);
    extern Bool isMacroClosing(char *s);
    extern Bool isLegalMacroName(char *s);
    extern Item *addMacro(char *name, int start, int end);
    extern Item *updateMacro(char *name, int start, int end);
    extern Item *getMacro(char *s);
    if(!isReadingMacro){
        if(!isMacroOpening(token)){
            fprintf(des,"%s",line);
            (*currentLineNumberPlusPlus)();
        }
    }
    if (!isPossiblyUseOfMacro(token) && !isMacroOpening(token) && !isMacroClosing(token))
        return;

    if (!isPossiblyUseOfMacro(token) && !isMacroOpening(token) && !isMacroClosing(token))
        return;

    if (isMacroOpening(token))
    {
        next = strtok(NULL, " \t\n\f\r");

        if (next == NULL)
        {

            return;
        }
        if (!isLegalMacroName(next))
        {

            return;
        }
        start = ftell(src);
        strcpy(macroName, next);
        isReadingMacro = True;
    }
    else if (isMacroClosing(token))
    {
        end = ftell(src) - strlen(line) + 1;
        addMacro(macroName, start, end);
        isReadingMacro = False;
        start = end = 0;
        memset(macroName, 0, MAX_LABEL_LEN);
    }
    else if (isPossiblyUseOfMacro(token))
    {
        Item *p = getMacro(token);
        if (p != NULL)
        {
            long c, toCopy = p->val.m.end - p->val.m.start;
            long lastPosition = 0;
            fseek(des, -strlen(line), SEEK_CUR);
            fprintf(des, "%s", "\0");
            lastPosition = ftell(src);
            fseek(src, p->val.m.start, SEEK_SET);

            while (--toCopy && (c = fgetc(src)) != EOF)
                fputc(c, des);

            fseek(src, lastPosition, SEEK_SET);
        }
    }

}