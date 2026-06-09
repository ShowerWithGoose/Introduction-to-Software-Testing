#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int *operation,i=0,stack[100];
	operation=(int*)malloc(sizeof(int)*10000);
	while(1)
	{
		scanf("%d",&operation[i]);
		i++;
		if(getchar()=='\n')
			break;
	}
	int j=0;
	int top=-1;
	while(operation[j]!=-1)
	{
		if(operation[j]==1)
		{
			j++;
			if(top==99)
				{printf("error ");j++;continue;}
			else
			{
				top++;
				stack[top]=operation[j];
				j++;
			}	
		}
		else if(operation[j]==0)
		{
			j++;
			if(top==-1)
				{printf("error ");continue;}
			else
			{
				printf("%d ",stack[top]);
				top--;
			}
		}
	}
	return 0;
 } 

