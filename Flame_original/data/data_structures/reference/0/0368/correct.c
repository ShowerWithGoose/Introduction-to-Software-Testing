#include <stdio.h>
#include <string.h>
char ch[100000];
int main()
{
	gets(ch);
	int i = 0,j,k;
	for(i = 0;ch[i]!='\0';i++)
	{
		printf("%c",ch[i]);
		if(ch[i+1]=='-')
		{
			if(ch[i]>='a' && ch[i]<='z' && ch[i+2]>ch[i] && ch[i+2]<='z')
			{
				for(j=ch[i]+1;j<=ch[i+2]-1;j++)
					printf("%c",j);
				i++;
			}
			else if(ch[i]>='A' && ch[i]<='Z' && ch[i+2]>ch[i] && ch[i+2]<='Z')
			{
				for(j=ch[i]+1;j<=ch[i+2]-1;j++)
					printf("%c",j);
				i++;
			}
			else if(ch[i]>='0' && ch[i]<='9' && ch[i+2]>ch[i] && ch[i+2]<='9')
			{
				for(j=ch[i]+1;j<=ch[i+2]-1;j++)
					printf("%c",j);
				i++;
			}
		}
	}
	return 0;
}

