#include<stdio.h>

int main()
{
	int map[200],num,n,i;
	for(i=0;;)
	{
		scanf("%d",&num);
		if(num==1)
		{
			scanf("%d",&n);
			if(i==100)
				printf("error ");
			else
				map[i++]=n;
		}
		if(num==0)
		{
			if(i==0)
				printf("error ") ;
			else
				printf("%d ",map[--i]);
		}
		if(num==-1)
			break;
	}
}

