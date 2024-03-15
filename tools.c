//
// Created by aviel on 15/03/2024.
//

#include "tools.h"
Bool isMacroOpening(char *s)
{
    return !strcmp(s, "mcr") ? True : False;
}
Bool isMacroClosing(char *s)
{
    return !strcmp(s, "endmcr") ? True : False;
}
Bool isPossiblyUseOfMacro(char *s)
{
    return !isMacroClosing(s) && !isMacroOpening(s)/*&& !isOperation(s) && !isComment(s) && !isInstructionStrict(s)&&!isLabelDeclaration(s) */;
}

Bool isLegalMacroName(char *s)
{
    return True;/*!isInstructionStrict(s) && !isOperation(s) ? True : False;*/
}
/*Bool isLabelDeclarationStrict(char *s)
{
    return s[strlen(s) - 1] == ':' ? True : False;
}

Bool isLabelDeclaration(char *s)
{
    return strchr(s, ':') != NULL ? True : False;
}*/