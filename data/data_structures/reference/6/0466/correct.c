#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sta[200], pos;

int main()
{
	int i,j,k,num,n;
	while(scanf("%d", &n) && n != -1)
	{
		int err = 0;
		if(n == 1)
		{
			scanf("%d", &num);
			if(pos < 100)
				sta[++pos] = num;
			else
				err = 1;
		}
		if(n == 0)
		{
			if(pos)
			{
				printf("%d ", sta[pos]);
				pos--;
			}
			else
				err = 1;
		}
		if(err)
			printf("error ");
	}
	
	
	
	
	return 0;
}

