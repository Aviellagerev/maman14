//
// Created by aviel on 21/03/2024.
//

#ifndef MAMAN14_PRINT_H
#define MAMAN14_PRINT_H
#include "library.h"
#include "typedefs.h"
#include "states.h"
#include "tools.h"
Bool read_line(char *line);
void print_as_code(FILE *des);
Bool print_line(char *token, char *line);
#endif //MAMAN14_PRINT_H
