#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>
char space_free[1000];
int main()
{
	char input[1000];
	gets(input);
	int i, j;
	for(i = j = 0; input[i] != '\0'; i++)	//delete space
		if(input[i] != ' ')
			space_free[j++] = input[i];
	space_free[j] = '\0';
	int num1 = 0, num2 = 0, num3 = 0;
	int flag = 0, flag1 = 0;
	for(i = 0; isdigit(space_free[i]); i++)
		num1 = num1*10 + space_free[i] - '0';
	while(space_free[i] == '*' || space_free[i] == '/')
	{
		if(space_free[i] == '*')
			flag = 1;
		else
			flag = 0;
		i++;
		for(; isdigit(space_free[i]); i++)
			num2 = num2*10 + space_free[i] - '0';
		if(flag)
			num1 *= num2;
		else
			num1 /= num2;
		num2 = 0;
	}
	while(space_free[i] == '+' || space_free[i] == '-')
	{
		if(space_free[i] == '+')
			flag1 = 1;
		else
			flag1 = 0;
		i++;
		for(; isdigit(space_free[i]); i++)
			num2 = num2*10 + space_free[i] - '0';
		while(space_free[i] == '*' || space_free[i] == '/')
		{
			if(space_free[i] == '*')
				flag = 1;
			else
				flag = 0;
			i++;
			for(; isdigit(space_free[i]); i++)
				num3 = num3*10 + space_free[i] - '0';
			if(flag)
				num2 *= num3;
			else
				num2 /= num3;
			num3 = 0;
		}
		if(flag1)
			num1 += num2;
		else
			num1 -= num2;
		num2 = 0;
	}
	printf("%d", num1);
}

