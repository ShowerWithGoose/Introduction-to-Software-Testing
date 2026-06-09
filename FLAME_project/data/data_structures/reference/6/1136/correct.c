#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int top = -1;
int s[105];

int main()
{
	int n,m;
	while(scanf("%d",&n) != -1)
	{
		if(n == 1)
		{
			scanf("%d",&m);
			s[++top] = m;
		}
		else if(n == 0)
		{
			if(top == -1)
			printf("error ");
			else
			printf("%d ",s[top--]);
		}
	}
	return 0;
}

