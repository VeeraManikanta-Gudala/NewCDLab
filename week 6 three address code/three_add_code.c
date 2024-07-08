#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "str.h"
void pm();
void plus();
void div1();
char* strrev(char*);
int i,ch,j,l,addr=100;
char ex[10],Exp[10],exp1[10],Exp2[10],id1[5],op[5],id2[5];
void main()
{
while(1)
{
	printf("\n1.Assignment 2.Aritrhmatic 3.Relational 4.Exit\nEnter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter the expression with assignement operator:");
			scanf("%s",Exp);
			l=strlen(Exp);
			Exp2[0]='\0';
			i=0;
			while(Exp[i]!='=')
				i++;
			strncat(Exp2,Exp,i);
			strrev(Exp);
			exp1[0]='\0';
			strncat(exp1,Exp,l-(i+1));
			strrev(exp1);
			printf("Three address code:\ntemp=%s\n%s=temp\n",exp1,Exp2);
			break;
		case 2:
			printf("\nEnter expression with arithmatic operator:");
			scanf("%s",ex);
			strcpy(Exp,ex);
			l=strlen(Exp);			
			exp1[0]='\0';
			for(i=0;i<l;i++)
			{
				if(Exp[i]=='+'||Exp[i]=='-')
				{
					if(Exp[i+2]=='/'||Exp[i+2]=='*')
					{
						pm();
						break;
					}
					else
					{
					plus();
					break;
					}
				}
				else if(Exp[i]=='/'||Exp[i]=='*')
				{
					div1();
					break;
				}
			}
			break;
		case 3:
			printf("\nEnter the expression with relational operator:");
			scanf("%s%s%s",id1,op,id2);
			if(((strcmp(op,"<")==0)||(strcmp(op,">")==0)||strcmp(op,"<=")==0||strcmp(op,">=")==0||strcmp(op,"==")==0||strcmp(op,"!=")==0)==0)
				printf("Expression error\n");
			else
			{
				printf("\n%d\tif %s%s%s goto %d",addr,id1,op,id2,addr+3);
				addr++;
				printf("\n%d\t T:=0",addr);
				addr++;
				printf("\n%d\t goto %d",addr,addr+2);
				addr++;
				printf("\n%d\t T:=1",addr);
			}
			break;
		case 4:
			exit(0);
		}
	}
}
void pm()
{
	strrev(Exp);
	j=l-i-1;
	strncat(exp1,Exp,j);
	printf("Three address code:\ntemp=%s\ntemp1=%c%ctemp\n",exp1,Exp[j+1],Exp[j]);
}
void div1()
{
	strncat(exp1,Exp,i+2);
	printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,Exp[i+1],Exp[i+3]);
}
void plus()
{
	strncat(exp1,Exp,i+2);
	printf("Three address code:\ntemp=%s\ntemp1=temp%c%c\n",exp1,Exp[i+2],Exp[i+3]);
}
char* strrev(char *str){
    if(!str || !*str) return str;
    char *end = str + strlen(str) -1;
    char temp;
    while(end>str){
        temp = *str;
        *str++ = *end;
        *end-- = temp;
    }
    return str;
}
