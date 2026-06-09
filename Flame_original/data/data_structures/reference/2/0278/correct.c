#include<stdio.h>
#include<string.h>
#include<ctype.h>
int sum[10000],mid,flag[10000],i=1,mid1,k;
int ans;
char ch,chi;
int main()
{
	flag[0]=1;
	while(1)
	{
		if(k==0)
		{
			scanf("%d",&mid);
			sum[i]=mid;
		}
		scanf("%c",&ch);
		if(ch==' ')
		{
			k=1;
			continue;
		}
		if(ch=='+')
		{
			flag[i]=1;i++;
			if(k!=0)
			sum[i]=mid;
			k=0;
		}
		if(ch=='-')
		{
			flag[i]=2;i++;
			if(k!=0)
			sum[i]=mid;
			k=0;
		}
		if(ch=='*')
		{
			if(k==1)
			{
				scanf("%d",&mid);	
				sum[i]*=mid;
			}
			else
			{
				k=1;
				scanf("%d",&mid1);
				sum[i]=mid*mid1;
			}
			continue;
		}
		if(ch=='/')
		{
			if(k==1)
			{
				scanf("%d",&mid);
				sum[i]/=mid;
			}
			else
			{
				k=1;
				scanf("%d",&mid1);
				sum[i]=mid/mid1;
			}
			continue;
		}
		if(ch=='=')
		break;
	}
	for(int j=1;j<=i;j++)
	{
		if(flag[j-1]==1)
		ans+=sum[j];
		if(flag[j-1]==2)
		ans-=sum[j];
	}
	printf("%d",ans);
	return 0;
}



