#include<stdio.h>
#include<string.h>
struct f
{
	long long xi;
	long long zhi;
};
struct f x1[200],x2[200],x3[500];
int main()
{
	int i=0,j=0,m=0,n1,n2,len1,len2,k=0;
	long long n=0;
	char s1[100],s2[100],c;
	gets(s1);
	len1=strlen(s1);
/*	for(i=0;i<len1;i++)
	{
		if(s1[i]==' '||s1[i]=='\n')
		{
			if(((m+1)%2==0)&&m+1!=1)
			{
				x1[j].zhi=n;
				j++;
			}
			else
				x1[j].xi=n;
			m++;
			n=0;
		}
		else
			n=n*10+(s1[i]-'0');
	}*/
	for(i=0;i<len1;i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')
		{
			n=n*10+(s1[i]-'0');
		}
		else
		{
			if((m+1)%2==0)
			{
				x1[j].zhi=n;
				j++;
			}
			else
				x1[j].xi=n;
			m++;
			n=0;
		}
	}
	x1[j].zhi=n;
	n=0;
	//c=getchar();
	n1=(m+1)/2;
	//printf("%d\n",n1);
	j=m=0;
	gets(s2);
	len2=strlen(s2);
	/*for(i=0;i<len2;i++)
	{
		if(s2[i]!=' ')
			n=n*10+(s2[i]-'0');
		else
		{
			if(((m+1)%2==0)&&m+1!=1)
			{
				x2[j].zhi=n;
				j++;
			}
			else
				x2[j].xi=n;
			m++;
			n=0;
		}
	}*/
	for(i=0;i<len2;i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')
		{
			n=n*10+(s2[i]-'0');
		}
		else
		{
			if((m+1)%2==0)
			{
				x2[j].zhi=n;
				j++;
			}
			else
				x2[j].xi=n;
			m++;
			n=0;
		}
	}
	x2[j].zhi=n;
	n=0;
	//c=getchar();
	n2=(m+1)/2;
	j=m=0;
	//printf("%d\n",n2);
	//for(i=0;i<n1;i++) printf("%lld %lld ",x1[i].xi,x1[i].zhi);
	//for(i=0;i<n2;i++) printf("%lld %lld ",x2[i].xi,x2[i].zhi);
	for(i=0;i<n1;i++)
		for(j=0;j<n2;j++)
		{
			if(x1[i].xi!=0&&x2[j].xi!=0)
			{
			x3[m].xi=x1[i].xi*x2[j].xi;
			x3[m].zhi=x1[i].zhi+x2[j].zhi;
			m++;
			}
		}
	for(i=0;i<m-1;i++)
	for(j=0;j<m-i-1;j++)
	{
		if(x3[j].zhi<x3[j+1].zhi)
		{
			n=x3[j].zhi;
			x3[j].zhi=x3[j+1].zhi;
			x3[j+1].zhi=n;
			n=x3[j].xi;
			x3[j].xi=x3[j+1].xi;
			x3[j+1].xi=n;
		}
	}
	j=0;
	for(i=0;i<m;i++)
	{
		for(j=i+1;j<m;j++)
		{
			if(x3[i].zhi==x3[j].zhi&&x3[i].xi!=0&&x3[j].xi!=0)
			{
				x3[i].xi=x3[i].xi+x3[j].xi;
				x3[j].xi=0;
			}
		}
	}
	for(i=0;i<=m;i++)
		if(x3[i].xi!=0)
		printf("%lld %lld ",x3[i].xi,x3[i].zhi);
		return 0;
}

