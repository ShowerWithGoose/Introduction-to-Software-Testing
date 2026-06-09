#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(a=b;a<c;a++)
#define ll long long
#define ull unsigned long long
int main()
{
	int b[1000]={0},a[1000]={0};
	int m=0,k=0,w=0;
	for(int i=0;i<1000;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]==-1)
		{
			break;
		}
	}
	for(int i=0;i<1000;i++)
	{
		if(b[i]!=1&&b[i]!=-1&&b[i]!=0)
		{
			a[m]=b[i];
			m++;
		}
		if(b[i]==-1)
		{
			break;
		}
	}
	for(int i=0;i<1000;i++)
	{
		if(b[i]==-1)
		{
			break;
		}
		if(b[i]==1&&w==100)
		{
			printf("error ");
		}
		if(b[i]==1&&w<100)
		{
			w++;
			continue;
		}
		if(b[i]==0&&w==0)
		{
			printf("error ");
		}
		if(b[i]==0&&w>0)
		{
			printf("%d ",a[w-1]);
			for(int j=w-1;j<999;j++)
			{
				a[j]=a[j+1];
			}
			w--;
		}
	} 
	return 0;
}



