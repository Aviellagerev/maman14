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
char *trim_from_left(char *s)
{
    while (isspace(*s) && *s != '\0')
        s++;
    return s;
}
Bool is_comment(char *s)
{
    s = trim_from_left(s);
    return s[0] == ';' ? True : False;
}
Bool is_mdefine(char*s){
    return s[0]=='.'?True:False;
}
/*Bool isLabelDeclarationStrict(char *s)
{
    return s[strlen(s) - 1] == ':' ? True : False;
}

Bool isLabelDeclaration(char *s)
{
    return strchr(s, ':') != NULL ? True : False;
}*/