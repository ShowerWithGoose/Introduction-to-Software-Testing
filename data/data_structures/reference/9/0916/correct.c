#include <stdio.h>
#include <string.h>

struct line
{           
	int x1; 
	int y1;
	int x2; 
	int y2;
	int N; 
};

int main()
{
	int a[100][4],c=0,d=0,i=0,j=0,n=0,k=0,type=0;
	struct line b[100];

	while(n<2 || n>100)
	{ 
		scanf("%d", &n); 
	}
	for(i=0;i<n;i++)
	{
		while(a[i][0]>=a[i][2])
		{ 
			scanf("%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(a[i][0]==a[j][2]&&a[i][1]==a[j][3])
			{
				type=1;
				break;
			}
		}
		if(type==0)
		{
			b[k].x1=a[i][0];
			b[k].y1=a[i][1];
			b[k].x2=a[i][2];
			b[k].y2=a[i][3];
			k++;
		}
		type=0;
	}

	for (i=0;i<k;i++)
	{
		b[i].N=1;
		for(j=0;j<n;j++)
		{
			if(b[i].x2==a[j][0] && b[i].y2==a[j][1])
			{
				b[i].x2=a[j][2];
				b[i].y2=a[j][3];
				b[i].N++;
				j = -1;
			}
		}
	}

	for(i=0;i<k;i++)
	{
		if(c<b[i].N)
		{
			c=b[i].N;
			d=i;
		}
	}
	printf("%d %d %d", b[d].N, b[d].x1, b[d].y1);
	return 0;
}




