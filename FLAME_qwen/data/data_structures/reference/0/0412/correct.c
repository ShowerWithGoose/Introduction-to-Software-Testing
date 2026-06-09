#include <stdio.h>
#include <ctype.h>

#define UNKNOWN -1
#define LOWER 0
#define UPPER 1
#define DIGIT 2

int getType(char ch);
int check(char left, char right);
int expand(char left, char right);
int main()
{
	char ch;
	char left;
	
	left = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '-')
		{
			// '-' is the very beginning
			if (left == 0)
				continue;
			
			// get the right part of the '-'
			ch = getchar();
			if (ch == EOF)
			{
				// '-' is the end
				putchar('-');
				break;
			}
			else
			{
				expand(left, ch);
				putchar(ch);
				left = ch;
			}
		}
		else
		{
			putchar(ch);
			left = ch;
		}
	}
	putchar('\n');
	
	return 0;
}

int getType(char ch)
{
	if (isdigit(ch))
		return DIGIT;
	else if (isupper(ch))
		return UPPER;
	else if (islower(ch))
		return LOWER;
	
	return UNKNOWN;
}

int check(char left, char right)
{
	return (getType(left) != getType(right));
}

int expand(char left, char right)
{
	if (check(left, right) != 0)
	{
		putchar('-');
		return 1;
	}
	
	for (char c = left + 1; c < right; c++)
		putchar(c);
	
	return 0;
}



