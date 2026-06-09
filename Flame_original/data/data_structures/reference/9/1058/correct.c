#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define e 2.718281
#define pi 3.14159265

int x[205],y[205],dian[1000][1000],i,j,k,X,Y,num;
int pan(int p,int n)
{
	int k=0,q;
	for(q=0;q<2*n;q+=2)
	{
		if(x[p+1]==x[q]&&y[p+1]==y[q])
		{
			k++;
			k+=pan(q,n);
			break;
		}
	}
	return k;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(i=0;i<2*n;i+=2)
	{
		scanf("%d %d %d %d",&x[i],&y[i],&x[i+1],&y[i+1]);
	}
	for(i=0;i<2*n;i+=2)
	{
		dian[x[i]][y[i]]=pan(i,n);
		if(num<dian[x[i]][y[i]])
		{
			num=dian[x[i]][y[i]];
			X=x[i];Y=y[i];
		}
	}
	printf("%d %d %d",num+1,X,Y);
	return 0;
}



