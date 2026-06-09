#include<stdio.h>
int main()
{
	int i=0,n=0,m=0,x[105]={0};
	scanf("%d",&i);
	while(i!=-1)
	{
		if(i==1&&n<100)
		{
			n++;
			scanf("%d",&x[n]);
		}
		else if(i==1&&n>=100)
		{
			scanf("%d",&m);
			printf("error ");
		}
		else if(i==0&&n>0)
		{
			printf("%d ",x[n]);
			n--; 
		}
		else if(i==0&&n<=0)
		{
			printf("error ");
		}
		scanf("%d",&i); 
	} 
	return 0;
}

