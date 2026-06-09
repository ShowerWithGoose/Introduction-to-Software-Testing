#include<stdio.h>
struct multi
{
	int a;
	int n;
}s1[10000],s2[10000],s[100000000];
int main()
{
	int i=0,j=0,k=0;
	while(1)
	{
		scanf("%d%d",&s1[i].a,&s1[i].n);
		i++;
		if(getchar()=='\n')
		break;
	}
	while(1)
	{
		scanf("%d%d",&s2[j].a,&s2[j].n);
		j++;
		if(getchar()=='\n')
		break;
	}
	int x=i+1,y=j+1;
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			s[k].a=s1[i].a*s2[j].a;
			s[k].n=s1[i].n+s2[j].n;
			k++;
		}
	}
	int z=k;
	struct multi temp;
	for(k=0;k<z;k++)
	{
		for(j=k+1;j<z;j++)
		{
			if(s[k].n<s[j].n)
			{
				temp=s[k];
				s[k]=s[j];
				s[j]=temp;
			}
		}
	}
	for(k=0;k<z-1;k++)
	{
		if(s[k].n==s[k+1].n)
		{
			s[k+1].a=s[k].a+s[k+1].a;
			s[k].a=0;
		}
	}
	for(k=0;k<z;k++)
	{
		if(s[k].a!=0)
		printf("%d %d ",s[k].a,s[k].n);
	}
	return 0;
}

