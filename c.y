%{
#include<stdio.h>
#include<stdlib.h>
  int yylex(); 
  %}
%token NUMBER
%left '+' '-'
%left '*' '/'
%%
stmt:exp{printf("%d",$$); return 0;};
exp:exp'+'exp {$$=$1+$3;}
|exp'-'exp {$$=$1-$3;}
|exp'*'exp {$$=$1*$3;}
|exp'/'exp {$$=$1/$3;}
|NUMBER {$$=$1;}
;
%%
void main()
{
  printf("enter expr : \n");
  yyparse();
  exit(0);
}
void yyerror()
{
  printf("invalid exp\n");
  exit(0);
}
