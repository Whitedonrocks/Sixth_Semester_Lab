%{
#include "y.tab.h"
%}

%%

[a-zA-Z][a-zA-Z0-9]*    { return VARIABLE; }
[ \t]                   ;
\n                      { return 0; }
.                       { return INVALID; }

%%

int yywrap()
{
    return 1;
}