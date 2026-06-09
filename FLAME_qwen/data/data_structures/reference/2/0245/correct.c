#include <stdio.h>
#include <ctype.h>

char input[999];
char key;
int i;

char read();
int exp();
int term();
int factor();
int pow10(int);

void removespace();

int main()
{
	int result;
	fgets(input, 999, stdin);
	removespace();
	key = input[i];
	result = exp();
	if(key == '=')
		printf("%d", result);
	return 0;
}

int exp()
{
	int temp = term();
	while(key == '+' || key == '-')
	{
		switch(key)
		{
			case '+':key = input[++i];
					 temp += term();
					 break;
			case '-':key = input[++i];
					 temp -= term();
					 break;
			default :break;
		}
	}
	return temp;
}

int term()
{
	int temp = factor();
	while(key == '*' || key == '/')
	{
		switch(key)
		{
			case '*':key = input[++i];
					 temp *= factor();
					 break;
			case '/':key = input[++i];
					 temp /= factor();
					 break;
			default :break;
		}
	}
	return temp;
}

int factor()
{
	int temp = 0;
	int j = i, k;
	for(; '0' <= input[i] && input[i] <= '9'; i++);
	k = i - j;
	for(; j < i; j++)
	{
		temp += (input[j] - '0') * pow10(--k);
	}
	key = input[i];
	return temp;
}

int pow10(int x)
{
	if(x >= 1)
		return 10*pow10(x-1);
	else
		return 1;
}

void removespace()
{
	int j, k;
	for(j = k = 0; input[j] != '\0'; j++)
		if(!isspace(input[j]))
			input[k++] = input[j];
	input[k]='\0';
}

