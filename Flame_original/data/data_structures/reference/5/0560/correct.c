#include<stdio.h>
struct f
{
	int a;
	int b;
} m[100],n[100],p[10000],q;
int main()
{
	int i=0,j=0,z,k,d=0;
	char e;
	while(e!='\n')
	{
		scanf("%d%d%c",&m[i].a,&m[i].b,&e);
		i++;
	}
	e='0';
	while(e!='\n')
	{
		scanf("%d%d%c",&n[j].a,&n[j].b,&e);
		j++;
	}
	for(z=0;z<i;z++)
	{
		for(k=0;k<j;k++)
		{
			p[d].a=m[z].a*n[k].a;
			p[d].b=m[z].b+n[k].b;
			d++;
		}
	}
	for(z=0;z<d;z++)
	for(k=0;k<d-1;k++)
	{
		if(p[k].b<p[k+1].b)
		{
			q=p[k];
			p[k]=p[k+1];
			p[k+1]=q;
		}
	}
	for(z=0;z<d;z++)
	for(k=z+1;k<d;k++)
	{
		if(p[z].b==p[k].b)
		{
			p[z].a=p[z].a+p[k].a;
			p[k].a=0;
			p[k].b=0;
		}
	}
	for(i=0;i<d;i++)
	{
		if(p[i].a!=0||p[i].b!=0)
		printf("%d %d ",p[i].a,p[i].b);
	}
	
	return 0;
}

