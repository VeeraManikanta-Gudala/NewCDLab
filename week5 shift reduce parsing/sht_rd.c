#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char input[15],stack[15];
int ip_ptr=0,st_ptr=0,len,i;
char temp[2],temp2[2];
char act[15];
void check();
void main()
{
printf("\nGRAMMER\n\n E->E+E\n E->E/E\n E->E*E\n E->a/b");
printf("\nEnter the input string:");
scanf("%s",input);
printf("\n\t Stack implementaion table\n");
printf("\n Stack\t\t Input Symbol\t\t action\n"); 
printf("\n $\t\t%s$",input);
strcpy(act,"shift ");
temp[0]=input[ip_ptr];
temp[1]='\0';
strcat(act,temp);
len=strlen(input);
for(i=0;i<=len-1;i++)
{
	stack[st_ptr]=input[ip_ptr];
	stack[st_ptr+1]='\0';
	input[ip_ptr]=' ';
	ip_ptr++;
	printf("\n $%s\t\t%s$\t\t\t%s",stack,input,act);
	strcpy(act,"shift ");
	temp[0]=input[ip_ptr];
	temp[1]='\0';
	strcat(act,temp);
	check();
	st_ptr++;
}
st_ptr++;
check();
}
void check()
{
int flag=0;
temp2[0]=stack[st_ptr];
temp2[1]='\0';
if((!strcmp(temp2,"a"))||(!strcmp(temp2,"b")))
{
	stack[st_ptr]='E';
	if(!strcmp(temp2,"a"))
		printf("\n $%s\t\t%s$\t\t\tReduce E->a ",stack,input);
	else
		printf("\n $%s\t\t%s$\t\t\tReduce E->b ",stack,input);
	flag=1;
}
if((!strcmp(temp2,"+"))||(!strcmp(temp2,"*"))||(!strcmp(temp2,"/")))
	flag=1;
if((!strcmp(stack,"E+E"))||(!strcmp(stack,"E*E"))||(!strcmp(stack,"E/E")))
{
	st_ptr=0;
	if(!strcmp(stack,"E+E"))
	{
		strcpy(stack,"E");
		printf("\n $%s\t\t%s$\t\t\tReduce E->E+E",stack,input);
	}
	else if(!strcmp(stack,"E/E"))
	{
		strcpy(stack,"E");
		printf("\n $%s\t\t%s$\t\t\tReduce E->E/E",stack,input);
	}
	else if(!strcmp(stack,"E*E"))
	{
		strcpy(stack,"E");
		printf("\n $%s\t\t%s$\t\t\tReduce E->E*E",stack,input);
	}
	flag=1;
}
if(!strcmp(stack,"E")&&ip_ptr==len)
{
	printf("\n $%s\t\t%s$\t\t\tACCEPT\n",stack,input);
	exit(0);
}
if(flag==0)
{
	printf("\n $%s\t\t%s$\t\t\tReject\n",stack,input);
	exit(0);
}
if(strcmp(stack,"E")&&ip_ptr==len)
{
	printf("\nReject\n");
	exit(0);
}
return;
}
