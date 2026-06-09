#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char nu[105]; 
int main(int argc, char *argv[]) {
	gets(nu);
	int i=0,len=strlen(nu),j=0;
	if(nu[0]=='0')
	{
		i=2;
		while(nu[i]=='0') i++;j=i-1;
		printf("%c",nu[i]);
		if(nu[i+1]!='\0') printf(".");
		i++;
		for(;i<len;i++)
		printf("%c",nu[i]);
		printf("e%d",-j);
	}
	else if(nu[1]=='.')
	{
		strcat(nu,"e0");
		puts(nu);
	}
	else 
	{
		i=1;
		printf("%c.",nu[0]);
		while(nu[i++]!='.'); j=i-2;
		for(i=1;i<len;i++)
		if(nu[i]!='.')
		printf("%c",nu[i]);
		printf("e%d\n",j);
	}
	return 0;
}

