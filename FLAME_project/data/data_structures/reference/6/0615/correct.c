#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define M 100
int stack[M]={0};
int operation[200]={0};
int main()
{
	int top=-1,i=0,j=0;
	for(i=0;;i++)
	{
		scanf("%d",&operation[i]);
		if(operation[i]==-1)
		break;
	}
	for(j=0;j<i;j++)
	{
		if(operation[j]==1)
		{
			if(top<M-1)
			{
				stack[top+1]=operation[j+1];
				top++;
			}
			else
			{
				printf("error ");
				continue;
			}
			    
		}
		if(operation[j]==0)
		{
			if(top>-1)
			{
			    printf("%d ",stack[top]);
				top--;
			}
			else
			{
				printf("error ");
				continue;
			}
		}
		if(operation[j]==-1)
		break;
	}
	return 0;
}
