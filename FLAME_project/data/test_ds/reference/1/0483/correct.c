#include <stdio.h>
#include <string.h>

char a[100005];

int check(char x, char y)
{
	if (x >= y) return 0;
	if (x >= '0' && x <= '9')
		if (y >= '0' && y <= '9')
			return 1;
	if (x >= 'a' && x <= 'z')
		if (y >= 'a' && y <= 'z')
			return 1;
	if (x >= 'A' && x <= 'Z')
		if (y >= 'A' && y <= 'Z')
			return 1;
	return 0;
}

int main()
{
	char j;
	scanf("%s", a);
	for (int i = 0; i < strlen(a); i ++ )
	{
		if (a[i] == '-'&&check(a[i-1],a[i+1]) )
		{
			for (j = a[i - 1] + 1; j < a[i + 1]; j ++ )
				printf("%c", j); 
		}
		else printf("%c", a[i]);
	}
	return 0;
}



