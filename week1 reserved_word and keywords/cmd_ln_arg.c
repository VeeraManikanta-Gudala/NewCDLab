#include<stdio.h>
void main(int argc,char* argv[])
{
FILE* f1;
char c[100];
f1=fopen(argv[1],"r");
if(f1!=NULL)
{
	while(fgets(c,99,f1))
		printf("%s",c);
}
else
	printf("File couldn't be opened\n");
fclose(f1);
}
