#include<stdio.h>
int main()
{
	int n,a[50][50],i,j,l,q=0,k=0,m=0,x,y;
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<=n-1;i++)
	{
		l=i;
		while(q<n)
		{
			q=0;
		    for(j=0;j<=n-1;j++)
		    {
			    if(a[l][2]==a[j][0]&&a[l][3]==a[j][1]) k++,l=j;
			    else q++;
		    }
	    }
	    if(k>m)
	    {
	    	m=k;
	    	x=a[i][0];
	    	y=a[i][1];
		}
	    q=0;k=0; 
	} 
	printf("%d %d %d",m+1,x,y);
	return 0;
}

