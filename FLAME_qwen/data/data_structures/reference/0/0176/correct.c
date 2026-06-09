#include<stdio.h>
#include<string.h>
int main()
{
	char c[1000000];
	gets(c);
	int i,j=0;
	printf("%c",c[0]);
	for(i=1;i<strlen(c)-1;i++)
	{
		if(c[i]!='-')
		printf("%c",c[i]);
		else if(c[i]=='-')
		{
			if(c[i-1]>='0'&&c[i+1]<='9')
				for(j=1;j<c[i+1]-c[i-1];j++)
					printf("%c",c[i-1]+j);
			else if(c[i-1]>='a'&&c[i+1]<='z')	
				for(j=1;j<c[i+1]-c[i-1];j++)
					printf("%c",c[i-1]+j);
			else if	(c[i-1]>='A'&&c[i+1]<='Z')		
				for(j=1;j<c[i+1]-c[i-1];j++)
					printf("%c",c[i-1]+j);
			else printf("%c",c[i]);		
		}
	}
	printf("%c",c[strlen(c)-1]);
	return 0;
}



