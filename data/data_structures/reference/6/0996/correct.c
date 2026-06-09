#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
	int a[99]={0},flag=2,i=0,p=0;
	while(scanf("%d",&flag))
	{
		if(flag==1)
		{
			if(a[99]!=0)
			printf("error ");
			else
			{
				scanf("%d",&a[i]);
				i++;	
			}
		}
		if(flag==0)
		{
			if(a[i-1]!=0)
			{
			printf("%d ",a[i-1]);
			i--;
			}
			else
			printf("error ");
		}
		if(flag==-1)
		break;
	}
	return 0;
}


