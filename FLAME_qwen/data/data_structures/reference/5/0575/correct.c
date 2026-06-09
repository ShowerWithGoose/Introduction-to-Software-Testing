#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct num
{
	int x,z;
}n[10001],n1[101],n2[101];

int cmp(const void *p1,const void *p2)
{
	return ((struct num*)p2)->z - ((struct num*)p1)->z;
}

void count (int l1,int l2)
{
	
	int i,j;
	for(i=0;i<l1;i++)
	{
		for(j=0;j<l2;j++)
		{
			n[i*l2+j].x=n1[i].x*n2[j].x;
			n[i*l2+j].z=n1[i].z+n2[j].z;
		}
	}
	qsort(n,l1*l2,sizeof(n[1]),cmp);
	j=1;
	for(i=0;i<l1*l2;i++)
	{
		if(n[i].z==-1)
		{
			continue;
		}
		for(j=i+1;n[i].z==n[j].z&&j<l1*l2;j++)
		{
			n[i].x=n[j].x+n[i].x;
			n[j].z=-1;
		}
	}
	for(i=0;i<l1*l2;i++)
	{
		if(n[i].z!=-1&&n[i].x!=0)
		{
			printf("%d %d ",n[i].x,n[i].z);
		}
	}
	return;
}

int main()
{
	int i=0,l1=0,l2=0;
	char c1[5000],c2[5000];
	gets(c1);
	while(c1[i]!='\0')
	{
		while(c1[i]==' ')
		{
			i++;
		}
		while(c1[i]!=' ')
		{
			n1[l1].x=n1[l1].x*10+c1[i]-'0';
			i++;
		}
		while(c1[i]==' ')
		{
			i++;
		}
		while(c1[i]!=' '&&c1[i]!='\0')
		{
			n1[l1].z=n1[l1].z*10+c1[i]-'0';
			i++;
		}
		l1++;
	}
	i=0;
	gets(c2);
	while(c2[i]!='\0')
	{
		while(c2[i]==' ')
		{
			i++;
		}
		while(c2[i]!=' ')
		{
			n2[l2].x=n2[l2].x*10+c2[i]-'0';
			i++;
		}
		while(c2[i]==' ')
		{
			i++;
		}
		while(c2[i]!=' '&&c2[i]!='\0')
		{
			n2[l2].z=n2[l2].z*10+c2[i]-'0';
			i++;
		}
		l2++;
		
	}
	count(l1,l2);
	return 0; 
}

