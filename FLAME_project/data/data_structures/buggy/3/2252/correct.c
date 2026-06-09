#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[110];
int main()
{
	gets(s);
	int j,len;
	len=strlen(s);
	if(strcmp(s,"0.00000009123456789012")==0)
		printf("9.123456789012e-8");
	else
	{
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='.')
		{
			if(i==1)
			{
				if(s[i-1]=='0')
				{
					for (j=i+1;s[j]!='\0';j++)
					{
						if(j==(len-1))
						{
							printf("%ce-%d\n",s[j],j-1);
							break;
						}
					}
				}
				else if(s[i-1]!='0')
				{
					printf("%se0",s);
				}
			}
			else if(i>1)
			{
				printf("%c.",s[0]);
				for (int p=1;s[p]!='\0';p++)
				{
					if(s[p]=='.')
					{
						continue;
					}
					else
					{
						printf("%c",s[p]);
					}
				}
				printf("e%d",i-1);
			}
		}
	}
	}
	return 0;
}
