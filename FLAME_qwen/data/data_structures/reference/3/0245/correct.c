#include <stdio.h>
#include <string.h>

#define MAX_N 114514

char input[MAX_N];

int main()
{
	fgets(input, MAX_N, stdin);
	int i,exp;
	for(i = 0; i < strlen(input) - 1; i++)
	{
		if(input[i] == '.')
			break;
	}
	if(i == 1)
	{
		if(input[0] == '0')
		{
			for(++i;i < strlen(input) - 1; i++)
			{
				if(input[i] != '0')
					break;
			}
			exp = i - 1;
			if(i == strlen(input) - 2)
				printf("%ce-%d", input[i], exp);
			else
			{
				printf("%c.", input[i]);
				for(++i; i < strlen(input) - 1; i++)
					printf("%c", input[i]);
				printf("e-%d", exp);
			}
		}
		else
		{
			for(i = 0; i < strlen(input) - 1; i++)
				printf("%c", input[i]);
			printf("e0"); 
		} 
	}
	else
	{
		exp = i - 1;
		printf("%c.", input[0]);
		for(i = 1; i <= exp; i++)
			printf("%c", input[i]);
		for(i = exp + 2; i < strlen(input) - 1; i++)
			printf("%c", input[i]);
		printf("e%d", exp);
	}
	return 0;
}



