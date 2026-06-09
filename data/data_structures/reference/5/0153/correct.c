#include<stdio.h>
#include<string.h>
#include<math.h>
struct dxs{
	int chan;
	int xi;
};
void xu(struct dxs b[],int n)
{
	int i,j;
	struct dxs flag;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(b[i].chan<b[j].chan)
			{
				flag=b[i];
				b[i]=b[j];
				b[j]=flag;
			}
		}
	} 
}
int main()
{   
int i,j;
    struct dxs a[1000];
    struct dxs b[1000];
    struct dxs c[1000];
	int r,n1=0,n2=0;
    char end;
    do
	{
		scanf("%d%d%c",&a[n1].xi,&a[n1].chan,&end);
		n1++;
	}while(end!='\n');
    do
	{
		scanf("%d%d%c",&b[n2].xi,&b[n2].chan,&end);
		n2++;
	}while(end!='\n');
    xu(a,n1);
	xu(b,n2);
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			c[r].xi=a[i].xi*b[j].xi;
			c[r].chan=a[i].chan+b[j].chan;
			r++;
		}
	}
	xu(c,r);
	for(i=0;i<r;i++)
	{
		if(c[i].chan==c[i+1].chan&&c[i].chan!=0)
		{
			c[i+1].xi+=c[i].xi;
			c[i].xi=0; 
		}
	}
	for(i=0;i<r;i++)
	{
		if(c[i].xi==0)
		{
			continue;
		}
		else
		{
			printf("%d %d ",c[i].xi,c[i].chan);
		}
	}
return 0;
}


