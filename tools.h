//
// Created by Aviel on 12/03/2024.
//

#ifndef MAMAN14_TOOLS_H
#define MAMAN14_TOOLS_H
#include "typedefs.h"
#include "library.h"
Bool isMacroOpening(char *s);
Bool isMacroClosing(char *s);
Bool isPossiblyUseOfMacro(char *s);
Bool isLegalMacroName(char *s);


/*Bool isLabelDeclaration(char *s);
Bool isLabelDeclarationStrict(char *s);*/
#endif //MAMAN14_TOOLS_H
