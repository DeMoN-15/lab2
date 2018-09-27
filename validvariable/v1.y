%{
#include<stdio.h>
#include<stdlib.h>
  %}

%token NUMBER ID UND NL

%%
stmt: variable NL {printf("valid identifiers\n"); exit(0);}
;
variable: ID alphanumeric
;
alphanumeric: ID alphanumeric | NUMBER alphanumeric | UND alphanumeric | ID | NUMBER | UND
;

%%

int yyerror(char *msg)
{
  printf("Invalid variable\n");
  exit(0);
}

main()
{
  printf("enter the variable: \n");
  yyparse();
}
