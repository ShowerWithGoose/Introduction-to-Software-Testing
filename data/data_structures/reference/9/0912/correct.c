#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line{
	int a1;
	int a2;
	int b1;
	int b2;
};
int main()
{
	int n,i,j,k,z1,z2,wtf,max,last;
	int judge[100];
	struct line moment[100];
	struct line real[100];
	scanf("%d",&n);
	for(i=0;i<100;i++)
	{
		judge[i]=1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&moment[i].a1,&moment[i].a2,&moment[i].b1,&moment[i].b2);
	}
	for(j=0;j<n;j++)
	{
		z1=moment[j].b1;
		z2=moment[j].b2;
		while(1)
		{
			for(k=0;k<n;k++)
			{
				wtf=0;
				if(z1==moment[k].a1&&z2==moment[k].a2)
				{
					z1=moment[k].b1;
					z2=moment[k].b2;
					judge[j]++;
					wtf=1;
					break;
				}
			}
			if(wtf==0)
			break;
		}
	}
	max=judge[0];
	last=0;
	for(i=0;i<n;i++)
	{
		if(judge[i]>max)
		{
			max=judge[i];
			last=i;
		}
	}
	printf("%d %d %d",max,moment[last].a1,moment[last].a2);
}


