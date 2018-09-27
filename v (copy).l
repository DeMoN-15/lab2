%{
#include "y.tab.h" 
%}
%option noyywrap
%%
[a-zA-Z] {return ID;}
[0-9]+ {return NUMBER;}
[ \t] {;}
\n {return 0;}
. {return yytext[0];}
%%
