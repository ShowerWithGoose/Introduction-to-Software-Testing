#include<stdio.h>
#include<string.h>
int sto[11]={};
int exclude(int sto[],int location,int ln)
{
	int i,sign=0;
	for(i=0;i<location;i++)
	{
		if(sto[i]==ln)
		{
			sign=1;
			break;
		}
	}
	return sign;
}
void print(int sto[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",sto[i]);
}
void haha(int n,int location)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(location==0)
		{
			sto[location]=i;
			haha(n,location+1);
		}
		else
		{
			if(exclude(sto,location,i))
				continue;
			else if(location==n-1)
			{
				sto[location]=i;
				print(sto,n);
				putchar('\n');
			}
			else
			{
				sto[location]=i;
				haha(n,location+1);
			}
		}
	}
}
int main(void)
{
	int n;
	scanf("%d",&n);
	if(n==1)
		printf("1");
	else
		haha(n,0);
}



