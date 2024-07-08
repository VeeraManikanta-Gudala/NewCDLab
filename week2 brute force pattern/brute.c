#include<stdio.h>
#include<stdlib.h>
#include<regex.h>
void searchPatternInFile(const char *filename,const char *pattern)
{
	FILE *file=fopen(filename,"r");
	if(file==NULL)
	{
		printf("Error openeing file %s\n",filename);
		return;
	}
int sz,ln=0,flag=0;
printf("Enter max line length:");
scanf("%d",&sz);
char line[sz];
regex_t regex;
int ret=regcomp(&regex,pattern,REG_EXTENDED);
if(ret)
{
	printf("Could not compile regular expression\n");
	fclose(file);
	return;
}
while(fgets(line,sz,file)!=NULL)
{
	ln++;
	if(regexec(&regex,line,0,NULL,0)==0)
	{
		printf("Match found at line %d:%s",ln,line);
		flag=1;
	}
}
if(flag==0)
{
	printf("Pattern not found\n");
}
regfree(&regex);
fclose(file);
}
int main(int argc,char **argv)
{
	const char *filename=argv[1];
	char pattern[100];
	printf("Enter the pattern to search for:");
	scanf("%[^\n]s",pattern);
	searchPatternInFile(filename,pattern);
	return 0;
}
