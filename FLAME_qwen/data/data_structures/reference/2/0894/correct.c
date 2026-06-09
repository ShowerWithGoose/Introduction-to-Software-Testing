#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char str[5000]={0};
double a[5000]={0};
double ans;
int i,j,k,n,key1,key2;
void read(int x);
void cal(int x);
int count(int x);
int main()
{
	gets(str);
	n=strlen(str);
	read(1);
	n=j;
	cal(1);
	printf("%.0lf",ans);
	return 0;
}
void read(int x)
{
	for(i=0;i<n;i++)
	{
		if(str[i]>='0'&&str[i]<='9')
		{
			a[j++]=atoi(str+i);
			i=i+count(a[j-1])-1;
			continue;
		}
		if(str[i]!=' ')
		{
			if(str[i]=='+')
			{
				a[j++]=-1.5;
			}
			if(str[i]=='-')
			{
				a[j++]=-2.5;
			}
			if(str[i]=='*')
			{
				a[j++]=-3.5;
			}
			if(str[i]=='/')
			{
				a[j++]=-4.5;
			}
		}
	}
}
int count(int x)
{
	if(x<10)return 1;
	int kkk=0;
	while(x>=pow(10,kkk))
	{
		kkk++;
	}
	return kkk;
}
void cal(int x)
{
	for(i=0;i<n;i++)
	{
		if(a[i]==-0.5)continue;
		if(a[i]==-3.5||a[i]==-4.5)
		{
			for(k=i-1;k>=0;k--)
			{
				if(a[k]!=-0.5)
				{
					key1=k;
					break;
				}
			}
			for(k=i+1;k<n;k++)
			{
				if(a[k]!=-0.5)
				{
					key2=k;
					break;
				}
			}
			if(a[i]==-3.5)
			{
				a[i]=a[key1]*a[key2];
				a[key1]=-0.5;
				a[key2]=-0.5;
			}
			if(a[i]==-4.5)
			{
				a[i]=(double)((int)a[key1]/(int)a[key2]);
				a[key1]=-0.5;
				a[key2]=-0.5;
			}
		}	
	}
	for(i=0;i<n;i++)
	{
		if(a[i]==-0.5)continue;
		if(a[i]==-1.5||a[i]==-2.5)
		{
			for(k=i-1;k>=0;k--)
			{
				if(a[k]!=-0.5)
				{
					key1=k;
					break;
				}
			}
			for(k=i+1;k<n;k++)
			{
				if(a[k]!=-0.5)
				{
					key2=k;
					break;
				}
			}
			if(a[i]==-1.5)
			{
				a[i]=a[key1]+a[key2];
				a[key1]=-0.5;
				a[key2]=-0.5;
			}
			if(a[i]==-2.5)
			{
				a[i]=a[key1]-a[key2];
				a[key1]=-0.5;
				a[key2]=-0.5;
			}
		}	
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=-0.5)ans=a[i];
	}
}



