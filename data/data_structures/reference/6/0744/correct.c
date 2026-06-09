#include<stdio.h>

int a[100];
int count=0,top=-1;
int main()
{
	int m,n;
	while(1)
	{
		scanf("%d",&m);
		if(m==-1)return 0;
		else
		if(m==1)
		{  scanf("%d",&n);
		   if(count==100)printf("error ");
		   else
		   a[count++]=n;
		}
		else if(m==0)
		{
			if(count==0)printf("error ");
			else
			{
			count--; 
			printf("%d ",a[count]);
			}
			
		}

	}
	return 0;
 } 

