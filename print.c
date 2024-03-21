//
// Created by aviel on 21/03/2024.
//
#include "print.h"
#include "states.h"
static void (*currentLineNumberPlusPlus)() = &increaseCurrentLineNumber;
static void (*resetCurrentLineCounter)() = &resetCurrentLineNumber;
void print_as_code(FILE *des){
    State (*globalState)() = &getGlobalState;
    void (*setState)(State) = &setGlobalState;
    int c = 0, i = 0;
    char line[MAX_LINE_LEN] = {0};
    Bool isValidCode = True;
    State nextState;

    while((c=fgetc(des))!=EOF){
        if(isspace(c&&i>0)){
            line[i++]=' ';
        }
        else if (!isspace(c)) {
            line[i++] = c;
        }
        if (i >= MAX_LINE_LEN - 2) {
            c = '\n';
        }
        if (c == '\n'){
            if(i>0){
                isValidCode = read_line(line) && isValidCode;
                memset(line, 0, MAX_LINE_LEN);
                i = 0;
            }
        }
    }
    if (i > 0)
        isValidCode = read_line(line) && isValidCode;

    if (!isValidCode)
        nextState = assemblyCodeFailedToCompile;
    else
        nextState = (*globalState)() == firstRun ? secondRun : exportFiles;

    (*resetCurrentLineCounter)();
    (*setState)(nextState);
}
Bool read_line(char *line){

    State (*globalState)() = &getGlobalState;
    char lineCopy[MAX_LINE_LEN] = {0};
    Bool result = True;
    char *token;
    strcpy(lineCopy, line);
    token = ((*globalState)() == firstRun) ? strtok(lineCopy, " \t\n\f\r") : strtok(lineCopy, ", \t\n\f\r");
    result = print_line(token, line);
    (*currentLineNumberPlusPlus)();
    return result;

}
Bool print_line(char *token, char *line){
    State (*globalState)() = &getGlobalState;
    Bool is_valid = True;
    if (is_comment(token)) {
        return True;
    }
    if(is_mdefine(token)){

    }
}

