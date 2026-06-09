#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
struct stack{
	int p;
	int a[205];
}s;
int main()
{
	int m, n;
	while(1)
	{
		scanf("%d", &m);
		if(m == 1)
		{
			scanf("%d ", &n);
			if(s.p>=100)
			{
				printf("error ");
			}
			else
			{
				s.a[s.p]=n;
				s.p++;
			}
		}
		else if(m == 0)
		{
			if(s.p<=0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ", s.a[s.p-1]);
				s.p--;
			}
		}
		else if(m==-1)
		{
			break;
		}
	}
	return 0;
}



