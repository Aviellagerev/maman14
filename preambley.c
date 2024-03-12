//
// Created by aviel on 06/03/2024.
//

#include "preambley.h"
#include "table.h"

int test() {
    printf("eat by balls pre\n");
    return 69;
}

void read_source_file(FILE *src, FILE *des) {
    char line[81] = {0};
    char line_cpy[81] = {0};
    char *token, c;
    int i = 0;
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
        strcpy(des, line);
        token = strtok(des, " \t\n\f\r");
        if (token != NULL)
            write_destenation_file(line, token, src, des);
    }
}

void write_destination_file(char *line,char *token,FILE *src, FILE *des){

}