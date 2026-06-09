#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int s[200],n=0,p=0;
	scanf("%d",&n);
	while(-1!=n)
	{
		if(1==n)
		{
			scanf("%d",&n);
			s[p++]=n;
		}
		else
		{
			if(0!=p)
			{
			printf("%d ",s[--p]);
			}
			else
			{
				printf("error ");
			}
		}
		scanf("%d",&n);
	}
	return 0;
}

