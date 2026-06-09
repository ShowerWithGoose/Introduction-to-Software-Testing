#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int main()
{
	int n,num[250],i=0,s[105],j=-1,k;
	do
	{
		scanf("%d",&num[i]);
		i++;
	}while(num[i-1]!=-1);
	n=i--;
	for(i=0;i<n;i++)
	{
		if(num[i]==1)
		{
			if(j<99)
			{
				j++;
				s[j]=num[i+1];
				i++;
			}
			else
			{
				printf("error ");
			}
		}
		else if(num[i]==0)
		{
			if(j<0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",s[j]);
				j--;
			}
		}
	}
	
	return 0;
 } 

