#include<stdio.h>
int n,s[105];
int find(int key,int len)
{
	for(int i=0;i<len;i++)
	{
		if(s[i]==key) 
		return 1;
	}
	return 0;
}
void print()
{
	for(int i=0;i<n;i++)
	printf("%d ",s[i]);
	printf("\n");
}
void di(int len)
{
	if(len==n)
	{
		print();
		return ;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(!find(i,len))
			{
				s[len]=i;
				di(len+1);
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	di(0);
	return 0;
}

