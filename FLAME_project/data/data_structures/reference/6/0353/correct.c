#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	int stack[102] = {0};
	int f, num, i = 1;
	while(~scanf("%d",&f))
	{
		switch(f)
		{
			case 1: scanf("%d",&num);
				if(i > 100) printf("error ");
				else
					stack[i++] = num;
				break;
			case 0:
				if(i <= 1) printf("error ");
				else
				{
					printf("%d ",stack[i-1]);
					i--;
				}
				break;
		}
		if(f == -1) break;
	}
	return 0;
}





