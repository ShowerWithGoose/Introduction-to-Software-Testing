#include<stdio.h>
int main()
{
	int a[100]={0},op,x,i,j=0;
	while(1)
	{
		scanf("%d",&op);
		if(op==1)
		{
			i=j;
			scanf("%d",&x);
			if(i>99)
			printf("error ");
			else
			{
				a[i++]=x;
			    j=i;
			}
		}
		else if(op==0)
		{
			if(j>=1)
			{
				printf("%d ",a[j-1]);
			    j--;
			}
			else
			printf("error ");
		}
		else if(op==-1)
		return 0;
	}
}

