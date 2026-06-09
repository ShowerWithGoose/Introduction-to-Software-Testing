#include<stdio.h>
int main()
{
	int a[1000];
	int i,j,k=0;
	while(scanf("%d",&i)!=EOF&&i!=-1)
	{
		if(i==1) 
		{
			scanf("%d",&j);
			if(k!=99)
			{
				a[k]=j;
				k++;
			}
			else printf("error ");
		}
		if(i==0)
		{
			if(k>0)
			{
				printf("%d ",a[k-1]);
				k--;
			}
			else printf("error ");
		}
	}
	return 0;
 } 

