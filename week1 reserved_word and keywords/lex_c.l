identifier [a-zA-Z_][a-zA-Z0-9_]*
%{
#include<stdio.h>
int COMMENT=0;
int idc=0,resc=0;
%}
%%
#.* 	{ printf("\n%s PREPROCESSOR DIRECTIVE",yytext); }
int|float|char|double|while|for|do|if|break|continue|void|switch|case|long|struct|const|typedef|return|else|goto		{resc++; printf("\n\t%s RESERVED WORD",yytext);}
"/*" 	{COMMENT = 1;}		{printf("\n\n\t%s is a COMMENT\n",yytext);}
"*/"	 {COMMENT = 0;} 		{printf("\n\n\t%s is a COMMENT\n",yytext);}
{identifier}\( 				{ if(!COMMENT) printf("\n%s FUNCTION ",yytext); }
\{	 					{ if(!COMMENT) printf("\n%s BLOCK-BEGINS",yytext); }
\} 						{ if(!COMMENT) printf("\n%s BLOCK-ENDS",yytext); }
{identifier}(\[[0-9]*\])?	 		{ idc++;if(!COMMENT) printf("\n%s IDENTIFIER",yytext); }
\".*\"					          { if(!COMMENT) printf("\n%s STRING",yytext); }
[0-9]+ 					{ if(!COMMENT) printf("\n%s CONSTANT",yytext); }
"="|"+="|"-="|"*="|"/="	 		{ if(!COMMENT) printf("\n\t%s ASSIGNMENT OPERATOR",yytext); }
"<="|">="|"<"|"=="|">"	 		{ if(!COMMENT) printf("\n\t%s RELATIONAL OPERATOR",yytext); }
"+"|"-"|"*"|"/"|"%"		          { if(!COMMENT) printf("\n\t%s ARITHMATIC OPERATOR",yytext); }
%%
int main(int argc,char **argv)
{
if (argc > 1)
{
FILE *file;
file = fopen(argv[1],"r");
if(!file)
{
printf("could not open %s \n",argv[1]);
exit(0);
}
yyin = file;
}
yylex();
printf("\n\n");
printf("Identifier count:%d\n",idc);
printf("Reserved words count:%d\n",resc);
return 1;
}
int yywrap()
{
return 1;
}
