#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{	char toex[10005];
	gets(toex);
	for(int i=0;i<=strlen(toex);i++)
	{	if(toex[i]!='-')
		printf("%c",toex[i]);
		else
		{	if(isdigit(toex[i-1])&&isdigit(toex[i+1])&&toex[i+1]-toex[i-1]>0)
			for(char j=toex[i-1]+1;j<=toex[i+1]-1;j++)
			printf("%c",j);
			else if(isupper(toex[i-1])&&isupper(toex[i+1])&&toex[i+1]-toex[i-1]>0)
			for(char j=toex[i-1]+1;j<=toex[i+1]-1;j++)
			printf("%c",j);
			else if(islower(toex[i-1])&&islower(toex[i+1])&&toex[i+1]-toex[i-1]>0)
			for(char j=toex[i-1]+1;j<=toex[i+1]-1;j++)
			printf("%c",j);
			else
			printf("-");
		}
	}
	return 0;
} 

