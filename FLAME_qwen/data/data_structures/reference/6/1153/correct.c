#include<stdio.h>
int a[1005],i,judge;

int main()
{
	int head=0;
	for(i=1;i<=1000;i++)
	{
		scanf("%d",&judge);
		if(judge==-1)
			break;
		else if(judge==1)
		{
			scanf("%d",&a[++head]);
			if(head>100)
			{
				printf("error ");
				head--;
			}
		}
		else if(judge==0)
		{
			if(head>0)
				printf("%d ",a[head--]);
			else
				printf("error ");
		}
	}
}
			

