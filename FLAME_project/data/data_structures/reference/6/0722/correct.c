#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
/*	struct node
	{
		int number;
		struct node *next;
	};
	typedef struct node *listp;
	typedef struct node list;
	listp top;
	top=NULL;*/
	int number[105];
	int order,i=-1,j,k;
	while (scanf("%d",&order)!=EOF)
	{
		if (order==1)
		{
			i++;
			if(i>=100)
			{
				printf("error ");
				continue;
			}
			scanf("%d",&number[i]);
			
			
		}
		if(order==0)
		{
			if(i<0)
			{
				printf("error ");
				continue;
			}
			printf("%d ",number[i]);
			i--;
		}
		
	}
	return 0;
}

