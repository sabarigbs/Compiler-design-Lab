%{
# include "y.tab.h"
#include<math.h>
#include<stdio.h>
%}
%%
[0-9]+             {yylval.dval = atof(yytext);
                    return NUMBER; }
sin |
SIN   {return SINE;}

COS |
cos   {return SINE;}

mem  {return MEM;}
[\t];
\$  {return 0;}
\n|.  return yytext[0];
%%
int yywrap()
{
return 1;
}





