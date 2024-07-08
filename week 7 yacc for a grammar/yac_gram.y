%{
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
int yylex();
int yyerror();
int getREindex(const char*);
signed char prod[MAX][MAX];
int count=0,i,j;
char temp[200],temp2[200];
%}

%token ALPHABET
%left '|'
%left '.'
%nonassoc '*' '+'

%%
S : re '\n' {
printf("This is the rightmost derivation--\n");
for(i=count-1;i>=0;--i)
	if(i==count-1)
	{
		printf("\nre=>");
		strcpy(temp,prod[i]);
		printf("%s",prod[i]);
	}
	else
	{
		printf("\n=>");
		j=getREindex(temp);
		temp[j]='\0';
		sprintf(temp2, "%s%s%s",temp,prod[i],(temp+j+2));
		printf("%s",temp2);
		strcpy(temp,temp2);
	}
printf("\n");
exit(0);
}
re: ALPHABET {temp[0]=yylval;temp[1]='\0';strcpy(prod[count++],temp);}
| '(' re ')' {strcpy(prod[count++],"(re)");}
| re '*' {strcpy(prod[count++],"re*");}
| re '+' {strcpy(prod[count++],"re+");}
| re '|' re {strcpy(prod[count++],"re | re");}
| re '.' re {strcpy(prod[count++],"re . re");}
;
%%
int main()
{
	yyparse();
	return 0;
}
int yylex()
{
	signed char ch=getchar();
	yylval=ch;
	if(isalpha(ch))
		return ALPHABET;
	return ch;
}
int yyerror()
{
	fprintf(stderr,"Invalid Regular Expression!\n");
	exit(1);
	return 0;
}
int getREindex(const char *str)
{
	int i=strlen(str)-1;
	for(;i>=0;--i)
		if(str[i]=='e' && str[i-1]=='r')
			return i-1;
}
