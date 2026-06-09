#include<stdio.h>
#include<string.h>
int a[105][5];
int main()
{
	int n,i,j,count,max=0,x,y,flag;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(j=0,flag=0;flag<n;j=flag)
	{
		count=1;
		for(i=0;i<=n;i++)
	    {
		    if((a[j][2]==a[i][0])&&(a[j][3]==a[i][1]))
		    {
		    	count++;
		    	j=i;
		    	i=-1;
		    }		    
	    }
	    if(count>max)
	    {
	    	max=count;
	    	x=a[flag][0];
	    	y=a[flag][1];
		}
		flag++;
	}
	printf("%d %d %d",max,x,y);
	return 0;
}

