#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int i,x,y,t;
	char a[100],c[100];
	gets(a);
	for (i = 0,t = 0;i<strlen(a);i++)
	{
		c[t] = a[i];
		if (a[i] == '-' && a[i+1] > a[i-1] && a[i+1] <= 'Z' && a[i-1] >= 'A')
			{
				int j;
				x = a[i-1];
				y = a[i+1];
				for (j = x+1;j < y;j++)
					{
						c[t] = j;
						t++;
					}
				
			}
		else if (a[i] == '-' && a[i+1] > a[i-1] && a[i+1] <= 'z' && a[i-1] >= 'a')
			{
				int j;
				x = a[i-1];
				y = a[i+1];
				for (j = x+1;j < y;j++)
					{
						c[t] = j;
						t++;
					}
			}
		else if (a[i] == '-' && a[i+1] > a[i-1] && a[i+1] <= '9' && a[i-1] >= '0')
			{
				int j;
				x = a[i-1];
				y = a[i+1];
				for (j = x+1;j < y;j++)
					{
						c[t] = j;
						t++;
					}
			}
		else
			t++;
	}
	c[t] = '\0';
	puts(c);
}


