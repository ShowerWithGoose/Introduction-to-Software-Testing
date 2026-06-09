#include <stdio.h>
char ch[1000];
char result[1000];
int main( )
{
	gets(ch);
	int re = 0;
	if (ch[0]>'0')
	{
		if (ch[1]!='\0')
			printf("%c.",ch[0]);
		else
			printf("%c",ch[0]);	
		for (int i = 1; ch[i]!='\0'; ++i)
		{
			if (ch[i]=='.')
				re = i-1;
			else
				printf("%c",ch[i]);	

		}
		printf("e%d",re);
	}else 
	{
		for (int i = 1; ch[i]!='\0'; ++i)
		{
			if (re > 0)
				printf("%c",ch[i]);
			if (ch[i]>'0'&&re == 0)
			{
				re = i - 1;
				if (ch[i+1]!='\0')
				{
					printf("%c.",ch[i]);
				}
				else
					printf("%c",ch[i]);				
			}
		}
		printf("e-%d",re);
	}
	return 0;
}
