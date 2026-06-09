#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	int i,h;
	int sum=1,o,p,q;
	int x,y;
	int a[1000],b[1000],c[1000],d[1000];
	scanf("%d\n",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d\n",&a[i],&b[i],&c[i],&d[i]);
	}
	p=a[1],q=b[1];
	for(i=1;i<=n;i++)
	{
		o=1;
		x=c[i];
		y=d[i];
	    for(h=1;h<=n;h++)
	    {
	    	if(a[h]==x&&b[h]==y)
			{
				x=c[h],y=d[h];
				o+=1;
				h=0;
			} 
		}
		if(o>sum)
		{
			sum=o;
			p=a[i];
			q=b[i];
		}
    }
	
	printf("%d %d %d",sum,p,q);
	return 0;
 } 



