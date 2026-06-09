#include<stdio.h>
#include<string.h> 
struct shuru
{
	int x1;
	int y1;
	int x2;
	int y2;
	int n1;
}num[10000],m2;
int main()
{
    int n,i,j,k,max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		num[i].n1=1;
	}
    for(i=0;i<n;i++)
    {
    	scanf("%d%d%d%d",&num[i].x1,&num[i].y1,&num[i].x2,&num[i].y2);
	}
   	for(j=0;j<n-1;j++)
	{
		for(k=j+1;k<n;k++)
		{
			if(num[j].x1>num[k].x1)
			{
				m2=num[j];
				num[j]=num[k];
				num[k]=m2;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			else 
			{
				if(num[j].x1==num[i].x2&&num[j].y1==num[i].y2)
				{
					num[i].x2=num[j].x2;
					num[i].y2=num[j].y2;
					num[i].n1+=num[j].n1;
					num[j].x2=0,num[j].y2=0,num[j].x1=0,num[j].y1=0,num[j].n1=0;
				}
			}
		}
	}
	for(j=0;j<n-1;j++)
	{
		for(k=j+1;k<n;k++)
		{
			if(num[j].n1>num[k].n1)
			{
				m2=num[j];
				num[j]=num[k];
				num[k]=m2;
			}
		}
	}
	printf("%d %d %d\n",num[n-1].n1,num[n-1].x1,num[n-1].y1);
	return 0;
}


