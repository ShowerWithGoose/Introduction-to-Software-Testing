#include<stdio.h>
#include<string.h>
int main()
{
	char c[1000];
	gets(c);
	int i;
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]!='-')
		printf("%c",c[i]);
		else if(c[i]=='-')
		{
			if(c[i-1]>='a'&&c[i-1]<='z'&&c[i+1]>='a'&&c[i+1]<='z')
			{
				int j;
				for(j=1;j<c[i+1]-c[i-1];j++)
				printf("%c",c[i-1]+j);
			}
			else if(c[i-1]>='A'&&c[i-1]<='Z'&&c[i+1]>='A'&&c[i+1]<='Z')
			{
				int j;
				for(j=1;j<c[i+1]-c[i-1];j++)
				printf("%c",c[i-1]+j);
			}
			else if(c[i-1]>='0'&&c[i-1]<='9'&&c[i+1]>='0'&&c[i+1]<='9')
			{
				int j;
				for(j=1;j<c[i+1]-c[i-1];j++)
				printf("%c",c[i-1]+j);
			}
			else
			printf("%c",c[i]);
		}
	}
	return 0;
}

