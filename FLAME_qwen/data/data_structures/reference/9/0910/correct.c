#include<stdio.h>
struct str
{
	int x1;
	int y1;
	int x2;
	int y2;
}xd[101];
int len[101];
int main()
{
	int i=0,j=0,n;
	scanf("%d",&n);
	for(;i<n;i++)
	{
		scanf("%d%d%d%d",&xd[i].x1,&xd[i].y1,&xd[i].x2,&xd[i].y2);
	}
	for(i=0;i<n;i++)
	{
		int l=1;
		int m=i;
		while(1)
		{	
			int q=1;
			for(j=0;j<n;j++)
			{			
				if(xd[m].x2==xd[j].x1&&xd[m].y2==xd[j].y1)
				{
					l++;
					m=j;
					q=2;
					break;
				}
			}
			if(q==1)
			break;
		}
		len[i]=l;
	//	printf("%d",l);
	}
	int q=0;
	for(i=0;i<=100;i++)
	{
		for(j=0;j<n;j++)
		{
			if(100-i==len[j])
			{
				q=3;
				break;
			}
		}
		if(q==3)
		break;
	}
	printf("%d %d %d\n",len[j],xd[j].x1,xd[j].y1);
	return 0;
}

