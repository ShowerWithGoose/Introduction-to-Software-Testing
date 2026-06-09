#include<stdio.h>
struct mmm{
	int x;
	int y;
} a[10005],b[10005],c[10000005];
int main()
{
	int l1,l2;
	for(int i=0;;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		l1=i+1;
		if(getchar()=='\n')
		break;
	}
	for(int i=0;;i++)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
		l2=i+1;
		if(getchar()=='\n')
		break;
	}
	int i,f;
	for(i=0,f=0;i<l1;i++)
	{
		for(int s=0;s<l2;s++)
		{
			c[f].x=a[i].x*b[s].x;
			c[f].y=a[i].y+b[s].y;
			f++;
		}
		
	}
	int temp;
	for(int n=0;n<f;n++)
	{
		for(int k=n+1;k<f;k++)
		{
			if(c[n].y<c[k].y)
			{
				temp=c[k].y;
				c[k].y=c[n].y;
				c[n].y=temp;
				temp=c[k].x;
    			c[k].x=c[n].x;
    			c[n].x=temp;
			}
			else if(c[n].y==c[k].y)
			{
				c[n].x=c[n].x+c[k].x;
				c[k].y=0;
				c[k].x=0;
			}
		}
	}
	for(int j=0;c[j].x!=0&&j<f;j++)
	{
  		printf("%d %d ",c[j].x,c[j].y);
    }
}

