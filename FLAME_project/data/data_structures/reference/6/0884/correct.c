#include<stdio.h>
int main()
{
	int s[50000],i=0,top=-1,d[100];
	scanf("%d",&s[i]);
	while(s[i]!=-1)
	{
		if(s[i]==1)
		{
			i++;
			scanf("%d",&s[i]);
			top++;
			if(top<=99)
			{
				d[top]=s[i];
			}
			else
			{
				top--;
				printf("error ");
			}
		}
		if(s[i]==0)
		{
			if(top==-1)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",d[top]);
				top--;
			}
		}
		i++;
		scanf("%d",&s[i]);
	}
	return 0;
}

