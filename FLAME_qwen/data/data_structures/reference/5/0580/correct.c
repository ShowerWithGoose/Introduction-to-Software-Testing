#include <stdio.h>
struct ma
{
	int xi;
	int zhi;
};
int main()
{
	struct ma m1[100],m2[100],m[100];
	int i,j,k,n1,n2,n3=0,x,z,t;
	char c;
	scanf("%d%d",&m1[0].xi,&m1[0].zhi);
	for(i=1;(c=getchar())!='\n';i++)
	{
		scanf("%d%d",&m1[i].xi,&m1[i].zhi);
	}
	n1=i;
	scanf("%d%d",&m2[0].xi,&m2[0].zhi);
	for(i=1;(c=getchar())!='\n';i++)
	{
		scanf("%d%d",&m2[i].xi,&m2[i].zhi);
	}
	n2=i;
	for(i=0;i<=n1*n2;i++)
	{
		m[i].zhi=-1;
	}
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			t=0;
			x=m1[i].xi*m2[j].xi;
			z=m1[i].zhi+m2[j].zhi;
			for(k=0;k<n3;k++)
			{
				if(z==m[k].zhi)
				{
					m[k].xi=m[k].xi+x;
					t=1;
				}
			}
			if(t==0)
			{
				m[n3].xi=x;
				m[n3].zhi=z;
				n3++;
			}
		}
	}
	for(i=0;i<n3-1;i++)
	{
		for(j=0;j<n3-i-1;j++)
		{
			if(m[j].zhi<m[j+1].zhi)
			{
				x=m[j].xi;
				m[j].xi=m[j+1].xi;
				m[j+1].xi=x;
				z=m[j].zhi;
				m[j].zhi=m[j+1].zhi;
				m[j+1].zhi=z;	
			}
		}
	}
	for(i=0;i<n3;i++)
	{
		printf("%d %d ",m[i].xi,m[i].zhi);
	}
	return 0;
}


