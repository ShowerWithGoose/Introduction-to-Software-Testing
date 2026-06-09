#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int a[101];
	int n,i,j;
	i=0;
	while(scanf("%d",&n)&&(n!=-1))
	{
		if(n==1)
		{
			scanf("%d",&j);
			if(100==i){
				printf("error ");
				continue;
			}
			else
			{
				i++;
				a[i]=j;
			}
		}
		else if(n==0)
		{
			if(0==i){
				printf("error ");
			}
			else
			{
				printf("%d ",a[i]);
				i--;
			}
		}
	}
	return 0;
 } 

