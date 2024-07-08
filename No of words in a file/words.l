%{
#include<stdio.h>
int word=0;
%}
%%
" " {word++;}
\n {word++;}
\t {word++;}
. ;
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
printf("\n\n");
printf("No of words in file:%d\n",word);
}
int yywrap()
{
	return 1;
}
