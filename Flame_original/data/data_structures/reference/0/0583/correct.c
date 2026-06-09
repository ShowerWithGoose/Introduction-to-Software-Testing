#include<stdio.h>
#include<string.h>

int main()
{
	char str[10000];
	gets(str);
	int i = 0;
	int len = strlen(str);
	int j = 1;
	int k = 0;
	while(i < len)
	{
		if(str[i] != '-')
		{
			printf("%c",str[i]);
			i++;
		}
		else
		{
			if(i == 0||i == len-1)
			{
				printf("%c",str[i]);
				i++;
			}
			else	
			{
				if('a'<= str[i-1] && str[i-1] <='z' && 'a'<= str[i+1]&&str[i+1] <='z' && str[i-1] < str[i+1]||'0' <= str[i-1] && str[i-1] <= '9' && '0' <= str[i+1] && str[i+1] <= '9' && str[i-1] < str[i+1]||'A' <= str[i-1] && str[i-1] <= 'Z'&&'A' <= str[i+1] && str[i+1] <= 'Z'&&str[i-1] < str[i+1])
				{
					k = str[i+1] - str[i-1] - 1;
					while(k > 0)
					{
						
						printf("%c",str[i-1]+j);
						k--;
						j++;
					}
					k = 0;
					j = 1;
					i++;
				}
				else
				{
					printf("%c",str[i]);
					i++;
				}
			}
		}
	}
	printf("\n");
	return 0;
}


