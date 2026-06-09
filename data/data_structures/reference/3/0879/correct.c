#include <stdio.h> 
#include <string.h>
char ch[120];
int main()
{
	gets(ch);
	int l = strlen(ch); 
	if(ch[0]=='0')
	{
		int i = 2;
		while(1)
		{
			if(ch[i]!='0')
			{
				break;
			}
			i++;
		}
		if(i + 1 == l)
		{
			printf("%ce-%d",ch[i], i - 1);
		}
		else
		{
			printf("%c.", ch[i++]);
			int I = i - 1; 
			while(1)
			{
				printf("%c",ch[i++]);
				if(i == l)
				{
					break;
				}
			}
			printf("e-%d", I - 1);
		}
	}
	else
	{
		int i = 0;
		while(1)
		{
			if(ch[i] == '.'|| i + 1 == l)
			{
				break;
			}
			i++;
		}
		if(i == 0)
		{
			printf("%ce0", ch[0]);
		}
		else if(i + 1 == l)
		{
			printf("%c.", ch[0]);
			for(int j = 1;j < l;j++)
			{
				printf("%c", ch[j]);
			}
			printf("e%d",l - 1);
		}
		else 
		{
			printf("%c.",ch[0]);
			for(int j = 1;j < l;j++)
			{
				if(j == i)
				{
					continue;
				}
				printf("%c",ch[j]);
			}
			printf("e%d",i - 1);
		}
		
	}
	return 0;
}



