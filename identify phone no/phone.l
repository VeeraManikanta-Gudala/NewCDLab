%{
#include<stdio.h>
%}
%%
[/+]91[6-9][0-9]{9}|[6-9][0-9]{9} {printf("%s is Valid number\n\n",yytext);}
\n ;
.* {printf("%s is Invalid number\n\n",yytext);}
%%
int main(int argc,char **argv)
{
	if(argc>1)
	{
		FILE *f;
		f=fopen(argv[1],"r");
		if(!f)
		{
			printf("Couldn't open %s\n",argv[1]);
			exit(0);
		}
	yyin=f;
	}
yylex();
}
int yywrap()
{
	return 1;
}
