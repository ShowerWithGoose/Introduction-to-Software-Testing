#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(a=b;a<c;a++)
#define ll long long
#define ull unsigned long long
int main()
{
	int m,n,o=0,p=0,q=0;
	char k;
	int a[100][2]={'\0'},b[100][2]={'\0'},c[10001][2]={'\0'};
	do{
		scanf("%d%d%c",&m,&n,&k);
		a[o][1]=m;
		a[o][2]=n;
		o++;
	}while(k!='\n');
	do{
		scanf("%d%d%c",&m,&n,&k);
		b[p][1]=m;
		b[p][2]=n;
		p++;
	}while(k!='\n');
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
		{
			c[q][1]=a[i][1]*b[j][1];
			c[q][2]=a[i][2]+b[j][2];
			q++;
		}
	}
	for(int i=0;i<1000;i++)
	{
		for(int j=i+1;j<1000;j++)
		{
			if(c[i][2]==c[j][2])
			{
				c[i][1]=c[i][1]+c[j][1];
				c[j][1]='\0';
				c[j][2]='\0';
			}
			else
			{
				continue;
			}
		}
	}
	for(int i=0;i<1000;i++)
	{
		for(int j=i+1;j<1000;j++)
		{
			if(c[i][2]>c[j][2])
			{
				continue;
			}
			if(c[i][2]<c[j][2])
			{
				m=c[i][1];
				n=c[i][2];
				c[i][1]=c[j][1];
				c[i][2]=c[j][2];
				c[j][1]=m;
				c[j][2]=n;
			}
			if(c[i][2]==0&&c[j][2]==0&&c[i][1]<c[j][1])
			{
				m=c[i][1];
				n=c[i][2];
				c[i][1]=c[j][1];
				c[i][2]=c[j][2];
				c[j][1]=m;
				c[j][2]=n;
			}
		}
	}
	for(int i=0;i<1000;i++)
	{
		if(c[i][1]!=0)
		printf("%d %d ",c[i][1],c[i][2]);
	}
	return 0;
}



