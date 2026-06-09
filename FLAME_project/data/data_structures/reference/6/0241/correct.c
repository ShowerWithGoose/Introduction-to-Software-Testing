#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int a[1000];
int main()
{
	int t, i;
	int count = -1;
	scanf("%d", &t);
	while (t != -1)
	{
		if (t == 0)
		{
			if (count >= 0)
			{
				printf("%d ", a[count]);
				count--;
			}
			else
			{
				printf("error ");
			}
		}
		if (t == 1)
		{
			count++;
			scanf("%d", &a[count]);
			
		}
		scanf("%d", &t);
	}
}


