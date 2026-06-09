#include <stdio.h>
#include <string.h>
char f[600];
 
int main()
{
	scanf("%s",f);
	int i,j;
	if(f[0]=='0'&&f[1]=='.')
	{
		for(i=2;f[i]=='0';i++);
		if(f[i+1]=='\0')
		{
			printf("%ce-%d",f[i],i-1);
		}
		else
		{
			printf("%c.",f[i]);
			for(j=i+1;f[j]!='\0';j++)
				printf("%c",f[j]);
			printf("e-%d",i-1);
		}
	}
	else
	{
		for(i=0;f[i]!='.';i++);
		printf("%c.",f[0]);
		for(j=1;f[j]!='\0';j++)
		{
			if(f[j]!='.')
				printf("%c",f[j]);
		}
		printf("e%d",i-1);
	}
	return 0;
}



