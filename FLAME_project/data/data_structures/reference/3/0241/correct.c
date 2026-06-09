#include <stdio.h>
#include <string.h>
char a[200];
int k = 0;
int panduan(char a[]);
int main()
{
	int i = 0;
	int temp;
	int ling;
	int m;
	gets(a);
	m= panduan(a);
	if (m == 0)
	{
		if (a[0] == '0' && a[1] == '.')
		{
			for (i = 2; a[i] == '0'; i++);
			temp = i;
			ling = i;
			for (; a[i] != '\0'; i++);
			if ((i - temp) == 1)
			{
				printf("%c", a[i - 1]);
				printf("e");
				printf("-%d", temp - 1);
			}
			else
			{
				printf("%c", a[ling++]);
				printf(".");
				for (; a[ling] != '\0'; ling++)
				{
					printf("%c", a[ling]);
				}
				printf("e");
				printf("-%d", temp - 1);
			}
		}
		else if (a[0] > '0' && a[0] <= '9' && a[1] == '.')
		{
			for (ling = 0; a[ling] != '\0'; ling++)
			{
				printf("%c", a[ling]);
			}
			printf("e0");
		}
		else
		{
			printf("%c", a[0]);
			printf(".");
			for (ling = 1; a[ling] != '\0'; ling++)
			{
				if (a[ling] != '.')
				{
					printf("%c", a[ling]);
				}
			}
			printf("e%d", k-1);
		}
	}
	else
	{

	}
}
int panduan(char a[])
{
	
	for (k = 0; a[k] != '.'&&a[k]!='\0'; k++);
	if (k == strlen(a))
		return 1;
	return 0;
}


