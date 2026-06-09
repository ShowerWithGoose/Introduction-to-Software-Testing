#include<stdio.h>
#include<string.h>
int main()
{
	int sum=0,a[1000]={0},i=0,tem=-1;
	char str;
	scanf("%d",&a[0]);
	while(scanf(" %c",&str)!=EOF)
	{
		if(str=='=')
		{
			if(tem!=-1)
			{
				sum += tem;
				break;
			}
			sum += a[i];
			break;
		}
		if(str=='+'||str=='-')
		{
			if(tem!=-1)
			{sum+=tem;
			tem = -1;}
			else
			sum += a[i];
			i++;
			scanf("%d",&a[i]);
			if(str=='-')
			a[i]=-a[i];
		} 
		if(str=='*')
		{
			if(tem==-1)
			tem = a[i];
			i++;
			scanf("%d",&a[i]);
			tem *= a[i];
		} 
		if(str=='/')
		{
			if(tem==-1)
			tem = a[i];
			i++;
			scanf("%d",&a[i]);
			tem/=a[i];
		}
	}
	printf("%d",sum);
	return 0;
 } 

