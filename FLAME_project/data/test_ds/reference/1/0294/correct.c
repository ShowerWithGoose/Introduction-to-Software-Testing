#include <stdio.h> 
#include <string.h>

int main()
{
	char ch[1000];
	gets(ch);
	int i,j;
	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i+1]!='-')
			printf("%c",ch[i]);
		else
		{
			if(ch[i]>='0'&&ch[i]<='9'&&ch[i+2]>='0'&&ch[i+2]<='9'&&ch[i+2]>ch[i])
			{
				for(j=0;j<ch[i+2]-ch[i];j++)
				{
					printf("%c",ch[i]+j);
				}
				i+=1;
			}
			else if(ch[i]>='A'&&ch[i]<='Z'&&ch[i+2]>='A'&&ch[i+2]<='Z'&&ch[i+2]>ch[i])
			{
				for(j=0;j<ch[i+2]-ch[i];j++)
				{
					printf("%c",ch[i]+j);
				}
				i+=1;
			}
			else if(ch[i]>='a'&&ch[i]<='z'&&ch[i+2]>='a'&&ch[i+2]<='z'&&ch[i+2]>ch[i])
			{
				for(j=0;j<ch[i+2]-ch[i];j++)
				{
					printf("%c",ch[i]+j);
				}
				i+=1;
			}
			else
				printf("%c",ch[i]);
		}
	}
	return 0;
}

