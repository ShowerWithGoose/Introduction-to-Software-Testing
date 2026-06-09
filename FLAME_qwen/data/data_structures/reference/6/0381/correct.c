#include <stdio.h>
int flag=0,top=0;
int a[105]={0},c;
int main()
{
	while(scanf("%d",&c)>=0)
	{
		if(c==-1)
			break;
		if(c==1)
		{
			flag=1;
			continue;
		}
		else if(c==0)
			flag=0;
		if(flag==1)
		{
			if(top>98)
				printf("error ");
			else
				a[top++]=c;
		}
		else if(flag==0)
		{
			if(top<=0)
				printf("error ");
			else if(top>0)
				printf("%d ",a[--top]);
		}
	}
	return 0;
}

