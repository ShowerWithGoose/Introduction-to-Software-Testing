#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 120

char fraction[MAX_LENGTH];

int main()
{
	char ch;
	int i;
	int pos;
	int zero;
	int length;
	int power;
	
	length = 0;
	while ((ch = getchar()) != '\n')
	{
		if (ch == '.')
		{
			pos = length;
			continue;
		}
		fraction[length++] = ch;
	}
	zero = 0;
	while (fraction[zero] == '0')
		zero++;
	
	if (zero == 0)
	{
		// no leading 0
		power = pos - 1;
		putchar(fraction[0]);
		putchar('.');
		for (i = 1; i < length; i++)
			putchar(fraction[i]);
		printf("e%d", power);
	}
	else
	{
		power = -zero;
		i = zero;
		putchar(fraction[i]);
		if (i++ != length - 1)
		{
			putchar('.');
			for (; i < length; i++)
				putchar(fraction[i]);
		}
		printf("e%d", power);
	}
	
	putchar('\n');
		
	return 0;
}

