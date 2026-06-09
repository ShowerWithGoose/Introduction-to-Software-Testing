#include <stdio.h>
#include <string.h>
int main()
{
	char c[10000];
	int i,j,k;
	gets(c);
	k=strlen(c);
	for(i=0;i<k;i++)
	{
		if(c[i]!='-')
		{
		printf("%c",c[i]);}
		if(c[i]=='-')
		{
			if(c[i-1]<='9'&&c[i+1]<='9'&&c[i-1]<c[i+1])
			{
				for(j=c[i-1]+1;j<c[i+1];j++)
				printf("%c",j);
			}
			else if(c[i-1]>='A'&&c[i+1]>='A'&&c[i-1]<='Z'&&c[i+1]<='Z'&&c[i-1]<c[i+1])
				{
					for(j=c[i-1]+1;j<c[i+1];j++)
					printf("%c",j);
				}
			else if(c[i-1]>='a'&&c[i+1]>='a'&&c[i-1]<='z'&&c[i+1]<='z'&&c[i-1]<c[i+1])
				{
					for(j=c[i-1]+1;j<c[i+1];j++)
					printf("%c",j);
				}
			else
			printf("%c",c[i]);
		}
	}
	return 0;
}

