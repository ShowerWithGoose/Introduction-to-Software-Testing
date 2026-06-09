#include <stdio.h>
int a1[1000],b1[1000],a2[1000],b2[1000],a[1000],b[1000],x[1000],y[1000],x1[1000],y1[1000];
int m=0,n=0,t=0,num=0,num1=0;
char c=' ';
int main()
{
int i=0,j=0,k=0,tmp;
while(c!='\n')
{
	scanf("%d%d%c",&a1[i],&b1[i],&c);
	++i;
	n++;
}
c=' ';
i=0;
while(c!='\n')
{
	scanf("%d%d%c",&a2[i],&b2[i],&c);
	++i;
	m++;
}
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)
	{
		a[k]=a1[i]*a2[j];
		b[k]=b1[i]+b2[j];
		k++;
		t++;
	}
}
for(i=0;i<t;i++)
{
	for(j=0;j<=t-i-1;j++)
	{
		if(b[j]<b[j+1])
		{
			tmp=a[j];
			a[j]=a[j+1];
			a[j+1]=tmp;
			
			tmp=b[j];
			b[j]=b[j+1];
			b[j+1]=tmp;
		}
	}
}
j=0;
for(i=0;i<t;i++)
{
	if(b[i]==b[i+1])
	{
		x[num]=a[i]+a[i+1];
		y[num]=b[i];
		num++;
		i++;
		continue;
	}
	else
	{
		x[num]=a[i];
		y[num]=b[i];
		num++;
	}
}
for(i=0;i<num;i++)
{
	if(y[i]==y[i+1])
	{
		x1[num1]=x[i]+x[i+1];
		y1[num1]=y[i];
		num1++;
		i++;
		continue;
	}
	else
	{
		x1[num1]=x[i];
		y1[num1]=y[i];
		num1++;
	}
}
for(i=0;i<num1;i++)
{
	printf("%d %d ",x1[i],y1[i]);
}
return 0;
}

