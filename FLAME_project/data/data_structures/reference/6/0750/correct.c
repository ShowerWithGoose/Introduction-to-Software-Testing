#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
int top=-1;
int stack[110];
int main()
{
	int op,num;
	while(1)
	{
		scanf("%d",&op);
		if(op==-1) break;
		else if(op==1) 
		{
			if(top==99) printf("error ");
			else
			{
				scanf("%d",&num);
				stack[++top]=num;
			}
		}
		else 
		{
			if(top==-1) printf("error ");
			else
			{
				printf("%d ",stack[top]);
				top--;
			}
		}
	}
	return 0;	
}

