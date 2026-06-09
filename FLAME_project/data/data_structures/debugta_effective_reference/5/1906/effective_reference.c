#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0;
	struct a
	{
		int mult;
		int pow;
	}a[100];
	struct c
	{
		int mult;
		int pow;
	}c[100];
	int ans[3][10010];
	
	char s;
	while(1)
	{
		scanf("%d%d",&a[i].mult,&a[i].pow);
		s=getchar();
		if(s=='\n')
		{
			break;
		}
		i++;
	}
	while(1){
		scanf("%d%d",&c[j].mult,&c[j].pow);
		s=getchar();
		if(s=='\n')
		{
			break;
		}
		j++;
	}
	int l=0;
	for(int s=0;s<=i;s++)
	{
		for(int t=0;t<=j;t++)
		{
			ans[0][l]=0;
			ans[1][l]=a[s].mult*c[t].mult;
			ans[2][l]=a[s].pow+c[t].pow;
			l++;
		}
	}
	
	for(int s=0;s<l-1;s++)
	{
		for(int t=0;t<l-s-1;t++)
		{
			if(ans[2][t]<ans[2][t+1])
			{
				int hold1,hold2;
				hold1=ans[1][t];
				ans[1][t]=ans[1][t+1];
				ans[1][t+1]=hold1;
				
				hold2=ans[2][t];
				ans[2][t]=ans[2][t+1];
				ans[2][t+1]=hold2;
			}
		}
	}
	
	for(int s=0;s<l-1;s++)
	{
		if(ans[0][s]==0)
		{
			
		for(int t=s+1;t<l;t++)
		{
			if(ans[2][s]==ans[2][t] && ans[0][t]==0)
			{
				ans[1][s]=ans[1][s]+ans[1][t];
				ans[0][t]=1;
			}
		}
		}
	} 
	
	
	for(int s=0;s<l;s++)
	{
		if(ans[0][s]==0){
			printf("%d %d ",ans[1][s],ans[2][s]);
		}
	}




	return 0;
} 

