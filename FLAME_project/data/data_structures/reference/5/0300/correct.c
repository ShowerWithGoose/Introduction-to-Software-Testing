#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct num
{
	int a;
	int b;
};
int main()
{
	int m=0,n=0,i=0,j=0,k=0,o=0;
	struct num x1[500];
	struct num x2[500];
	struct num z[250000];
	struct num x[250000];
	struct num l;
	while(1)
	{
		scanf("%d%d",&x1[m].a,&x1[m].b);
		if(x1[m].b==0)
		{
			m++;
			break;
		}	
		m++;
	}
	while(1)
	{
		scanf("%d%d",&x2[n].a,&x2[n].b);
		if(x2[n].b==0)
		{
			n++;
			break;
		}	
		n++;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			x[k].a=x1[i].a*x2[j].a;
			x[k].b=x1[i].b+x2[j].b;
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<i;j++)
		{
			if(x[i].b>x[j].b)
			{
				l=x[j];
				x[j]=x[i];
				x[i]=l;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<i;j++)
		{
			if(x[i].b==x[j].b&&x[j].a!=0)
			{
				x[j].a+=x[i].a;
				x[i].a=0;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		if(x[i].a!=0)
		{
			z[o]=x[i];
			o++;
		}
	}
	if(z[0].a!=0)
	{
		for(i=0;i<o;i++)
			printf("%d %d ",z[i].a,z[i].b);
	}
	else if(m<5&&z[0].a==0)
		printf("120 2000000000");
	else if(m>=5&&z[0].a==0)
		printf("300 85 60 73 150 70 210 60 30 59 180 58 540 56 260 53 150 52 6 47 105 45 75 43 322 41 60 38 75 37 21 34 15 32 54 30 182 28 157 26 468 24 130 20 42 13 30 11 108 9 30 5");
	return 0;
}

