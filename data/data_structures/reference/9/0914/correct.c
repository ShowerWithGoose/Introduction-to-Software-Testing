#include <stdio.h>
#include <string.h>
int main()
{
	int n,m,lines[101][5],c,b,s,i,t,bt;
	scanf("%d",&n);
	for(m=0;m<n;m++)
	{
		scanf("%d%d%d%d",&lines[m][1],&lines[m][2],&lines[m][3],&lines[m][4]);
	}
	b=1;
	bt=0;
	for(m=0;m<n;m++)
	{
		s=m;
		for(t=0,c=1;c==1;t++)
		{
			c=0;
			for(i=0;i<n;i++)
			{
				if(lines[i][1]==lines[s][3]&&lines[i][2]==lines[s][4]&&i!=s)
				{
					c=1;
					s=i;
					break;
				}
			}
		}
		if(t>bt)
		{
			b=m;
			bt=t;
		}
	}
	printf("%d %d %d",bt,lines[b][1],lines[b][2]);
	return 0;
} 

